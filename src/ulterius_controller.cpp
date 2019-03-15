#include "ulterius_controller.h"

#ifdef USE_ULTERIUS


static bool UlteriusController::start_acquisition(const char *device_ident)
{
}

static bool UlteriusController::stop_acquisition()
{
}

static bool UlteriusController::is_acquiring()
{
}

static bool UlteriusController::get_data(
    uint8_t *data, uint32_t *width, uint32_t *height,
    uint32_t *depth, uint32_t *freq
)
{
}

#endif // USE_ULTERIUS
