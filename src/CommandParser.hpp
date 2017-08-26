//
//  CommandParser.hpp
//  MoneyManager
//
//  Created by Varma, Kajal on 8/25/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#ifndef CommandParser_hpp
#define CommandParser_hpp

#include "Utilities/StringUtils.hpp"

struct DateStruct
{
    int day = 0;
    int month = 0;
    int year = 2017;
};

typedef struct DateStruct DateStruct;

void extractCommandLineFlags(std::string parsedParams[], const char * params[], int numParams);

void pruneCommand(std::string &transaction, std::string &type, std::string &date,
                  std::string &amount, std::string &category, std::string &comment, std::string &balance,
                  double &amountValue, DateStruct &dateValue);

void parseCommand(int numParams, const char * params[],
                  std::string &transaction, std::string &type, std::string &date,
                  std::string &amount, std::string &category, std::string &comment, std::string &balance,
                  double &amountValue, DateStruct &dateValue);

bool isBlank(DateStruct date);

#endif /* CommandParser_hpp */
