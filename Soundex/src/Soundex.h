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

  std::string zeroPad(const std::string& word) const;
  std::string head(const std::string & word) const;
  std::string encodedDigits(const std::string& word) const;
  std::string encodedDigit(char letter) const;
  std::string tail(const std::string & word) const;
};

#endif // !Soundex_h

