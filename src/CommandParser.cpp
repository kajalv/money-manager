//
//  CommandParser.cpp
//  MoneyManager
//
//  Created by Varma, Kajal on 8/25/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#include "CommandParser.hpp"

void parseCommand(int numParams, const char * params[],
                  std::string &transaction, std::string &type, std::string &date,
                  std::string &amount, std::string &category, std::string &comment,
                  double &amountValue, DateStruct &dateValue)
{
    std::string parsedParams[MAX_PARAMS];
    
    // parse command line flags
    extractCommandLineFlags(parsedParams, params, numParams);
    
    // prune the command
    transaction = parsedParams[ParamIndex::Transaction];
    type = parsedParams[ParamIndex::Type];
    date = parsedParams[ParamIndex::Date];
    amount = parsedParams[ParamIndex::Amount];
    category = parsedParams[ParamIndex::Category];
    comment = parsedParams[ParamIndex::Comment];
    
    pruneCommand(transaction, type, date, amount, category, comment, amountValue, dateValue);
}

void extractCommandLineFlags(std::string parsedParams[], const char * params[], int numParams)
{
    std::string currentParam;
    
    for (int i = 1; i < numParams; i++)
    {
        if (i != numParams - 1) // command line flag must be followed by the corresponding value, otherwise it is discarded
        {
            currentParam = params[i];
            
            if (equals(currentParam, OPT_PREFIX + OPT_TRANSACTION))
            {
                parsedParams[ParamIndex::Transaction] = params[i + 1];
            }
            else if (equals(currentParam, OPT_PREFIX + OPT_TYPE))
            {
                parsedParams[ParamIndex::Type] = params[i + 1];
            }
            else if (equals(currentParam, OPT_PREFIX + OPT_DATE))
            {
                parsedParams[ParamIndex::Date] = params[i + 1];
            }
            else if (equals(currentParam, OPT_PREFIX + OPT_AMT))
            {
                parsedParams[ParamIndex::Amount] = params[i + 1];
            }
            else if (equals(currentParam, OPT_PREFIX + OPT_CATEGORY))
            {
                parsedParams[ParamIndex::Category] = params[i + 1];
            }
            else if (equals(currentParam, OPT_PREFIX + OPT_COMMENT))
            {
                parsedParams[ParamIndex::Comment] = params[i + 1];
            }
        }
    }
}

void pruneCommand(std::string &transaction, std::string &type, std::string &date,
                  std::string &amount, std::string &category, std::string &comment,
                  double &amountValue, DateStruct &dateValue)
{
    // transaction
    if (!equals(transaction, "Bank") && !equals(transaction, "PayTM") && !equals(transaction, "Uber"))
    {
        transaction = "";
    }
    
    // type
    if (equals(transaction, "Uber"))
    {
        if (!equals(type, "Personal") && !equals(type, "Business"))
        {
            type = "Personal"; // default for Uber
        }
    }
    else if (!equals(type, "Debit") && !equals(type, "Credit"))
    {
        type = "";
    }
    
    // date
    std::string dateTokens[3];
    tokenize(date, dateTokens, 3);
    
    int val = 0;
    if (getStringAsInteger(dateTokens[0], val) && val >= 1 && val <= 31)
    {
        dateValue.day = val;
    }
    
    std::string monStr = dateTokens[1];
    toUpper(monStr);
    val = 0;
    if (getStringAsInteger(monStr, val) && val >= 1 && val <= 12)
    {
        dateValue.month = val;
    }
    else if (containsSubstring(monStr, "JAN"))
    {
        dateValue.month = 1;
    }
    else if (containsSubstring(monStr, "FEB"))
    {
        dateValue.month = 2;
    }
    else if (containsSubstring(monStr, "MAR"))
    {
        dateValue.month = 3;
    }
    else if (containsSubstring(monStr, "APR"))
    {
        dateValue.month = 4;
    }
    else if (containsSubstring(monStr, "MAY"))
    {
        dateValue.month = 5;
    }
    else if (containsSubstring(monStr, "JUN"))
    {
        dateValue.month = 6;
    }
    else if (containsSubstring(monStr, "JUL"))
    {
        dateValue.month = 7;
    }
    else if (containsSubstring(monStr, "AUG"))
    {
        dateValue.month = 8;
    }
    else if (containsSubstring(monStr, "SEP"))
    {
        dateValue.month = 9;
    }
    else if (containsSubstring(monStr, "OCT"))
    {
        dateValue.month = 10;
    }
    else if (containsSubstring(monStr, "NOV"))
    {
        dateValue.month = 11;
    }
    else if (containsSubstring(monStr, "DEC"))
    {
        dateValue.month = 12;
    }
    
    if (getStringAsInteger(dateTokens[2], val))
    {
        dateValue.year = val;
    }

    // amount
    if (!getStringAsDouble(amount, amountValue))
    {
        amount = "";
    }
    
    // category - no modifications
    // comment - no modifications
}

bool isBlank(DateStruct date)
{
    return (date.day == 0 || date.month == 0 || date.year == 0);
}
