#include "senbong/senbong.h"
#include <iostream>

bool Senbong::Senbong::OnInitialize() {
  std::cout << "OnInitialize" << std::endl;
  return false;
}

void Senbong::Senbong::OnFinalize() {
  std::cout << "OnFinalize" << std::endl;
}

bool Senbong::Senbong::OnStart() {
  std::cout << "OnStart" << std::endl;
  return false;
}

void Senbong::Senbong::OnStop() { std::cout << "OnStop" << std::endl; }
