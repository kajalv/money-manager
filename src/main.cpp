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
      std::cout << "Run \'moneymanager test\' to test.\n";

      return 0;
    }
    
    std::string transaction;
    std::string type;
    std::string date;
    std::string amount;
    std::string category;
    std::string comment;
    
    double amountValue = 0.0;
    DateStruct dateValue;
    
    parseCommand(argc, argv, transaction, type, date, amount, category, comment, amountValue, dateValue);
    
    if (!executeCommand(transaction, type, dateValue, amountValue, category, comment))
    {
        std::cout << "Could not execute command.\n";
    }

    std::cout << RULEDLINE;
    return 0;
}
