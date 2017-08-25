//
//  Executor.cpp
//  MoneyManager
//
//  Created by Varma, Kajal on 8/26/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#include "Executor.hpp"

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
