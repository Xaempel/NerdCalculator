#include "../../include/controllers/BitShiftController.hpp"

#include "../../include/models/NumberConversionModel.hpp"

#include <iostream>
#include <string>

enum class BitsShiftType {
   LeftSided = 1,
   RightSided,
};

void BitShiftController::runBitShiftOperations(std::string number)
{
   NumberConversionModel numberConversionModel;
   number = numberConversionModel.convertToDec(number);
   std::string convertedNumber {numberConversionModel.convertToBin(std::stoi(number))};
   convertedNumber.erase(convertedNumber.size() - 3, 3);

   std::cout << "Your number in BIN is " + convertedNumber + "\n";

   int bitsShiftingTimes {0};
   std::cout << "How much times I have to shift bits\n";
   std::cin >> bitsShiftingTimes;

   int selectedBitsShiftMode {0};

   std::cout << "Which type of bit shift should I choose?\n";
   std::cout << "(1) Left Sided\n";
   std::cout << "(2) Right Sided\n";
   std::cin >> selectedBitsShiftMode;

   int numberToShift {std::stoi(convertedNumber, nullptr, 2)};
   switch (static_cast<BitsShiftType>(selectedBitsShiftMode)) {
      case BitsShiftType::LeftSided:
         numberToShift   = numberToShift << bitsShiftingTimes;
         convertedNumber = numberConversionModel.convertToBin(numberToShift);
         std::cout << "You number shifted this is result " << convertedNumber << "\n";
         break;
      case BitsShiftType::RightSided:
         numberToShift   = numberToShift >> bitsShiftingTimes;
         convertedNumber = numberConversionModel.convertToBin(numberToShift);
         std::cout << "You number shifted this is result" << convertedNumber << "\n";
         break;
      default:
         break;
   }
}