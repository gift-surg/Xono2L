#include "connection.h"
#include <exception>
#include <cctype>


Stream::Stream()
    : initialised(false)
{
    // nop
}


Stream::~Stream()
{
    initialised = false;
}


Stream& Stream::get_instance()
{
	static Stream _stream;
	return _stream;
}


void Stream::set_interface(const char *device_ident)
{
    if (initialised)
        throw std::runtime_error("Streaming already initialised");

    std::string _device_ident(device_ident);
    if (_device_ident.starts_with("COM"))
        interface = Interface::Epiphan;
    else if (std::isdigit(device_ident[0]))
        interface = Interface::Ulterius;
    else
        throw std::runtime_error("Device identifier not recognised");
    initialised = true;
}


Interface Stream::get_interface()
{
    if (not initialised)
        throw std::runtime_error("Streaming not initialised");
    return interface;
}
