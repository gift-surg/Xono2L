#pragma once
#include "data_buffer.h"
//!
//! A very simple data buffering mechanism for B-mode frames, that
//! expects intensity values. This is a singleton class with the
//! aim of providing a robust global buffer.
//!
class BModeFrame :
	public DataBuffer
{
protected:
	size_t width;
	size_t height;
public:
	virtual ~BModeFrame();
protected:
	BModeFrame();
public:
	size_t get_width();
	size_t get_height();
	void set_dims(size_t width, size_t height);
	//!
	//! \brief Get the singleton instance of this class
	//!
	static BModeFrame& get_instance();
};

static BModeFrame& b_mode_frame = BModeFrame::get_instance();
