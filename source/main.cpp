
#pragma once

#include <Windows.h>
#include <iostream>
#include "ari/ari.h"
#include "senbong/senbong.h"

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

  static const std::string senbongPath = "../bin/senbong.dll";
  HMODULE handle = LoadLibraryA(senbongPath.c_str());

  if (nullptr == handle) {
    std::cout << "Fail to load a dll." << std::endl;
  }

  Senbong::Senbong* senbong =
      (Senbong::Senbong*)malloc(sizeof(Senbong::Senbong));
  if (NULL == senbong) {
    std::cout << "memory allocation failed" << std::endl;
    return 1;
  }

  senbong->Initialize();
  senbong->Finalize();
  senbong->Start();
  senbong->Stop();
  return 0;
}
