#include "Soundex.h"

#include<unordered_map>

Soundex::Soundex() {}

Soundex::~Soundex() {}

std::string Soundex::encode(const std::string& word) const {
  return zeroPad(head(word) + encodedDigits(word));
}

std::string Soundex::zeroPad(const std::string& word) const {
  auto zerosNeeded = MAX_CODE_LENGTH - word.length();

  return word + std::string(zerosNeeded, '0');
}

std::string Soundex::head(const std::string & word) const {
  return word.substr(0, 1);
}

std::string Soundex::encodedDigits(const std::string& word) const {
  if (word.length() > 1) {
    return encodedDigit(word[1]);
  }
  return "";
}

std::string Soundex::encodedDigit(char letter) const {
  const std::unordered_map<char, std::string> encodings{
    {'b', "1"},
    {'c', "2"},
    {'d', "3"}
  };

  return encodings.find(letter)->second;
}
