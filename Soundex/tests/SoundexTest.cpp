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
  ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}