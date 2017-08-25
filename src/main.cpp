//
//  main.cpp
//  Money Manager
//
//  Created by Varma, Kajal on 8/25/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#include <iostream>
#include "Constants/StringConstants.h"

int main(int argc, const char * argv[])
{
    std::cout << RULEDLINE;
    std::cout << "\t\t\tMONEY MANAGER\n";

    if (argc < 2)
    {
      // help content
      std::cout << "Run moneymanager test to test.\n";
    }
    else
    {
      std::string firstArg = argv[1];
      if (firstArg == "test")
        std::cout << "Application works!";
      else
        std::cout << "Running.... " << firstArg << "\n";
    }

    std::cout << RULEDLINE;
    return 0;
}
