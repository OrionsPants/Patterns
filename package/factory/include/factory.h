#ifndef FACTORY_H_
#define FACTORY_H_

#include <string>

class Dialog
{
 public:
  void Render();

 private:
};

class WindowsDialog
{
};

class WebDialog
{
};

class IButton
{
 public:
  virtual ~IButton() = default;
  virtual void Render() = 0;
  virtual void OnClick() = 0;
};

#endif
