# Money Manager

Command line application for MacOS, which helps to keep track of bank account transactions, PayTM wallet transactions, and Uber rides.

## Setup

* From Terminal, `cd` to the directory containing the repository.
* Run `sh installMoneyManager.sh`
* To remove, run `sh uninstallMoneyManager.sh`

## Usage

From Terminal:

```
moneymanager [--options]
```

The options are:

`--transaction` : `Bank`, `PayTM`, or `Uber`

`--type` : For bank and PayTM - `Credit` or `Debit` and for Uber, `Personal` or `Business`

`--date` : Date in format such as `15/6/2017` or `15 Jun`

`--amount` : Cash value

`--category` : Any category you want to categorize the transaction as, such as `Travel` or `Shopping`

`--comment` : Additional comments

Depending on the transaction, some options may not be required.

## Modifications to project before use

In Xcodec go to Product > Scheme > Edit Scheme > Run test > Options. Down under Options check `Use custom working directory` and set it to the directory containing the code. eg. `~/money-manager`. (The program will store data in the `data/` folder.)
