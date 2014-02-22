#include <gmock/gmock.h>

int main(int args, char** argsv) {
  ::testing::InitGoogleMock(&args, argsv);
  return RUN_ALL_TESTS();
}