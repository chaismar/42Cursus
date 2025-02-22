#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
    virtual void identify() const = 0;
    virtual ~Base() {}
};

class A : public Base {void identify() const {std::cout << "A" << std::endl;}};
class B : public Base {void identify() const {std::cout << "B" << std::endl;}};
class C : public Base {void identify() const {std::cout << "C" << std::endl;}};

Base* generate() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 3;

    switch (random) {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        return 0;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    } else {
        std::cout << "Type inconnu\n";
    }
}

void identify(Base& p) {
    p.identify();               
}

int main() {
    Base* base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}
