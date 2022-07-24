#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <ctime>
#include <vector>
#include <iostream>
#include "Transaction.hpp"
#include <sstream>


class Block{

    int idx;
    size_t _blockHash;
    size_t _previousHash;
    size_t generateHash(Transaction data);

    public:
    Block(int index, Transaction data, size_t prevHash);
    Transaction data;

    friend bool operator==(const Block& lhs, const Block& rhs){
            return lhs._blockHash == rhs._blockHash;
        }

    size_t getHash();
    size_t getPreviousHash();
    Transaction getData();


    bool isHashValid(Transaction data);
};

    

#endif
