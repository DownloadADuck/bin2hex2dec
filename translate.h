#include <string>

#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__

class translate {
  public:
    int bin2dec(long long);
    long long dec2bin(int);
    int hex2dec(char hex[]);
    std::string dec2hex(int dec);
    std::string bin2hex(long long bin);
    long long hex2bin(char hex[]); 
};


#endif
