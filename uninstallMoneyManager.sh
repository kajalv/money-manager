#!/bin/bash
# Set up Money Manager for command line

CUR_DIR=$(pwd)
MONEY_MANAGER_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
MONEY_MANAGER_BIN="$MONEY_MANAGER_DIR/bin"
RUN_MM="$MONEY_MANAGER_BIN/MoneyManager"
ALIAS_MM="alias moneymanager=$RUN_MM"

echo "Cleaning up Money Manager"

cd $MONEY_MANAGER_DIR
make clean

# Remove moneymanager from aliases

if grep -q moneymanager ~/.bash_aliases; then
  cat ~/.bash_aliases | grep -v moneymanager > ~/temporary_aliases.tmp && mv ~/temporary_aliases.tmp ~/.bash_aliases
  . ~/.bash_aliases
fi

cd $CUR_DIR

echo "Cleanup successful."
echo

# read -n1 -r -p "Press any key to end. " key
