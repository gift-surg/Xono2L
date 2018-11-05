#include "data_buffer.h"
#include <assert.h>
#include <memory>

DataBuffer::DataBuffer(size_t length)
	: length(length)
	, data(nullptr)
{
	if (this->length > 0)
		data = reinterpret_cast<uint8_t *>(malloc(length * sizeof(uint8_t)));
}


DataBuffer::~DataBuffer()
{
	std::lock_guard<std::mutex> guard(data_mutex);
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}


uint8_t * DataBuffer::get_data()
{
	return data;
}


size_t DataBuffer::get_length()
{
	return length;
}


void DataBuffer::resize(size_t length)
{
	std::lock_guard<std::mutex> guard(data_mutex);
	if (length > 0)
		data = reinterpret_cast<uint8_t *>(realloc(data, length * sizeof(uint8_t)));
	else if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	this->length = length;
}


void DataBuffer::set_data(const uint8_t *data)
{
	std::lock_guard<std::mutex> guard(data_mutex);
	memcpy(this->data, data, this->length);
}
