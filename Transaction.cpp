#include "Transaction.hpp"

Transaction::Transaction(){}

Transaction::Transaction(int amount,std::string senderkey, std::string receiverkey, time_t timestamp)
    : _amount(amount), _senderKey(senderkey), _receiverKey(receiverkey), _timestamp(timestamp)
    {}

Transaction::~Transaction(){}