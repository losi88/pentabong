module;

export module bong;

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
}  // namespace Bong