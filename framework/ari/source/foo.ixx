module;

#include <iostream>

export module helloworld;

export __declspec(dllexport) void hello() {
  std::cout << "hello,world!" << std::endl;
}