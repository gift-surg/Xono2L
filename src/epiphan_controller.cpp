#include "epiphan_controller.h"

#include <iostream>

#ifdef USE_EPIPHAN


EpiphanController::EpiphanController()
	: frame_grabber(NULL)
	, flags(0)
	, buffer(NULL)
{
	// nop
}


EpiphanController::~EpiphanController()
{
	if (is_acquiring())
		stop_acquisition();
}


EpiphanController& EpiphanController::get_instance()
{
	static EpiphanController _controller;
	return _controller;
}


bool EpiphanController::start_acquisition(const char *device_ident)
{
    // TODO
    return false;
}


bool EpiphanController::stop_acquisition()
{
    // TODO
    return false;
}


bool EpiphanController::is_acquiring()
{
    // TODO
    return false;
}


bool EpiphanController::get_data(uint8_t *data, uint32_t *width, uint32_t *height)
{
    // TODO
    return false;
}


#endif // USE_EPIPHAN
