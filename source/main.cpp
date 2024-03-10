
#include <iostream>
#include <queue>

#include "ari/ari.h"
#include "ari/network.h"
#include "ari/session.h"
// #include "senbong/senbong.h"
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "config_generated/pentabong.pb.h"

#include "player.h"

import bong;

import helloworld;

class Sub : public A::Test {
public:
    virtual void Print() override { std::cout << "sub" << std::endl; }
};

class Task {
public:
    Task(int id, std::function<void()> task) : _id(id), _task(task) {}

private:
    friend class Scheduler;
    friend class Worker;

    const int _id;
    const std::function<void()> _task;
};

class Worker {
public:
    Worker() {
        _th = new std::thread(&Worker::worker_main, this);
    }  // asio::thread는 인자 넘길수가 없음.

public:
    void Post(Task* task) { _taskQueue.push(task); }

private:
    static void worker_main(Worker* worker) {
        while (true) {
            while (!worker->_taskQueue.empty()) {
                auto task = worker->_taskQueue.front();
                worker->_taskQueue.pop();

                task->_task();
            }
        }
    }

private:
    std::queue<Task*> _taskQueue;  // 락이 필요하지만 테스트 코드니 일단 쓴다.
    std::thread* _th;
};

class Scheduler {
public:
    Scheduler(const int count) : _count(count) {
        for (auto i = 0; i < _count; ++i) {
            _workerList.push_back(new Worker());
        }
    }

public:
    void Post(Task* task) {
        int index = task->_id % _count;

        _workerList[index]->Post(task);
    }

private:
    const int _count;
    std::vector<Worker*> _workerList;
};

Scheduler* _Scheduler = new Scheduler(4);

void task_test() {
    std::cout << "1. " << std::this_thread::get_id() << std::endl;

    int a = 10;

    auto task1 =
        new Task(1, [a]() {  // 지역변수는 레퍼런스 캡쳐하면
                                         // 안되지만 테스트 코드니 일단 쓴다.
            std::cout << "2. " << a << ", " << std::this_thread::get_id()
                      << std::endl;

            int b = 20;
            auto task2 = new Task(2, [b]() {
                std::cout << "3. " << b << ", " << std::this_thread::get_id()
                          << std::endl;
            });

            _Scheduler->Post(task2);
        });

    _Scheduler->Post(task1);
}

Player* _Player = nullptr;

class NetworkHandler : public ari::NetworkHandler {
public:
    virtual void OnAccepted(
        std::shared_ptr<ari::Session>& session) const override final {
        std::cout << "accept: " << session->ID() << std::endl;
        _Player = new Player(session);
    }
    virtual void OnReceived() const override final {}
    virtual void OnClosed() const override final {}
};

std::shared_ptr<NetworkHandler> _NetworkHandler = std::make_shared<NetworkHandler>();

void network_test() {
    auto network = ari::Network::TCP(ari::IP::V4, 8080, _NetworkHandler);
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

    task_test();

    network_test();

    return 0;
}
