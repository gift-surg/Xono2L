#pragma once
#include "ulterius.h"

//!
//! Very thin wrapper allowing for maintaining the
//! ulterius controller as a singleton
//!
class UlteriusSingleton :
	public ulterius
{
public:
	~UlteriusSingleton();
protected:
	UlteriusSingleton();
public:
	static UlteriusSingleton& get_instance();
};

static UlteriusSingleton& controller = UlteriusSingleton::get_instance();
