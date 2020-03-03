#include <iostream>
#include <string>

using std::string;

class Master {
private:
    string master_private = "private_default";
public:
    string master_public = "public_default";

    Master() {
        std::cout << "Master()" << std::endl;
    }

    Master(string master_public) : master_public(master_public) {

    }

    ~Master() {
        std::cout << "~Master()" << std::endl;
    }

    virtual std::string to_string() {
        return "master_private: " + master_private + "\nmaster_public: " + master_public;
    }
};

class Derived : public Master {
public:
    Derived() : Master("cds") {
        std::cout << "Derived()" << std::endl;
    }

    ~Derived() {
        std::cout << "~Derived()" << std::endl;
    }
};



int main()
{
    Derived d;

    std::cout << d.to_string() << std::endl;
}
