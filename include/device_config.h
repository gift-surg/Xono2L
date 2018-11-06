#pragma once

#include <stdint.h>

//!
//! Singleton class that keeps the relevant device
//! settings
//!
class DeviceConfig
{
protected:
	uint32_t depth;
	uint32_t freq;
public:
	~DeviceConfig();
protected:
	DeviceConfig();
public:
	//!
	//! \brief Get the singleton instance of this class
	//!
	static DeviceConfig& get_instance();

	inline uint32_t get_depth()
	{
		return depth;
	}

	inline void set_depth(uint32_t depth)
	{
		this->depth = depth;
	}

	inline uint32_t get_freq()
	{
		return freq;
	}

	inline void set_freq(uint32_t freq)
	{
		this->freq = freq;
	}
};

static DeviceConfig& device_config = DeviceConfig::get_instance();
