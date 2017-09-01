//
//  Executor.hpp
//  MoneyManager
//
//  Created by Varma, Kajal on 8/26/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#ifndef Executor_hpp
#define Executor_hpp

#include "CommandParser.hpp"

bool writeToFile(int transactionType, const std::string& commaSeparatedValueString);
bool balanceQuery(const std::string &balance);
bool executeCommand(const std::string &transaction, const std::string &type, DateStruct &date,
                    double &amount, const std::string &category, const std::string &comment);

#endif /* Executor_hpp */
