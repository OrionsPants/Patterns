
#include <factory.h>
#include <singleton.h>

#include <iostream>
#include <thread>

void RunFactory()
{
  std::cout << "Starting manual tests" << std::endl;

  std::unique_ptr<Dialog> diag = std::make_unique<WindowsDialog>();

  std::cout << diag->SomeOperation() << std::endl;
}

void Thread()
{
  Singleton& singleton = Singleton::GetInstance();
  std::cout << "Thread one reading count: " << singleton.accessor_count << "\n";
  singleton.accessor_count++;
  std::cout << "Thread one reading count after modification: " << singleton.accessor_count << "\n";
}

void RunSingleton()
{
  Singleton& singleton = Singleton::GetInstance();
  std::cout << "Thread main reading count: " << singleton.accessor_count << "\n";
  singleton.accessor_count = 10;
  std::cout << "Thread main reading count after modification: " << singleton.accessor_count << "\n";
  std::thread t1(Thread);
  t1.join();
  std::cout << "Thread main reading count after modification: " << singleton.accessor_count << "\n";
}

int main()
{
  return 0;
}
