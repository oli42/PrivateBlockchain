#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP
#include "Block.hpp"

class Blockchain{

    Block createGenesisBlock();

    public:
    std::vector<Block> chain;

    Blockchain();
    std::string addBlock(Transaction data);
    bool isChainValid();
    std::string intro();

    Block* getLatestBlock();

};

#endif