module;

export module bong;

#include <Windows.h>
#include <stdio.h>

export namespace Bong {
class IBong {
 protected:
  virtual bool OnInitialize() = 0;
  virtual void OnFinalize() = 0;

  virtual bool OnStart() = 0;
  virtual void OnStop() = 0;
};

class Bong : public IBong {
 public:
  Bong() = default;
  ~Bong() = default;

 public:
  virtual bool Initialize() { return OnInitialize(); }
  virtual void Finalize() { OnFinalize(); }

  virtual bool Start() { return OnStart(); }

  virtual void Stop() { OnStop(); }
};

class Factory {
  typedef Bong* (*CreateBongFunc)();

 public:
  Factory() = default;
  ~Factory() = default;

  Bong* GetCreateBong() { return _createBong(); }

  bool Load(char const* path) {
    HMODULE handle = LoadLibraryA(path);

    if (nullptr == handle) {
      printf("Fail to load a dll.\n");
      return false;
    }

    _createBong = (CreateBongFunc)GetProcAddress(handle, "CreateBong");

    return true;
  }

 private:
  CreateBongFunc _createBong;
};
}  // namespace Bong