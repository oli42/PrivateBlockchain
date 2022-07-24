#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <sstream>


class Client{

    public:
    std::string _name;
    int _account;
    std::string _hashHelper;

    public:
    Client() {}
    Client(const std::string& name, const int& account): _name(name), _account(account), _hashHelper("a") {}
    ~Client(){}


};

bool operator==(const Client& lhs, const Client rhs) {
    return lhs._name == rhs._name && lhs._account == rhs._account;
}

class Ledger : public Client{

    public:
    std::map<std::string, int> ledger;

    public:
    Ledger(){}
    Ledger(Client &one){
        hasher(one);
    }

    int hasher(Client one){

        // std::cout << "1 = " << one._hashHelper << std::endl;
        std::size_t h1 = std::hash<std::string>{}(one._name);
        std::size_t h2 = std::hash<std::string>{}(one._hashHelper);
        std::cout << "h1= "<< h1 << std::endl;
        std::cout << "h2= "<< h2 << std::endl;

        std::stringstream ss;
        ss << (h1 + h2);
        std::string s = ss.str();
        std::cout << "s = " << s << std::endl;

        if ( s[1] == 48 && s[2] == 48 && s[3] == 48){
            ledger[s] = one._account;
            return (0);
        }
        else{
            std::cout << "Still have to hash!!" << std::endl;
            one._hashHelper += "a";
        // std::cout << "2 = " << one._hashHelper << std::endl;

            return hasher(one);
        }

    }
    ~Ledger(){}
};

int main(){

    Client jo("James", 888);
    Ledger reg(jo);

    std::string str = jo._name;

    std::size_t h1 = std::hash<std::string>{}(str);

    std::stringstream ss;
    ss << h1;
    std::string s = ss.str();

    if (reg.ledger[s]){
    std::cout << "in main Jo's hashed name = " <<  s << std::endl;
    std::cout << "in main Jo's account = " <<  reg.ledger[s] << std::endl;

    }


    // reg.ledger.insert(std::pair<std::string, int>(str, 77));
    reg.ledger[jo._name] = 44;
    std::cout << "in main Jo's name = " <<  jo._name << std::endl;
    std::cout << "in main Jo's account = " <<    reg.ledger[jo._name]  << std::endl;
    std::cout << "in main Jo's account = " <<    jo._account  << std::endl;




    return (0);
}