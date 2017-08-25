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

#define MAX_PARAMS 6

enum ParamIndex
{
    Transaction = 0,
    Type,
    Date,
    Amount,
    Category,
    Comment
};

#endif /* Constants_h */
