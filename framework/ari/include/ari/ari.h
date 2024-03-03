// ari.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <memory>

#ifdef ARI_EXPORTS
#define ARI_API __declspec(dllexport)
#else // ARI_EXPORTS
#define ARI_API __declspec(dllimport)
#endif // ARI_EXPORTS


class ARI_API Ari
{
private:
	static Ari* _instance;

public:
	static Ari* GetInstance();
	void Print();
};