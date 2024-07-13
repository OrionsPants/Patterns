#include <factory.h>
#include <gtest/gtest.h>

TEST(FactoryTest, BasicTest)
{
  Factory f;

  EXPECT_EQ(f.HelloWorld(), "Hello World!");
}
