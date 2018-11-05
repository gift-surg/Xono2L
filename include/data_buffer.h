#pragma once

#include <stdint.h>
#include <mutex>

//!
//! A very simple data buffering mechanism.
//!
class DataBuffer
{
protected:
	size_t length;
	uint8_t *data;
	std::mutex data_mutex;
public:
	DataBuffer(size_t length = 0);
	virtual ~DataBuffer();
public:
	uint8_t * get_data();
	//!
	//! \brief Copy passed data to internal buffer
	//!
	void set_data(const uint8_t *data);
	size_t get_length();
	void resize(size_t length);
};

