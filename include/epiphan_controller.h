#pragma once

#include <stdint.h>

#ifdef USE_EPIPHAN

#include "frmgrab.h"


class EpiphanController
{
protected:
	FrmGrabber * frame_grabber;

protected:
	EpiphanController();
	
public:
	~EpiphanController();

public:
	static EpiphanController& get_instance();

    static bool start_acquisition(const char *device_ident);

    static bool stop_acquisition();

    static bool is_acquiring();

    static bool get_data(uint8_t *data, uint32_t *width, uint32_t *height);
};

static EpiphanController& epiphan_controller = EpiphanController::get_instance();

#endif // USE_EPIPHAN
