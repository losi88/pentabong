import bong;

namespace Senbong {
class Senbong : public Bong::Bong {
 public:
  Senbong() = default;
  ~Senbong() = default;

protected:
  virtual bool OnInitialize() override;
  virtual void OnFinalize() override;

  virtual bool OnStart() override;

  virtual void OnStop() override;
};
}  // namespace Senbong