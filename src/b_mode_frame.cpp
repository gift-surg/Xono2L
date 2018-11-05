#include "b_mode_frame.h"


BModeFrame::BModeFrame()
	: DataBuffer()
	, width(0)
	, height(0)
{
}


BModeFrame::~BModeFrame()
{
}


size_t BModeFrame::get_width()
{
	return width;
}


size_t BModeFrame::get_height()
{
	return height;
}


void BModeFrame::set_dims(size_t width, size_t height)
{
	resize(width * height);
	this->width = width;
	this->height = height;
}


BModeFrame& BModeFrame::get_instance()
{
	static BModeFrame _b_mode_frame;
	return _b_mode_frame;
}
