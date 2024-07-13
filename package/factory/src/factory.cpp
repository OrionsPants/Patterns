#include "factory.h"

std::string WindowsButton::Render() const
{
  return "Windows Button";
}

std::string HTMLButton::Render() const
{
  return "HTML Button";
}

std::string Dialog::SomeOperation() const
{
  std::unique_ptr<IButton> button = this->CreateButton();

  std::string result = "Creator: Dialog code worked with: " + button->Render();
  return result;
}

std::unique_ptr<IButton> WindowsDialog::CreateButton() const
{
  return std::make_unique<WindowsButton>();
}

std::unique_ptr<IButton> WebDialog::CreateButton() const
{
  return std::make_unique<HTMLButton>();
}
