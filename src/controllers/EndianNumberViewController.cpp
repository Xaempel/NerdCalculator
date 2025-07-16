#include "../../include/controllers/EndianNumberViewController.hpp"

#include "../../include/models/NumberConversionModel.hpp"

#include <algorithm>
#include <iostream>

enum class MenuOption {
   LittleEndian = 1,
   BigEndian,
   Quit,
};

void EndianNumberViewController::runEndianView(std::string number)
{
   NumberConversionModel numberConversionModel;
   if (numberConversionModel.isDecimalNumber(number) == false) {
      numberConversionModel.convertToDec(number);
   }
   std::string binaryNumber {numberConversionModel.convertToBin(std::stoi(number))};
   binaryNumber.erase(binaryNumber.size() - 3, 3);

   int padding = 8 - (binaryNumber.size() % 8);
   if(padding != 8){
    binaryNumber = std::string(padding,'0') + binaryNumber;
   }

   int userSelectedOption {0};
   std::cout << "Warning This function support only Bin numbers so I'll convert Your number and show It like a binary form\n";

   std::cout << "Your DEC number is " + number + "\n";
   std::cout << "Which option I have to use?\n";
   std::cout << "(1) Little Endian Most significant byte stored first. Standard network order.\n";
   std::cout << "(2) Big Endian Least significant byte stored first. Common on Intel processors.\n";
   std::cout << "(3) Quit\n";
   std::cin >> userSelectedOption;

   switch (static_cast<MenuOption>(userSelectedOption)) {
      case MenuOption::LittleEndian:
         if (numberIsLittleEndian == false) {
            numberIsLittleEndian = true;
            std::cout << "You number in Little Endian is " + binaryNumber + "\n";
         }
         else{
            std::cout << "You number is in Little Endian" + binaryNumber + "\n";
         }
         break;
      case MenuOption::BigEndian:
         if (numberIsLittleEndian == true) {
            std::reverse(binaryNumber.begin(), binaryNumber.end());
            numberIsLittleEndian = false;
            std::cout << "You number in Big Endian is " + binaryNumber + "\n";
         }
         break;
      case MenuOption::Quit:
         return;
   }
}