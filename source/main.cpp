
#pragma once

#include "ari/ari.h"

void main(int argc, int** argv)
{
	Ari* ari = Ari::GetInstance();
	ari->Print();
}
