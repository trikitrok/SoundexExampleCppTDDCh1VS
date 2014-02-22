#include <gmock/gmock.h>
#include "../src/Soundex.h"

using namespace testing;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLettrWorld) {
  Soundex soundex;

  auto encoded = soundex.encode("A");
  
  ASSERT_THAT(encoded, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZeroesToEnsureThreeDigits) {
  Soundex soundex;

  auto encoded = soundex.encode("I");

  ASSERT_THAT(encoded, Eq("I000"));
}