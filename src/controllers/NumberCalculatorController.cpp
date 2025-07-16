#include "../../include/controllers/NumberCalculatorController.hpp"

#include "../../include/models/NumberConversionModel.hpp"

#include <iostream>

enum class MenuOption {
   ConvertToBin = 1,
   ConvertToOct = 2,
   ConvertToHex = 3,
};

void NumberCalculatorController::startNumberCalculator()
{
   int userNumber {0};
   std::cout << "Welcome to Number calculator on the start input a number\n";
   std::cin >> userNumber;

   int selectedOption;
   std::cout << "Ok I have this so now Select your option what you wanna do with this number\n";
   std::cout << "(1) Convert to bin (2) Convert to oct (3) Convert to hex\n";
   std::cin >> selectedOption;

   NumberConversionModel numberConversionModel;
   switch (static_cast<MenuOption>(selectedOption)) {
      case MenuOption::ConvertToBin:
         std::cout << "You number in binary system is " + numberConversionModel.convertToBin(userNumber) + "\n";
         break;
      case MenuOption::ConvertToOct:
         std::cout << "You number in Oct system is " + numberConversionModel.convertToOct(userNumber) + "\n";
         break;

      case MenuOption::ConvertToHex:
         std::cout << "You number in Oct system is " + numberConversionModel.convertToHex(userNumber) + "\n";

         break;

      default:
         std::cout << "You selected a wrong option\n";
   }
}