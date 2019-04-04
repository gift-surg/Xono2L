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

    /**
     * Start acquisition from specified Epiphan port.
     *
     * \param device_ident serial number of requested Epiphan port, followed
     * by "-i" for capturing in intensity mode (grayscale images), or "-c"
     * for capturing in colour mode (3-byte packed RGB images). Defaults to
     * colour mode if nothing or any other suffix specified.
     * \return true if acquisition has been started, false otherwise
     * \see determine_colour which will ALWAYS return a valid colour space
     */
    bool start_acquisition(const char *device_ident);

    bool stop_acquisition();

    bool is_acquiring();

    bool get_data(uint8_t *data, uint32_t *width, uint32_t *height);

    static V2U_INT32 determine_colour(const char *device_ident);
};

static EpiphanController& epiphan_controller = EpiphanController::get_instance();

#endif // USE_EPIPHAN
