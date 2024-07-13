#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <memory>

class Singleton
{
 public:
  static std::shared_ptr<Singleton> GetInstance()
  {
    return instance;
  }

 private:
  Singleton() = default;

  static std::shared_ptr<Singleton> instance;
};

#endif
