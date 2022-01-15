#include <iostream>
#include <cmath>
#include <math.h>
#include <tgmath.h>
#include <string.h>

int bin2dec(long long);
int dec2bin(double); //TODO
int hex2dec(char hex[]);
char* dec2hex(int); //TODO
long long bin2hex(char hex[]); //TODO 
char* hex2bin(long long); //TODO
int concat(int a, int b);

int main()
{
  int bin[10]; 
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
int dec2bin(int dec)
{
  //double numOfBits = log2(dec);
  int bin[10], i, binOut;
  for(i=0; dec>0;i++)
  {
    bin[i] = dec % 2;
    dec /= 2;
  }
  for(i=i-1 ;i>=0 ;i--)
  {
    binOut = concat(binOut, bin[i]);
  }
  return binOut;
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
  for(int i=len-1; 1>=0; i--)
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

int concat(int a, int b)
{
  // Convert both the integers to string
  std::string s1 = std::to_string(a);
  std::string s2 = std::to_string(b);

  // Concatenate both strings
  std::string s = s1 + s2;

  // Convert the concatenated string
  // to integer
  int c = stoi(s);

  return c;
}
