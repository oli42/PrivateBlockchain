#include "Block.hpp"

Block::Block(int index, Transaction d, size_t prevHash)
{
    idx = index;
    data = d;
    _previousHash = prevHash;
    _blockHash = generateHash(d);
}

size_t Block::generateHash(Transaction data){

    std::hash<std::string> hash1;
    std::hash<size_t> hash2;
    std::hash<size_t> finalhash;
    std::string toHash = std::to_string(data._amount) + data._receiverKey + data._senderKey + std::to_string(data._timestamp);
    
    return finalhash(hash1(toHash) + hash2(_previousHash));
}

size_t Block::getHash(){
    return _blockHash;
}

size_t Block::getPreviousHash(){
    return _previousHash;
}

Transaction Block::getData(){
    return data;
}

bool Block::isHashValid(Transaction data){

    return generateHash(data) == _blockHash;
}