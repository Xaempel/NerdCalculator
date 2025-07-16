/*******************************************************************************
**                                                                            **
**  Copyright (C) [2025] [Xaempel]                                            **
**                                                                            **
**  This file is part of [NerdCalculator].                                    **
**  [NerdCalculator] is free software: you can redistribute it and/or         **
**  modify it under the terms of the GNU General Public License as published  **
**  by the Free Software Foundation, either version 3 of the License, or any  **
**  later version.                                                            **
**                                                                            **
**  [NerdCalculator] is distributed in the hope that it will be               **
**  useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             **
**  GNU General Public License for more details.                              **
**                                                                            **
**  You should have received a copy of the GNU General Public License along   **
**  with [NerdCalculator].  If not, see <https://www.gnu.org/licenses/>.      **
**                                                                            **
*******************************************************************************/

#include "../include/controllers/NumberCalculatorController.hpp"

#include <iostream>

enum class MenuOption {
   NumberCalculator = 1,
   Quit,
};

int main()
{
   while (true) {
      int selectedNumber {0};
      std::cout << "For start select a option\n";
      std::cout << "(1) Number calculator\n";
      std::cout << "(2) Quit\n";
      std::cin >> selectedNumber;

      NumberCalculatorController numberCalculatorController;
      switch (static_cast<MenuOption>(selectedNumber)) {
         case MenuOption::NumberCalculator:
            numberCalculatorController.startNumberCalculator();
            break;
         case MenuOption::Quit:
            return 0;
         default:
            break;
      }
   }
}