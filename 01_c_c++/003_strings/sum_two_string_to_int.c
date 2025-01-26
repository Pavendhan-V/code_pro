/*
Given two non-negative integers, num1 and num2 represented as strings numAsStr1 and numAsStr2, 
return the sum of num1 and num2 as a string.
Constraints:
You cannot use any C library functions that convert string to int or int to string
The numbers represented as strings strings can hold up to 10,000 digits each
You can only convert ‘char’ type to ‘int’ and only if char is in the range ‘0’ to ‘9’
charToInt() must be used to do this conversion.
If you attempt to convert a char outside range ‘0’ to ‘9’ you will get an error.
You can only convert integers in the range 0-9 to a char type: ‘0’ to ‘9’
intToChar() must be used to do this conversion.
If you attempt to convert an integer outside the range 0-9 to a char you will get an error.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int charToInt(char digitAsChar)
{
  if (( digitAsChar < '0' ) || ( digitAsChar > '9') )
  {
    printf("ERROR: You are only allowed to convert characters from '0' to '9' to int\n");
    return -99999;
  }
  return digitAsChar-'0';
}
 
char intToChar(int digitAsInt)
{
  if ( (digitAsInt < 0) || (digitAsInt > 9) )
  {
    printf("ERROR: You are only allowed to convert integers 0-9 to char\n");
    return 'Z';
  }
  return '0' + digitAsInt;
}
 
// The output is returned in parameter strSum
// strSumLen contains the max size of strSum
// For this exercise assume that strSum is large enough to hold the output
void addStrNums(char *strSum, int strSumLen, const char *numAsStr1, const char *numAsStr2)
{
    memset(strSum, 0, strSumLen);
 
    int numAsStr1Len = strlen(numAsStr1) - 1;
    int numAsStr2Len = strlen(numAsStr2) - 1;
    int carry = 0;
    int i = numAsStr1Len, j = numAsStr2Len, k = 0;

    int num1 = 0, num2 = 0, num3 = 0;

    while (i >= 0 || j >= 0) {
        
        if (i >= 0) {
            num1 = charToInt(numAsStr1[i]);
            i--;
        }
        else {
            num1 = 0;
        }

        if (j >= 0) {
            num2 = charToInt(numAsStr2[j]);
            j--;
        }
        else {
            num2 = 0;
        }

        num3 = num1 + num2 + carry;
        carry = num3 / 10;
        strSum[k++] = intToChar(num3 % 10);
    }

    // add remaining carry if any
    if (carry) {
        strSum[k++] = intToChar(carry);
    }

    // reverse the result string
    for (int m = 0; m < k / 2; m++) {
        char temp = strSum[m];
        strSum[m] = strSum[k - m - 1];
        strSum[k - m - 1] = temp;
    }
}


void testSum(const char *numAsStr1, const char *numAsStr2, const char *expectedSum)
{
  int len1 = strlen(numAsStr1);
  int len2 = strlen(numAsStr2);
  int lenOut = len1;
  if (len2 > len1) {
    lenOut = len2;
  }
  // Add 1st 1 in case extra digit needed
  // Add 2nd 1 in for final null byte
  lenOut = lenOut + 1 + 1;
  char *actualSum = (char*) malloc(lenOut);
  memset(actualSum, 0, lenOut);
  addStrNums(actualSum, lenOut, numAsStr1, numAsStr2);
  if(!strcmp(expectedSum, actualSum))
  {
    printf("Passed: Test case: '%s' + '%s' = '%s'\n", numAsStr1, numAsStr2, expectedSum);
  }
  else
  {
    printf("FAILED Test case!\n");
    printf("  Expected: '%s' + '%s' = '%s'\n", numAsStr1, numAsStr2, expectedSum);
    printf("    Actual: '%s' + '%s' = '%s'\n", numAsStr1, numAsStr2, actualSum);
  }
  free(actualSum);
}
 
int main() {
  testSum("1", "2", "3");
  testSum("9", "3", "12");
  testSum("12", "345", "357");
  testSum("89", "34", "123");
  testSum("2333333333", "1398888888888888", "1398891222222221");
  testSum("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", "98765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210", "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111100");
  return 0;
}