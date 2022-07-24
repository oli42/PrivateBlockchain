#include "Blockchain.hpp"
#include <unistd.h>
#include <sstream>


int main(){

    Blockchain yo;
    while (1){

        std::string i = yo.intro();

        if (!i.compare("1")){
            if (yo._corrupted){
                std::cout << "**************************************************" << std::endl;
                std::cout << "The chain has been corrupted, you can't do any transaction till further notice." << std::endl;
                std::cout << "**************************************************" << std::endl;
                continue;
            }
            time_t data1Time;
            std::string recName;
            std::string sName;
            int a = 0;
            std::cout << "Please provide an amount." << std::endl;
            scanf("%d", &a);
            std::cout << "Please provide a receiver name." << std::endl;
            std::cin >> recName;
            std::cout << "Please provide a sender name." << std::endl;
            std::cin >> sName;
            Transaction data1(a, recName, sName, time(&data1Time));
           std::string ref  = yo.addBlock(data1);

            std::cout << " " << std::endl;
            std::cout << "**************************************************" << std::endl;
            std::cout << "Your transaction has been added to the Blockchain." << std::endl;
            std::cout << "Reference: " << ref << std::endl;
            std::cout << "**************************************************" << std::endl;
            std::cout << " " << std::endl;

        }
        else if (!i.compare("2")){

            std::string a;
            std::cout << "Please provide a reference." << std::endl;
            std::getline(std::cin, a);

            std::vector<Block>::iterator it;
            for (it = yo.chain.begin(); it != yo.chain.end(); it++){
                Block currentBlock = *it;
                size_t blockHash = currentBlock.getHash();
                std::stringstream ss;
                ss << blockHash;
                std::string other = ss.str();
                if (!other.compare(a)){
                    std::cout << "**************************************************" << std::endl;
                    std::cout << "Your reference is in the chain." << std::endl;
                    std::cout << "**************************************************" << std::endl;

                    break;
                }
                if (currentBlock == yo.chain.back()){
                    std::cout << "**************************************************" << std::endl;
                    std::cout << "I am afraid your reference is not in the chain." << std::endl;
                    std::cout << "**************************************************" << std::endl;
                
                }
            }
        }
        else if (!i.compare("3")){

            if (!yo.isChainValid()){
                std::cout << " " << std::endl;
                std::cout << "****************************" << std::endl;
                std::cout << "The chain has been corrupted" << std::endl;
                std::cout << "****************************" << std::endl;
                std::cout << " " << std::endl;
            }
            else{
                std::cout << " " << std::endl;
                std::cout << "**************************" << std::endl;
                std::cout << "The chain is not corrupted" << std::endl;
                std::cout << "**************************" << std::endl;
                std::cout << " " << std::endl;
            }

        }
        else if (!i.compare("4")){
            Block* b = yo.getLatestBlock();
            b->data._amount = 88888;
            yo._corrupted = true;
            std::cout << "The Blockchain has just been corrupt. You can check if you want." << std::endl;

        }
        else if (!i.compare("5"))
            break;

        else{

            std::cout << "** Invalid answer, try again. **" << std::endl;
        }
    }
    std::cout << "The actual Blockchain size is " << yo.chain.size() << std::endl;
    std::cout << "Enjoy the rest of your day." << std::endl;
    return (0);

}