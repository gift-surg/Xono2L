#include "ulterius_controller.h"

#ifdef USE_ULTERIUS


static bool UlteriusController::start_acquisition(const char *device_ident)
{
    return false;
}

static bool UlteriusController::stop_acquisition()
{
    return false;
}

static bool UlteriusController::is_acquiring()
{
    return false;
}

static bool UlteriusController::get_data(
    uint8_t *data, uint32_t *width, uint32_t *height,
    uint32_t *depth, uint32_t *freq
)
{
    return false;
}

#endif // USE_ULTERIUS
