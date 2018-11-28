#include "stdafx.h"
#include "xono2l.h"
#include "b_mode_frame.h"
#include "ImagingModes.h"
#include "callbacks.h"
#include "device_config.h"
#include "device_config_daemon.h"
#include "ulterius_singleton.h"
#include <thread>

uDataDesc data_desc;

BOOL APIENTRY  DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

_declspec (dllexport)
bool start_acquisition(const char *ip_address) noexcept
{
	try
	{
		if (is_acquiring())
			return false;

		UlteriusSingleton& ult = UlteriusSingleton::get_instance();
		if (!ult.connect(ip_address))
			return false;

		if (!ult.selectMode(imagingMode::BMode))
			return false;
		// seems to be necessary to allow for mode selection to complete
		std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(1000));
		if (ult.getActiveImagingMode() != imagingMode::BMode)
			return false;

		if (!ult.setSharedMemoryStatus(0))
			return false;

		if (!ult.isDataAvailable(uData::udtBPost))
			return false;
		if (!ult.getDataDescriptor(uData::udtBPost, data_desc))
			return false;
		if (!ult.setDataToAcquire(uData::udtBPost))
			return false;
		BModeFrame& buffer = BModeFrame::get_instance();
		buffer.set_dims(data_desc.w, data_desc.h);

		DeviceConfigDaemon& device_monitor = DeviceConfigDaemon::get_instance();

		// we reset these artificially to 0, to induce a "change" in the 
		// subsequent set, such that the line triggers get activated
		ult.setParamValue("trigger out", 0);
		ult.setParamValue("trigger out 2", 0);

		ult.setCallback(new_frame_arrived);
		ult.setParamCallback(params_changed);
		ult.setTimeout(100);
		// seems to be necessary to allow for above stuff to take effect
		std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(1000));

		// and now actually "set" them, activating the line triggers
		ult.setParamValue("trigger out", 2);
		ult.setParamValue("trigger out 2", 1);

		device_monitor.start();
		return true;
	}
	catch (...)
	{
		/* We use this evil design only with the intention of not causing
		 * the LabVIEW client to crash. This try-catch block should better
		 * be replaced by an appropriate exception handling mechanism
		 * interplayed between C++ and LabVIEW.
		 */
		return false;
	}
}

_declspec (dllexport)
bool stop_acquisition() noexcept
{
	try
	{
		if (!is_acquiring())
			return true;

		DeviceConfigDaemon& device_monitor = DeviceConfigDaemon::get_instance();
		device_monitor.stop();

		UlteriusSingleton& ult = UlteriusSingleton::get_instance();
		ult.setCallback(ignore_new_frame);
		ult.setParamCallback(ignore_new_params);
		ult.setTimeout(100);
		// seems to be necessary to allow for above stuff to take effect
		std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(1000));

		if (ult.isConnected())
		{
			ult.disconnect();
			// seems to be necessary to allow for mode disconnection to complete
			std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(500));
			if (ult.isConnected())
				return false;
		}

		return true;
	}
	catch (...)
	{
		/* We use this evil design only with the intention of not causing
		 * the LabVIEW client to crash. This try-catch block should better
		 * be replaced by an appropriate exception handling mechanism
		 * interplayed between C++ and LabVIEW.
		 */
		return false;
	}
}

_declspec (dllexport)
bool is_acquiring() noexcept
{
	try
	{
		UlteriusSingleton& ult = UlteriusSingleton::get_instance();
		return ult.isConnected();
	}
	catch (...)
	{
		/* We use this evil design only with the intention of not causing
		 * the LabVIEW client to crash. This try-catch block should better
		 * be replaced by an appropriate exception handling mechanism
		 * interplayed between C++ and LabVIEW.
		 */
		return false;
	}
}

_declspec (dllexport)
bool get_data(uint8_t *data, uint32_t *width, uint32_t *height,
              uint32_t *depth, uint32_t *freq) noexcept
{
	try
	{
		if (!is_acquiring())
			return false;

		BModeFrame& buffer = BModeFrame::get_instance();
		memcpy(data, buffer.get_data(), buffer.get_length());
		*width = buffer.get_width();
		*height = buffer.get_height();
		DeviceConfig& config = DeviceConfig::get_instance();
		*depth = config.get_depth();
		*freq = config.get_freq();

		return true;
	}
	catch (...)
	{
		/* We use this evil design only with the intention of not causing
		 * the LabVIEW client to crash. This try-catch block should better
		 * be replaced by an appropriate exception handling mechanism
		 * interplayed between C++ and LabVIEW.
		 */
		return false;
	}
}

_declspec (dllexport)
bool set_focus_depth(float focus_depth) noexcept
{
	try
	{
		if (!is_acquiring())
			return false;

		UlteriusSingleton& ult = UlteriusSingleton::get_instance();
		ult.setParamValue("focus depth", (uint32_t)(focus_depth * 1000));

		return true;
	}
	catch (...)
	{
		/* We use this evil design only with the intention of not causing
		 * the LabVIEW client to crash. This try-catch block should better
		 * be replaced by an appropriate exception handling mechanism
		 * interplayed between C++ and LabVIEW.
		 */
		return false;
	}
}
