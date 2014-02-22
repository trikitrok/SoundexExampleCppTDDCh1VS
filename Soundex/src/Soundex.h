#pragma once

#ifndef Soundex_h
#define Soundex_h

#include<string>

class Soundex
{
public:
  Soundex();
  virtual ~Soundex();

  std::string encode(const std::string& word);
};

#endif // !Soundex_h

