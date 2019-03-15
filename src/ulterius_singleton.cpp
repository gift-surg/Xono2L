#include "ulterius_singleton.h"

#ifdef USE_ULTERIUS

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

#endif // USE_ULTERIUS
