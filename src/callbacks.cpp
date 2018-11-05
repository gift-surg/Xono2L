#include "callbacks.h"
#include "b_mode_frame.h"
#include <memory>

bool new_frame_arrived(void* data, int type, int sz, bool cine, int frmnum)
{
	BModeFrame& buffer = BModeFrame::get_instance();

	if (buffer.get_length() < sz)
		return false;

	buffer.set_data(reinterpret_cast<uint8_t *>(data));
	return true;
}

bool ignore_new_frame(void* data, int type, int sz, bool cine, int frmnum)
{
	return true;
}

bool params_changed(void* paramID, int ptX, int ptY)
{
	return false;
}

bool ignore_new_params(void* paramID, int ptX, int ptY)
{
	return true;
}
