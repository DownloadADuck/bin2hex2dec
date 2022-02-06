#include <string> 
#include <iostream>
#include <cmath>
#include <algorithm>

#include <math.h>
#include <tgmath.h>
#include <string.h>

#include "translate.h"


int main()
{
  translate myObject;

  long long testBinary1 = 1001;
  long long testBinary2 = 101011101010101101;
  int testDec1 = 38674;
  char testHex1[]= "0FA16";
  char testHex2[]= "2BAAD";
  std::string resultDec2Hex = myObject.dec2hex(testDec1);

  std::cout << "The decimal value of: " << testBinary1 << " is: " << myObject.bin2dec(testBinary1) << std::endl;
  std::cout << "The binary value of: " << testDec1 << " is: " << myObject.dec2bin(testDec1) << std::endl;
  std::cout << "The decimal value of: " << testHex1 << " is: " << myObject.hex2dec(testHex1) << std::endl;
  std::cout << "The hexadecimal value of: " << testDec1 << " is: " << resultDec2Hex << std::endl;
  std::cout << "The hexadecimal value of: " << testBinary2 << " is: " << myObject.bin2hex(testBinary2) << std::endl;
  std::cout << "The binary value of: " << testHex2 << " is: " << myObject.hex2bin(testHex2) << std::endl;
}

