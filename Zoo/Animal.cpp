#pragma once
#include "Animal.h"
#include <iostream>

using namespace std;


Animal::Animal( string name = "Unnamed animal", int age = -1 ) {
	Name = name;
	Age = age;
	Talanted.clear();
	WorkPlaces.clear();
}

Animal::~Animal() {
	Talanted.clear();
	for( int i = 0; i < WorkPlaces.size(); i++ ) {
		if(WorkPlaces[i])
			WorkPlaces[i]->RemoveAnimal( this );
	}
	WorkPlaces.clear();
}

/*void Animal::GetVoice() {
	cout << "Default animal voice\n";
}*/

string Animal::ToString() {
	string result = Name + " ";
	if( Age < 0 ) result += "NonAged\n";
	else result += to_string( Age );
	result += "Working at: ";
	for( int i = 0; i < WorkPlaces.size(); i++ ) {
		if( WorkPlaces[i] )
			result += WorkPlaces[i]->GetName() + ", ";
	}
	return result;
}

void Animal::AddTalent(Talent *talent)  {
	Talanted.push_back( talent );
}

// Talent* Animal::GetTalent() { return Talanted; }
void Animal::ShowTalents() {
	cout << ToString() + "has talents:\n";
	for(int i = 0; i < Talanted.size(); i++) {
		Talanted[i]->Cast();
	}
}

vector<Zoo*> *Animal::GetWorkPlaces() { return &WorkPlaces; }

void Animal::RemoveWorkPlace(Zoo *zoo ) {
	for(int i = 0; i < WorkPlaces.size(); i++ ) {
		if( WorkPlaces[i] == zoo ) WorkPlaces[i] = nullptr;
	}
}

