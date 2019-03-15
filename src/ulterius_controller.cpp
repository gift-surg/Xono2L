#include "ulterius_controller.h"

#ifdef USE_ULTERIUS


bool UlteriusController::start_acquisition(const char *device_ident)
{
    UlteriusSingleton& ult = UlteriusSingleton::get_instance();
    if (!ult.connect(device_ident))
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

bool UlteriusController::stop_acquisition()
{
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

bool UlteriusController::is_acquiring()
{
    UlteriusSingleton& ult = UlteriusSingleton::get_instance();
    return ult.isConnected();
}

bool UlteriusController::get_data(
    uint8_t *data, uint32_t *width, uint32_t *height,
    uint32_t *depth, uint32_t *freq
)
{
    BModeFrame& buffer = BModeFrame::get_instance();
    memcpy(data, buffer.get_data(), buffer.get_length());
    *width = buffer.get_width();
    *height = buffer.get_height();
    DeviceConfig& config = DeviceConfig::get_instance();
    *depth = config.get_depth();
    *freq = config.get_freq();

    return true;
}

#endif // USE_ULTERIUS
