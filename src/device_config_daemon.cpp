#include "device_config_daemon.h"
#include "device_config.h"
#include "ulterius_singleton.h"
#include <assert.h>


DeviceConfigDaemon::DeviceConfigDaemon()
	: running(false)
{
}


DeviceConfigDaemon::~DeviceConfigDaemon()
{
	stop();
}


void DeviceConfigDaemon::start()
{
	if (running)
		return;

	running = true;
	daemon_thread = std::thread(&DeviceConfigDaemon::run, this);
}


void DeviceConfigDaemon::stop()
{
	running = false;
	if (daemon_thread.joinable())
		daemon_thread.join();
}


DeviceConfigDaemon& DeviceConfigDaemon::get_instance()
{
	static DeviceConfigDaemon _device_monitor;
	return _device_monitor;
}


void DeviceConfigDaemon::run()
{
	int depth = 0;
	int freq = 0;
	DeviceConfig &config = DeviceConfig::get_instance();
	UlteriusSingleton &controller = UlteriusSingleton::get_instance();
	while (running)
	{
		if (controller.getParamValue("b-depth", depth))
			config.set_depth(depth);
		if (controller.getParamValue("b-freq", freq))
			config.set_freq(freq);
		// TODO: change to an automated value based e.g. on frame rate
		std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(100));
	}
}