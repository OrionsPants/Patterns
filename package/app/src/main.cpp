
#include <factory.h>

#include <iostream>

int main()
{
  std::cout << "Starting manual tests" << std::endl;

  std::unique_ptr<Dialog> diag = std::make_unique<WindowsDialog>();

  std::cout << diag->SomeOperation() << std::endl;

  return 0;
}
