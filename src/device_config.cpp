#include "device_config.h"



DeviceConfig::DeviceConfig()
	: depth(0)
	, freq(0)
{
}


DeviceConfig::~DeviceConfig()
{
}


DeviceConfig& DeviceConfig::get_instance()
{
	static DeviceConfig _device_config;
	return _device_config;
}

