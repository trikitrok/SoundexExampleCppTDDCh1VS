#include "Soundex.h"

Soundex::Soundex() {}

Soundex::~Soundex() {}

std::string Soundex::encode(const std::string& word) {
  auto encoded = word.substr(0, 1);

  if (word.length() > 1) {
    encoded += "1";
  }

  return zeroPad(encoded);
}

std::string Soundex::zeroPad(const std::string& word) {
  auto zerosNeeded = 4 - word.length();

  return word + std::string(zerosNeeded, '0');
}
