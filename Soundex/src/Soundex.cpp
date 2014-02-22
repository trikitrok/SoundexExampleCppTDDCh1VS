#include "Soundex.h"

Soundex::Soundex() {}

Soundex::~Soundex() {}

std::string Soundex::encode(const std::string& word) {
  return zeroPad(head(word) + encodedDigits(word));
}

std::string Soundex::zeroPad(const std::string& word) {
  auto zerosNeeded = 4 - word.length();

  return word + std::string(zerosNeeded, '0');
}

std::string Soundex::head(const std::string & word) {
  return word.substr(0, 1);
}

std::string Soundex::encodedDigits(const std::string& word) {
  if (word.length() > 1) {
    return "1";
  }
  return "";
}
