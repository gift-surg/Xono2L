#pragma once

#include <stdint.h>

#ifdef USE_EPIPHAN

#include "frmgrab.h"


class EpiphanController
{
protected:
	FrmGrabber * frame_grabber;
	V2U_UINT32 flags;
	V2U_GrabFrame2 * buffer;
	V2URect roi;

protected:
	EpiphanController();
	
public:
	~EpiphanController();

public:
	static EpiphanController& get_instance();

    bool start_acquisition(const char *device_ident);

    bool stop_acquisition();

    bool is_acquiring();

    bool get_data(uint8_t *data, uint32_t *width, uint32_t *height);
};

static EpiphanController& epiphan_controller = EpiphanController::get_instance();

#endif // USE_EPIPHAN
