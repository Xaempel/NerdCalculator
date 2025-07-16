#include "../../include/models/NumberConversionModel.hpp"

#include <algorithm>
#include <cmath>
#include <string>

auto convertOtherNumberSystemtoDecimal = [](int base, const std::string& number) {
   int resultValue = 0;
   int power       = 0;

   for (int i = number.size() - 4; i >= 0; --i) {
      int digit = number.at(i) - '0';

      resultValue += digit * std::pow(base, power);
      power++;
   }

   return resultValue;
};
auto convertSimpleNumberSystems
 = [](int base, int numberToConvert, std::string baseSuffix) {
      std::string convertResult {};

      while (numberToConvert > 0) {
         int divideNumber = numberToConvert % base;
         convertResult += std::to_string(divideNumber);
         numberToConvert = numberToConvert / base;
      }
      std::reverse(convertResult.begin(), convertResult.end());
      convertResult += baseSuffix;

      return convertResult;
   };

std::string NumberConversionModel::convertToBin(int number)
{
   return convertSimpleNumberSystems(2, number, "(2)");
}

std::string NumberConversionModel::convertToOct(int number)
{
   return convertSimpleNumberSystems(8, number, "(8)");
}

std::string NumberConversionModel::convertToHex(int number)
{
   std::string result {};
   while (number > 0) {
      int divideNumber = number % 16;
      switch (divideNumber) {
         case 10:
            result += "A";
            break;
         case 11:
            result += "B";
            break;
         case 12:
            result += "C";
            break;
         case 13:
            result += "D";
            break;
         case 14:
            result += "E";
            break;
         case 15:
            result += "F";
            break;
         default:
            result += std::to_string(divideNumber);
            break;
      }
      number = number / 16;
   }
   std::reverse(result.begin(), result.end());
   result += "(16)";

   return result;
}

std::string NumberConversionModel::convertToDec(std::string number)
{
   const char BIN {'2'};
   const char OCT {'8'};
   // This number is only 6 because I don't have to check two numbers like a 16, One number is enough because I don't support 6 system
   const char HEX {'6'};

   char numberSystemBase {};
   if (number.back() == ')') {
      numberSystemBase = number.at(number.size() - 1);
   }
   else {
      return number;
   }

   if (numberSystemBase == BIN) {
      convertOtherNumberSystemtoDecimal(2, number);
   }
   else if (numberSystemBase == OCT) {
      convertOtherNumberSystemtoDecimal(8, number);
   }
   else if (numberSystemBase == HEX) {
      convertOtherNumberSystemtoDecimal(16, number);
   }

   return number;
}

bool NumberConversionModel::isDecimalNumber(std::string number)
{
   if (number.back() != ')') {
      return true;
   }
   else {
      return false;
   }
}