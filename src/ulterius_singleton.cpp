#include "ulterius_singleton.h"



UlteriusSingleton::UlteriusSingleton()
	: ulterius()
{
}


UlteriusSingleton::~UlteriusSingleton()
{
}


UlteriusSingleton& UlteriusSingleton::get_instance()
{
	static UlteriusSingleton _controller;
	return _controller;
}
