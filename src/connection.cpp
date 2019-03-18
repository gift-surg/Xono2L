#include "connection.h"


Stream::Stream()
    : initialised(false)
{
    // nop
}


Stream::~Stream()
{
    // nop
}


Stream& Stream::get_instance()
{
	static Stream _stream;
	return _stream;
}


void Stream::set_interface(const char *device_ident)
{
    // TODO
}


Interface Stream::get_interface()
{
    // TODO
}
