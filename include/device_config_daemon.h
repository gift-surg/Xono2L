#pragma once

#include <thread>

//!
//! This class implements a background thread that monitors
//! changes in the Ultrasonix device parameters.
//!
class DeviceConfigDaemon
{
protected:
	bool running;
	std::thread daemon_thread;
public:
	~DeviceConfigDaemon();
protected:
	DeviceConfigDaemon();
public:
	//!
	//! \brief Get the singleton instance of this class
	//!
	static DeviceConfigDaemon& get_instance();
	void start();
	void stop();
protected:
	void run();
};

static DeviceConfigDaemon& device_monitor = DeviceConfigDaemon::get_instance();
