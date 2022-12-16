#include <gtest/gtest.h>
#include <cstdlib> 
#include <ctime> 

int main(int ac, char* av[])
{

  srand((unsigned)time(0));

  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}