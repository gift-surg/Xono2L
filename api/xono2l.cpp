#include "stdafx.h"
#include "xono2l.h"
#include "ulterius_controller.h"
#include "connection.h"
#include "epiphan_controller.h"
#include <thread>

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
bool start_acquisition(const char *device_ident) noexcept
{
	try
	{
		if (is_acquiring())
			return false;

        Stream& stream = Stream::get_instance();
        stream.set_interface(device_ident);

        switch(stream.get_interface())
        {
        case Interface::Ulterius:
#ifdef USE_ULTERIUS
            return UlteriusController::start_acquisition(device_ident);
#else
            return false;
#endif
            break;
        case Interface::Epiphan:
#ifdef USE_EPIPHAN
            return EpiphanController::start_acquisition(device_ident);
#else
            return false;
#endif
            break;
        default:
            return false;
            break;
		}
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

        Stream& stream = Stream::get_instance();
        switch(stream.get_interface())
        {
        case Interface::Ulterius:
#ifdef USE_ULTERIUS
            return UlteriusController::stop_acquisition();
#else
            return false;
#endif
            break;
        case Interface::Epiphan:
#ifdef USE_EPIPHAN
            return EpiphanController::stop_acquisition();
#else
            return false;
#endif
            break;
        default:
            return false;
            break;
        }
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
        Stream& stream = Stream::get_instance();
        switch(stream.get_interface())
        {
        case Interface::Ulterius:
#ifdef USE_ULTERIUS
            return UlteriusController::is_acquiring();
#else
            return false;
#endif
            break;
        case Interface::Epiphan:
#ifdef USE_EPIPHAN
            return EpiphanController::is_acquiring();
#else
            return false;
#endif
            break;
        default:
            return false;
            break;
        }
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

        Stream& stream = Stream::get_instance();
        switch(stream.get_interface())
        {
        case Interface::Ulterius:
#ifdef USE_ULTERIUS
            return UlteriusController::get_data(data, width, height, depth, freq);
#else
            return false;
#endif
            break;
        case Interface::Epiphan:
#ifdef USE_EPIPHAN
            return EpiphanController::get_data(data, width, height);
#else
            return false;
#endif
            break;
        default:
            return false;
            break;
        }
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

_declspec (dllexport)
float get_focus_depth() noexcept
{
	try
	{
		if (!is_acquiring())
			return false;

		UlteriusSingleton& ult = UlteriusSingleton::get_instance();
		int focus_depth;
		ult.getParamValue("focus depth", focus_depth);
		return focus_depth / 1000.0;
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
