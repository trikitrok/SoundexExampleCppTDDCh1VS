#include <gmock/gmock.h>
#include "../src/Soundex.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLettrWorld) {
  Soundex soundex;

  auto encoded = soundex.encode("A");
  
  ASSERT_THAT(encoded, testing::Eq("A"));
}