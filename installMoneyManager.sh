#!/bin/bash
# Set up Money Manager for command line

CUR_DIR=$(pwd)
MONEY_MANAGER_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
MONEY_MANAGER_BIN="$MONEY_MANAGER_DIR/bin"
RUN_MM="$MONEY_MANAGER_BIN/MoneyManager"
ALIAS_MM="alias moneymanager=$RUN_MM"

echo "Money Manager Setup"

cd $MONEY_MANAGER_DIR
make

# Add moneymanager to aliases

if grep -q moneymanager ~/.bash_aliases; then
   # Alias already exists
   :
else
   echo $ALIAS_MM >> ~/.bash_aliases
   . ~/.bash_aliases
fi

cd $CUR_DIR

echo "Setup successful."
echo

# read -n1 -r -p "Press any key to end. " key
