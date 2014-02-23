#pragma once

#ifndef Soundex_h
#define Soundex_h

#include<string>

class Soundex
{
public:
  Soundex();
  virtual ~Soundex();

  std::string encode(const std::string& word) const;

private:

  static const size_t MAX_CODE_LENGTH{4};
  const std::string NOT_A_DIGIT{"*"};

  std::string zeroPad(const std::string& word) const;
  std::string head(const std::string & word) const;
  std::string encodedDigits(const std::string& word) const;
  std::string encodedDigit(char letter) const;
  std::string tail(const std::string & word) const;
  bool isComplete(const std::string& encoded) const;
  std::string lastDigit(const std::string& encoding) const;
  std::string upperFront(const std::string& str) const;
  char lower(char letter) const;
  std::string encodeHead(const std::string& word) const;
  std::string encodeTail(const std::string& headEncoding, const std::string& word) const;
  void encodeLetter(std::string& encoding, char letter, char lastLetter) const;
  bool isVowel(char letter) const;
};

#endif // !Soundex_h

