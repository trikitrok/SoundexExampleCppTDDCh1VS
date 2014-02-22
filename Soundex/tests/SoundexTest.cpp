#include <gmock/gmock.h>
#include "../src/Soundex.h"

using namespace testing;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLettrWorld) {
  Soundex soundex;

  auto encoded = soundex.encode("A");
  
  ASSERT_THAT(encoded, Eq("A"));
}