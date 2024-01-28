
#pragma once

#include <iostream>
#include "ari/ari.h"
// #include "senbong/senbong.h"

import bong;

import helloworld;

class Sub : public A::Test {
 public:
  virtual void Print() override { std::cout << "sub" << std::endl; }
};

int main(int argc, int** argv) {
  Ari* ari = Ari::GetInstance();
  ari->Print();

  hello();
  A::Test* test = new Sub();
  test->Print();

  static const std::string senbongPath = "../bin/senbong_d.dll";

  Bong::Factory factory;

  bool ret = factory.Load(senbongPath.c_str());
  if (false == ret) {
    return 0;
  }
  
  Bong::Bong* senbong = factory.CreateBong();
  if (nullptr == senbong) {
    return 1;
  }

  senbong->Initialize();
  senbong->Finalize();
  senbong->Start();
  senbong->Stop();
  return 0;
}
