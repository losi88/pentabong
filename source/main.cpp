
#pragma once

#include <Windows.h>
#include <iostream>
#include "ari/ari.h"
//#include "senbong/senbong.h"

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
  HMODULE handle = LoadLibraryA(senbongPath.c_str());

  if (nullptr == handle) {
    std::cout << "Fail to load a dll." << std::endl;
  }


  typedef Bong::Bong* (*CreateBongFunc)();
  CreateBongFunc createBong = (CreateBongFunc)GetProcAddress(handle, "CreateBong");

  Bong::Bong* bong = createBong();

  bong->Initialize();
  bong->Finalize();
  bong->Start();
  bong->Stop();
  return 0;
}
