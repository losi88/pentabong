// ari.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

#ifdef _WINDLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif


class Ari
{
private:
	Ari* _instance;

public:
	Ari* GetInstance();
	void Print();
};