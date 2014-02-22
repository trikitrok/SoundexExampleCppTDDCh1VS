#include <gmock/gmock.h>
#include "../src/Soundex.h"

using namespace testing;

class SoundexEncoding : public Test 
{
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLettrWorld) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroesToEnsureThreeDigits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithApropriateDigits) {
  ASSERT_THAT(soundex.encode("Bx"), Eq("B200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
  ASSERT_THAT(soundex.encode("B#"), Eq("B000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
  ASSERT_THAT(soundex.encode("Bcdl"), Eq("B234"));
}