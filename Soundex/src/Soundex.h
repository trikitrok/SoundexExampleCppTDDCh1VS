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
  std::string zeroPad(const std::string& word) const;
  std::string head(const std::string & word) const;
  std::string encodedDigits(const std::string& word) const;
};

#endif // !Soundex_h

