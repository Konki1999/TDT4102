#include "Animals.h"

Animal::Animal(string n, int a): name{n}, age{a}{};

string Cat::toString(){
    string str = "Cat: " + name + ", " + to_string(age);
    return str;
}

string Dog::toString(){
    string str = "Dog: " + name + ", " + to_string(age);
    return str; 
}

void testAnimal(){
    using namespace Graph_lib;
    Vector_ref<Animal> animals;

    Dog dog1 = Dog("Koda", 1);
    animals.push_back(dog1);
    Cat cat1 = Cat("Supernova", 6);
    animals.push_back(cat1);
    Dog dog2 = Dog("Kira", 7);
    animals.push_back(dog2);
    Cat cat2 = Cat("Hassan", 1);
    animals.push_back(cat2);
    for(Animal* x : animals){
        cout << x->toString() << endl;
    }
}