#include "cormentalgo_test.h"
#include "secondchal_test.h"
#include "twosum_test.h"
#include "weissbasic_test.h"
#include "red_black_test.h"
#include <gtest/gtest.h>
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}