//
//  main.cpp
//  Money Manager
//
//  Created by Varma, Kajal on 8/25/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#include "Executor.hpp"

int main(int argc, const char * argv[])
{
    std::cout << RULEDLINE;
    std::cout << "\t\t\tMONEY MANAGER\n\n";

    if (argc < 2)
    {
        // help content
        std::cout << "Usage\nmoneymanager [--options]\n\n";
        std::cout << "--transaction, -tr \t\t Transaction type: Bank, PayTM, or Uber.\n";
        std::cout << "--type, -ty \t\t\t For bank and PayTM: Credit or Debit. For Uber: Personal or Business.\n";
        std::cout << "--date, -d \t\t\t\t Date in format such as 15/6/2017 or 15 Jun.\n";
        std::cout << "--amount, -a \t\t\t Cash value.\n";
        std::cout << "--category, -a \t\t\t Any category you want to categorize the transaction as, such as Travel or Shopping.\n";
        std::cout << "--comment, -a \t\t\t Additional comments.\n";

        std::cout << RULEDLINE;
        return 0;
    }
    
    std::string transaction;
    std::string type;
    std::string date;
    std::string amount;
    std::string category;
    std::string comment;
    std::string balance;
    
    double amountValue = 0.0;
    DateStruct dateValue;
    
    parseCommand(argc, argv, transaction, type, date, amount, category, comment, balance, amountValue, dateValue);
    
    if (balanceQuery(balance))
    {
        ;
    }
    else if (!executeCommand(transaction, type, dateValue, amountValue, category, comment))
    {
        std::cout << "Could not execute command.\n";
    }

    std::cout << RULEDLINE;
    return 0;
}
