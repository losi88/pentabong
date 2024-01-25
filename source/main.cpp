
#pragma once

#include "ari/ari.h"

import helloworld;

int main(int argc, int** argv)
{
	Ari* ari = Ari::GetInstance();
	ari->Print();
   
	hello();
	
	return 0;
}
