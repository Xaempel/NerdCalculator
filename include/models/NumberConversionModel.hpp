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
#pragma once

#include <string>

class NumberConversionModel{
    public:
    std::string convertToBin(int number);
    std::string convertToOct(int number);
    std::string convertToHex(int number);
    std::string convertToDec(std::string number);

    bool isDecimalNumber(std::string number);
};