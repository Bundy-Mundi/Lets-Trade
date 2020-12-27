#ifndef STOCK_H
#define STOCK_H
#include <time.h>
#include <conio.h>
#include <ctime>
#include <vector>
enum TRANSACTION_TYPE { SELL, BUY };

struct Transaction{
    Transaction(int, double);
    string currentTime;
    int type;
    double cost;

    friend ostream& operator<<(ostream& strm, const Transaction& t);
};

struct Company{
    Company(string, double, double);
    string companyName;
    double companyPrice;
    double companyValue;

    friend ostream& operator<<(ostream& strm, const Company& c);
};

class Stock{
public:
    Stock();
    Stock(string, string, double);

    // Get
    string GetName();
    double GetPrice();
    vector<Transaction> GetTransactionHistory();
    Company GetOwnedCompany();

    // Set
    void SetName(string);
    void SetPrice(double);
    void SetCompany(Company*); // Just passing pointer

    // Methods
    void AddTransactionHistory(int, double);
    //double PriceChangeRate();
    string UpOrDown();

    // Tests
    void PrintCompany();
    void PrintTransactionHistory();

    // Dectructor
    ~Stock();


protected:
    double stockCurrentPrice;
    double stockPrevPrice;
    string stockName;
    string stockSymbol;
    Company* ownedCompany;
    vector<Transaction> transactionHistory; // Neead fix

    friend ostream& operator<<(ostream& strm, const Stock& s);
};

#endif
