module;

#include <iostream>

export module helloworld;

export __declspec(dllexport) void hello() {
  std::cout << "hello,world!" << std::endl;
}

export namespace A {
class Test {
 public:
  virtual void Print() { std::cout << "test" << std::endl; }
};
}  // namespace A