#include "Dummy.h"

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a: " << *a.num <<'\n';
    cout << "b: " << *b.num <<'\n';
    cout << "c: " << *c.num <<'\n';

    *b.num = 3;
    *c.num = 5;

    cout << "a: " << *a.num <<'\n';
    cout << "b: " << *b.num <<'\n';
    cout << "c: " << *c.num <<'\n'; 
}

Dummy::Dummy(const Dummy& d) : num{nullptr}{
    this->num = new int{};
    int* temp = d.num;
    *num = *temp;
}

Dummy Dummy::operator=(const Dummy& d){
    swap(*num, *d.num);
    return *this;
}