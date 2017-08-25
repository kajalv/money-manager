//
//  StringUtils.hpp
//  MoneyManager
//
//  Created by Varma, Kajal on 8/26/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#ifndef StringUtils_hpp
#define StringUtils_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "../Constants/Constants.h"

bool isBlank(const std::string &arg);
bool equals(const std::string &arg1, const std::string &arg2);
bool equals(const char * arg1, const char * arg2);

bool containsCharacter(const std::string &arg, char character);
bool containsSubstring(const std::string &parentStr, const std::string &subStr);

bool getStringAsInteger(const std::string &arg, int& outParam);
bool getStringAsDouble(const std::string &arg, double& outParam);
void replaceAll(std::string &arg, const std::string &from, const std::string &to);

void tokenize(const std::string &arg, std::string tokens[], int maxSize);

void ltrim(std::string &arg);
void rtrim(std::string &arg);
void trim(std::string &arg);

void toUpper(std::string &arg);

#endif /* StringUtils_hpp */
