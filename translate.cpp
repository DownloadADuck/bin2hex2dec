#include "translate.h"

#include <iostream>
#include <string> 
#include <cmath>
#include <algorithm>

#include <math.h>
#include <tgmath.h>
#include <string.h>





/** bin2dec
 * translates a binary to a decimal number
 * 
 * uses rem as a "boolean" to know if the
 * current power of two is or not in the 
 * binary
 *
 * input:
 * long long bin = 110101011010;
 */
int translate::bin2dec(long long bin)
{
  int dec = 0, i = 0, rem;
  while(bin!=0)
  {
    rem = bin % 10;
    bin /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
  return dec;
}

/** dec2bin
 * converts a decimal into a binary
 *
 * store remainder by dividing 2 with %
 *
 * divide number by 2
 * 
 * repeat the second step until the number 
 * is greater than zero
 */
long long translate::dec2bin(int dec)
{
    std::string bin;
    while(dec!=0) 
    {
      bin=(dec%2==0 ?"0":"1")+bin; 
      dec/=2;
    }
    std::string::size_type size = 0;
    long long binLong = std::stoll (bin, &size, 10);
    return binLong;
}



/** hex2dec
 * traslates hexadecimal number into 
 * a decimal number
 *
 * input 
 * char hex[]="fbc085";
 *
 * uses ASCII codes to translate A-->F
 * into their numeral equivalent
 *
 * uses base to keep track of the power 
 * of 16
 */
int translate::hex2dec(char hex[])
{
  int len = strlen(hex);
  int base = 1;
  int dec = 0;
  for(int i=len-1; i>=0; i--)
  {
    if(hex[i]>='0' && hex[i]<='9')
    {
      dec += (hex[i] - 48) * base;
      base = base * 16; 
    }
    else if(hex[i]>='A' && hex[i]<='F')
    {
      dec += (hex[i] - 55) * base;
      base = base * 16;
    }
  }
  return dec;
}


std::string translate::dec2hex(int dec)
{
  int rem, product = 1;
  std::string hex = "";
  while (dec != 0) {
    rem = dec % 16;
    char ch;
    if (rem >= 10)
      ch = rem + 55;
    else
      ch = rem + 48;
    hex += ch;

    dec = dec / 16;
    product *= 10;
  }
  std::reverse(hex.begin(), hex.end());
  return hex;
}


std::string translate::bin2hex(long long bin)
{
  int intermediate = bin2dec(bin);
  std::string hex = dec2hex(intermediate);
  return hex;
}


long long translate::hex2bin(char hex[])
{
  int intermediate = hex2dec(hex);
  long long bin = dec2bin(intermediate);
  return bin;
}
