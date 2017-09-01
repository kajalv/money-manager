//
//  Constants.h
//  MoneyManager
//
//  Created by Varma, Kajal on 8/26/17.
//  Copyright © 2017 Kajal. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#define RULEDLINE "\n-----------------------------------------------------------------\n"

const std::string OPT_PREFIX = "--";

const std::string OPT_TRANSACTION = "transaction";
const std::string OPT_TYPE = "type";
const std::string OPT_DATE = "date";
const std::string OPT_AMT = "amount";
const std::string OPT_CATEGORY = "category";
const std::string OPT_COMMENT = "comment";
const std::string OPT_BALANCE = "balance";

const std::string SHORT_PREFIX = "-";

const std::string SHORT_TRANSACTION = "tr";
const std::string SHORT_TYPE = "ty";
const std::string SHORT_DATE = "d";
const std::string SHORT_AMT = "a";
const std::string SHORT_CATEGORY = "ca";
const std::string SHORT_COMMENT = "co";
const std::string SHORT_BALANCE = "b";

#define MAX_PARAMS 7

enum ParamIndex
{
    Transaction = 0,
    Type,
    Date,
    Amount,
    Category,
    Comment,
    Balance
};

enum TransactionType
{
    Bank = 0,
    PayTM,
    Uber
};

const std::string fileBank = "dataBank.csv";
const std::string filePayTM = "dataPayTM.csv";
const std::string fileUber = "dataUber.csv";

const std::string folderPrefix = "data/";

const std::string fileBalanceBank = "balanceBank.txt";
const std::string fileBalancePayTM = "balancePayTM.txt";

#endif /* Constants_h */
