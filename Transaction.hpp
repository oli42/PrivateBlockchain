#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <ctime>
#include <vector>
#include <iostream>

class Transaction {

    public:
    int _amount;
    std::string _senderKey;
    std::string _receiverKey;
    time_t _timestamp;

    public:
    Transaction();
    Transaction(int amount,std::string senderkey, std::string receiverkey, time_t timestamp);
    ~Transaction();

};

#endif