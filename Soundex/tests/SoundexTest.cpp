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

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
  ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
  ASSERT_THAT(soundex.encode("PaEiOuYhwcdlb"), Eq("P234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {

  ASSERT_THAT(soundex.encode("Ab"), soundex.encode("Af"));
  ASSERT_THAT(soundex.encode("Ac"), soundex.encode("Ag"));
  ASSERT_THAT(soundex.encode("Ad"), soundex.encode("At"));

  ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
  ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresCasesWhenEncodingConsonants) {
  ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}