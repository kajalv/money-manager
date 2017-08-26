//
//  Executor.cpp
//  MoneyManager
//
//  Created by Varma, Kajal on 8/26/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#include "Executor.hpp"
#include <unistd.h>
#include <sstream>

bool balanceQuery(const std::string &balance)
{
    bool result = false;
    double amount = 0.0;
    
    std::string filePath;
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        return result;
    }
    
    std::ostringstream ss;
    ss << cwd << "/" << folderPrefix;
    filePath = ss.str();
    
    if (!balance.empty()) // this is a balance query
    {
        if (equals(balance, "Bank"))
        {
            // bank balance
            filePath = filePath + fileBalanceBank;
            std::ifstream infile(filePath);
            if (infile)
            {
                infile >> amount;
                std::cout << "Bank balance = \t\tRs. " << amount;
            }
            else
            {
                std::cout << "No saved bank amount yet.";
            }
            result = true;
        }
        else if (equals(balance, "PayTM"))
        {
            // PayTM balance
            filePath = filePath + fileBalancePayTM;
            std::ifstream infile(filePath);
            if (infile)
            {
                infile >> amount;
                std::cout << "PayTM wallet balance = \t\tRs. " << amount;
            }
            else
            {
                std::cout << "No saved PayTM amount yet.";
            }
            result = true;
        }
    }
    
    return result;
}

bool executeCommand(const std::string &transaction, const std::string &type, DateStruct &date,
                    double &amount, const std::string &category, const std::string &comment)
{
    bool result = false;
    
    std::string dateStr = std::to_string(date.day) + "/" + std::to_string(date.month) + "/" + std::to_string(date.year);
    
    if (equals(transaction, "Bank"))
    {
        if (!isBlank(date) && !isBlank(type) && amount != 0)
        {
            std::cout << "Saved bank " << type << " for Rs. " << std::setprecision(2) << std::fixed << amount << " on " << dateStr << ".\n";
            result = true;
        }
    }
    else if (equals(transaction, "PayTM"))
    {
        if (!isBlank(date) && !isBlank(type) && amount != 0)
        {
            std::cout << "Saved PayTM " << type << " for Rs. " << std::setprecision(2) << std::fixed << amount << " on " << dateStr << ".\n";
            result = true;
        }
    }
    else if (equals(transaction, "Uber"))
    {
        if (!isBlank(date) && amount != 0)
        {
            if (!isBlank(type) && (equals(type, "Personal") || equals(type, "Business")))
            {
                std::cout << "Saved Uber " << type << " for Rs. " << std::setprecision(2) << std::fixed << amount << " on " << dateStr << ".\n";
                result = true;
            }
        }
    }
    
    return result;
}
