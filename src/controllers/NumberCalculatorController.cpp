#include "../../include/controllers/NumberCalculatorController.hpp"

#include "../../include/controllers/EndianNumberViewController.hpp"
#include "../../include/models/NumberConversionModel.hpp"

#include <iostream>
#include <string>

enum class MenuOption {
   ConvertToBin = 1,
   ConvertToOct,
   ConvertToHex,
   ConvertToDec,
   EnterAgainNumber,
   ShowNumberasEndian,
   Quit,
};

auto convertStandardMenu = [](std::string systemBase, std::string userConvertedNumber, std::string& userCurrentNumber) {
   int userNumberDecision {};
   std::cout << "You number in " + systemBase + " system is " + userConvertedNumber + "\n";
   std::cout << "Do you wanna save this number (1) Yes (2) No\n";
   std::cin >> userNumberDecision;
   if (userNumberDecision == '1') {
      userConvertedNumber = userConvertedNumber;
   }
};

void NumberCalculatorController::startNumberCalculator()
{
   std::string userNumber {0};
   std::cout << "Welcome to Number calculator on the start input a number\n";
   std::cin >> userNumber;

   EndianNumberViewController endianNumberViewController;
   while (true) {
      int selectedOption;
      std::cout << "Ok I have this so now Select your option what you wanna do with this number\n";
      std::cout << "(1) Convert to bin (2) Convert to oct (3) Convert to hex (4) Convert to dec\n";
      std::cout << "(5) Enter again number (6) Show Number as Endian\n";
      std::cout << "(7) Quit\n";
      std::cin >> selectedOption;

      NumberConversionModel numberConversionModel;
      int userConvertedNumber {0};
      if (numberConversionModel.isDecimalNumber(userNumber) == true) {
         userConvertedNumber = std::stoi(userNumber);
      }
      else {
         numberConversionModel.convertToDec(userNumber);
         userConvertedNumber = std::stoi(userNumber);
      }

      switch (static_cast<MenuOption>(selectedOption)) {
         case MenuOption::ConvertToBin:
            convertStandardMenu("BIN", numberConversionModel.convertToBin(userConvertedNumber), userNumber);
            break;
         case MenuOption::ConvertToOct:
            convertStandardMenu("OCT", numberConversionModel.convertToOct(userConvertedNumber), userNumber);
            break;

         case MenuOption::ConvertToHex:
            convertStandardMenu("HEX", numberConversionModel.convertToHex(userConvertedNumber), userNumber);

            break;

         case MenuOption::ConvertToDec:
            convertStandardMenu("DEC", numberConversionModel.convertToDec(userNumber), userNumber);
            break;

         case MenuOption::EnterAgainNumber:
            std::cout << "Enter Again your number\n";
            std::cin >> userNumber;
            break;

         case MenuOption::ShowNumberasEndian:
            endianNumberViewController.runEndianView(userNumber);
            break;

         case MenuOption::Quit:
            return;

         default:
            std::cout << "You selected a wrong option\n";
            break;
      }
   }
}