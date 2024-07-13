#ifndef FACTORY_H_
#define FACTORY_H_

#include <memory>
#include <string>
// Example Product
class IButton
{
 public:
  virtual ~IButton() = default;
  virtual std::string Render() const = 0;
};
// Specific Product 1
class WindowsButton : public IButton
{
 public:
  std::string Render() const override;
};
// Specific Product 2
class HTMLButton : public IButton
{
 public:
  std::string Render() const override;
};
// Example Creator
class Dialog
{
 public:
  virtual ~Dialog() = default;
  virtual std::unique_ptr<IButton> CreateButton() const = 0;
  std::string SomeOperation() const;
};
// Specific Creator 1
class WindowsDialog : public Dialog
{
 public:
  std::unique_ptr<IButton> CreateButton() const override;
};
// Specific Creator 2
class WebDialog : public Dialog
{
 public:
  std::unique_ptr<IButton> CreateButton() const override;
};

#endif
