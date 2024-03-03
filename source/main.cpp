
#include <iostream>

#include "ari/ari.h"
#include "ari/network.h"
// #include "senbong/senbong.h"
#include "asio/thread.hpp"
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "config_generated/pentabong.pb.h"

import bong;

import helloworld;

class Sub : public A::Test {
public:
    virtual void Print() override { std::cout << "sub" << std::endl; }
};

void thread_test() { std::cout << "thread test" << std::endl; }

void network_test()
{
    auto network = ari::Network::TCP(ari::IP::V4, 8080, 4);
    network->Start();
}

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

    pentabong::Hello hello;
    hello.set_text("hello,world");
    std::cout << hello.text() << std::endl;

    asio::thread t(thread_test);
    t.join();

    network_test();

    return 0;
}
