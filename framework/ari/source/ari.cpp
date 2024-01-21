// ari.cpp : Defines the entry point for the application.
//

#include "ari/ari.h"

Ari* Ari::_instance = nullptr;

Ari* Ari::GetInstance()
{
	if (nullptr == _instance)
	{
		_instance = new Ari();
		return _instance;
	}

	return _instance;
}

void Ari::Print()
{
	std::cout << "MareMareGame wil make MareMareWorld!!!" << std::endl;
}
