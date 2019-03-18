#pragma once

#include <stdint.h>

#ifdef USE_EPIPHAN

class EpiphanController
{
public:
    static bool start_acquisition(const char *device_ident);

    static bool stop_acquisition();

    static bool is_acquiring();

    static bool get_data(uint8_t *data, uint32_t *width, uint32_t *height);
};

#endif // USE_EPIPHAN
