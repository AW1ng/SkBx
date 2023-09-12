#pragma once
#include <vector>
#include "Animal.h"
#include <functional>

using namespace std;
class Animal;

class Zoo {
    protected:
    	string Name;
        vector <Animal*> Animals;
        // vector<reference_wrapper<Animal> > Animals;
    public:
        Zoo( string );
        ~Zoo();
        string GetName();
        void ListAnimals();
        void AddAnimal(Animal *animal);
        void Performance();
        void RemoveAnimal( Animal *animal );
};