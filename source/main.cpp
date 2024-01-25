
#pragma once

#include "ari/ari.h"

import helloworld;

class Sub : public A::Test
{
 public:
  virtual void Print() override { std::cout << "sub" << std::endl; }
};

int main(int argc, int** argv)
{
	Ari* ari = Ari::GetInstance();
	ari->Print();
   
	hello();
    A::Test* test = new Sub();
    test->Print();
	
	return 0;
}
