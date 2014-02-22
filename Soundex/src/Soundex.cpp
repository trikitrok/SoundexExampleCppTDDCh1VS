#include "Soundex.h"

#include<unordered_map>
#include <cctype>

Soundex::Soundex() {}

Soundex::~Soundex() {}

std::string Soundex::encode(const std::string& word) const {
  return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
}

std::string Soundex::zeroPad(const std::string& word) const {
  auto zerosNeeded = MAX_CODE_LENGTH - word.length();
  return word + std::string(zerosNeeded, '0');
}

std::string Soundex::head(const std::string & word) const {
  return word.substr(0, 1);
}

std::string Soundex::tail(const std::string & word) const {
  return word.substr(1);
}

std::string Soundex::encodedDigits(const std::string& word) const {
  std::string encoding = "";
  for (auto letter : word) {

    letter = std::tolower(letter);

    if (isComplete(encoding))
      break;

    auto digit = encodedDigit(letter);

    if (digit != NOT_A_DIGIT && digit != lastDigit(encoding))
      encoding += encodedDigit(letter);
  }
  return encoding;
}

std::string Soundex::encodedDigit(char letter) const {
  const std::unordered_map<char, std::string> encodings{
    {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
    {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
    {'s', "2"}, {'x', "2"}, {'z', "2"},
    {'d', "3"}, {'t', "3"},
    {'l', "4"},
    {'m', "5"}, {'n', "5"},
    {'r', "6"}
  };

  auto it = encodings.find(letter);

  if (it == encodings.end())
    return NOT_A_DIGIT;
  return it->second;
}

bool Soundex::isComplete(const std::string& encoding) const {
  return encoding.length() == MAX_CODE_LENGTH - 1;
}

std::string Soundex::lastDigit(const std::string& encoding) const {
  if (encoding.empty())
    return NOT_A_DIGIT;
  return std::string(1, encoding.back());
}

std::string Soundex::upperFront(const std::string& str) const {
  return std::string(1,
    std::toupper(static_cast<unsigned char>(str.front())));
}