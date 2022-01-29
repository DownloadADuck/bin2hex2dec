#include <sstream>
#include <iostream>
#include <cmath>

#include <math.h>
#include <tgmath.h>
#include <string.h>

int bin2dec(long long);
long long dec2bin(int);
int hex2dec(char hex[]);
char* dec2hex(int); //TODO
long long bin2hex(char hex[]); //TODO 
char* hex2bin(long long); //TODO

int main()
{
  long long testBinary1 = 1001; // d7
  int testDec1 = 34;
  char testHex1[]= "0FA16"; //64022
  int binResult = hex2dec(testHex1);
  std::cout << "The decimal value of: " << testBinary1 << " is: " << bin2dec(testBinary1) << std::endl;
  std::cout << "The binary value of: " << testDec1 << " is: " << dec2bin(testDec1) << std::endl;
  std::cout << "The decimal value of: " << testHex1 << " is: " << binResult << std::endl;
  std::cin.get();
}

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
int bin2dec(long long bin)
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
long long dec2bin(int dec)
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
int hex2dec(char hex[])
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


