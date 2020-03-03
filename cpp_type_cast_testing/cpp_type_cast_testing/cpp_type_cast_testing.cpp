#include <iostream>
#include <string>

using std::string;

class Master {
private:
    string master_private = "private_default";
public:
    string master_public = "public_default";

    Master() {
        //std::cout << "Master()" << std::endl;
    }

    Master(string master_public) : master_public(master_public) {
        //std::cout << "Master()" << std::endl;
    }

    ~Master() {
        //std::cout << "~Master()" << std::endl;
    }

    virtual std::string to_string() {
        return "master_private: " + master_private + "\nmaster_public: " + master_public;
    }
};

class Derived : public Master {
public:
    string derived_private = "private_derived_default";

    Derived() : Master("cds") {
        //std::cout << "Derived()" << std::endl;
    }

    ~Derived() {
        //std::cout << "~Derived()" << std::endl;
    }

    virtual std::string to_string() {
        return "Master string: " + Master::to_string() + "\nDerived:\nmaster_public: " + master_public + "\nderived_private: " + derived_private;
    }
};

class Derived2 : public Master {
public:
    string derived_private = "private_derived2_default";

    Derived2() : Master("ccdsacdsa") {
        //std::cout << "Derived()" << std::endl;
    }

    ~Derived2() {
        //std::cout << "~Derived()" << std::endl;
    }

    virtual std::string to_string() {
        return "Master string: " + Master::to_string() + "\nDerived:\nmaster_public: " + master_public + "\nderived_private: " + derived_private;
    }
};



int main()
{
    /*

    Derived* d = new Derived();
    d->derived_private = "custom";
            
    Master* m = d;
    Master m1 = *m;

    Derived* dm = dynamic_cast<Derived*>(m);
    Derived2* dm2 = dynamic_cast<Derived2*>(m);

    std::cout << d->to_string() << std::endl;
    std::cout << std::endl;
    std::cout << m->to_string() << std::endl;
    std::cout << std::endl;
    std::cout << m1.to_string() << std::endl;
    std::cout << std::endl;
    std::cout << dm->to_string() << std::endl;
    std::cout << std::endl;
    std::cout << dm2->to_string() << std::endl;
    */

    {
        Derived* d = new Derived();
        d->derived_private = "custom";

        Master* m = dynamic_cast<Master*>(d);

        Derived* dm = dynamic_cast<Derived*>(m);

        std::cout << d->to_string() << std::endl;
        std::cout << std::endl;
        std::cout << m->to_string() << std::endl;
        std::cout << std::endl;
        std::cout << dm->to_string() << std::endl;
        std::cout << std::endl;
    }
}
