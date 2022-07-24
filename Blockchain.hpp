#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP
#include "Block.hpp"

class Blockchain{

    Block createGenesisBlock();

    public:
    std::vector<Block> chain;
    bool _corrupted; // a passer private

    Blockchain();
    std::string addBlock(Transaction data);
    bool isChainValid();
    std::string intro();

    Block* getLatestBlock();

};

#endif