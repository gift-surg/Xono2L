#include "connection.h"
#include <stdexcept>
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


void Stream::set_interface(const char *device_url, char *device_ident)
{
    if (initialised)
        throw std::runtime_error("Streaming already initialised");

    std::string _device_url(device_url);
	if (_device_url.compare(0, 2, "u:") == 0)
		interf = Interface::Ulterius;
    else if (_device_url.compare(0, 2, "e:") == 0)
		interf = Interface::Epiphan;
	else
		throw std::runtime_error("Unsupported interface");

	strcpy(device_ident, _device_url.substr(2).c_str());
    initialised = true;
}


Interface Stream::get_interface()
{
    if (!initialised)
        throw std::runtime_error("Streaming not initialised");
    return interf;
}
