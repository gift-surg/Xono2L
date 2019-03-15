#pragma once

#ifdef USE_ULTERIUS

#include "b_mode_frame.h"
#include "ImagingModes.h"
#include "callbacks.h"
#include "device_config.h"
#include "device_config_daemon.h"
#include "ulterius_singleton.h"


class UlteriusController
{
public:
    static bool start_acquisition(const char *device_ident);

    static bool stop_acquisition();

    static bool is_acquiring();

    static bool get_data(uint8_t *data, uint32_t *width, uint32_t *height,
                         uint32_t *depth, uint32_t *freq);
};

#endif // USE_ULTERIUS
