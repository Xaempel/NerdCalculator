#include "../../include/models/NumberConversionModel.hpp"

#include <algorithm>
#include <string>

auto convertSimpleNumberSystems = [](int base, int numberToConvert, std::string baseSuffix) {
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