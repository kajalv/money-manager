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

const std::string fileBank = "dataBank.csv";
const std::string filePayTM = "dataPayTM.csv";
const std::string fileUber = "dataUber.csv";

const std::string folderPrefix = "data/";

const std::string fileBalanceBank = "balanceBank.txt";
const std::string fileBalancePayTM = "balancePayTM.txt";

#endif /* Constants_h */
