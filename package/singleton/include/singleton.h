#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <memory>

class Singleton
{
 public:
  Singleton(Singleton& other) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton& GetInstance()
  {
    static Singleton instance;
    return instance;
  }

  size_t accessor_count = 0;

 private:
  Singleton()
  {
  }
};

#endif
