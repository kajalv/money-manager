//
//  StringUtils.cpp
//  MoneyManager
//
//  Created by Varma, Kajal on 8/26/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#include "StringUtils.hpp"

bool isBlank(const std::string &arg)
{
    return arg.empty();
}

bool equals(const std::string &arg1, const std::string &arg2)
{
    return equals(arg1.c_str(), arg2.c_str());
}

bool equals(const char * arg1, const char * arg2)
{
    if (strcasecmp(arg1, arg2) == 0)
    {
        return true;
    }
    return false;
}

bool containsCharacter(const std::string &arg, char character)
{
    return (arg.find(character) != std::string::npos);
}

bool containsSubstring(const std::string &parentStr, const std::string &subStr)
{
    if (parentStr.empty() || subStr.empty())
    {
        return false;
    }
    return (parentStr.find(subStr) != std::string::npos);
}

bool getStringAsInteger(const std::string &arg, int& outParam)
{
    try
    {
        outParam = std::stoi(arg);
        return true;
    }
    catch (...)
    {
    }
    
    return false;
}

bool getStringAsDouble(const std::string &arg, double& outParam)
{
    try
    {
        outParam = std::stod(arg);
        return true;
    }
    catch (...)
    {
    }
    
    return false;
}

void replaceAll(std::string &arg, const std::string &from, const std::string &to)
{
    if (from.empty())
    {
        return;
    }
    
    size_t startPos = 0;
    
    while ((startPos = arg.find(from, startPos)) != std::string::npos)
    {
        arg.replace(startPos, from.length(), to);
        startPos += to.length(); // Handles to being substring of from
    }
}

void tokenize(const std::string &arg, std::string tokens[], int maxSize)
{
    unsigned long pos = arg.find(' ');
    unsigned long initialPos = 0;
    
    std::string tempStr;
    int i = 0;
    
    // Decompose statement
    while(pos != std::string::npos && i < maxSize)
    {
        tempStr = arg.substr(initialPos, pos - initialPos + 1);
        trim(tempStr);
        if (!tempStr.empty())
        {
            tokens[i] = tempStr;
            i++;
        }
        initialPos = pos + 1;
        pos = arg.find(' ', initialPos);
    }
    
    // Add the last one
    tempStr = arg.substr(initialPos, std::min(pos, arg.size()) - initialPos + 1);
    trim(tempStr);
    if (!tempStr.empty())
    {
        tokens[i] = tempStr;
        i++;
    }
}

void ltrim(std::string &arg)
{
    arg.erase(arg.begin(), std::find_if(arg.begin(), arg.end(), [](int ch)
                                    {
                                        return !std::isspace(ch);
                                    }));
}

void rtrim(std::string &arg)
{
    arg.erase(std::find_if(arg.rbegin(), arg.rend(), [](int ch)
                         {
                             return !std::isspace(ch);
                         }).base(), arg.end());
}

void trim(std::string &arg)
{
    ltrim(arg);
    rtrim(arg);
}

void toUpper(std::string &arg)
{
    transform(arg.begin(), arg.end(), arg.begin(), toupper);
}
