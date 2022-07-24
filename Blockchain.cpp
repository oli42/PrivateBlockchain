#include "Blockchain.hpp"

Blockchain::Blockchain(){

    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock(){

    time_t current;
    Transaction d(0, "yo", "yo", time(&current));

    std::hash<int> hash1;
    Block genesis(0, d, hash1(0));
    return genesis;
}

Block* Blockchain::getLatestBlock(){

    return &chain.back();
}


std::string Blockchain::addBlock(Transaction data){
    int index = (int)chain.size() - 1;
    Block newBlock(index, data, getLatestBlock()->getHash());
    chain.push_back(newBlock);

    std::cout << "new block hash = " << newBlock.getHash() << std::endl;

    std::stringstream ss;
    ss << newBlock.getHash();
    std::string other = ss.str();
    return (other);
}

bool Blockchain:: isChainValid(){

    std::vector<Block>::iterator it;
    int len = (int)chain.size();
    for (it = chain.begin(); it != chain.end(); it++){
        Block currentBlock = *it;
        if (!currentBlock.isHashValid(currentBlock.getData()))
            return false;
        if(len > 1){

            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
                return false;
        }

    }
    return true;
}

std::string Blockchain::intro(){

    std::string i;
        std::cout << " " << std::endl;
        std::cout << "What can of operation would you like to proceed to? Press a number then Enter." << std::endl;
        std::cout << "1: Operate a new transaction" << std::endl;
        std::cout << "2: Checking a transaction" << std::endl;
        std::cout << "3: Checking the integrity of the Blockchain" << std::endl;
        std::cout << "4: Corrupt the Blockchain" << std::endl;
        std::cout << "5: Exit the menu" << std::endl;

        std::getline(std::cin, i);
    return (i);
}
