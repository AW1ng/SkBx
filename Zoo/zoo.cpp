#include "zoo.h"
#include <vector>
#include <iostream>

using namespace std;

Zoo::Zoo( string name = "Roga i Kopyta") {
    cout << "Zoo c- tor\n";
    Name = name;
    Animals.clear();
}

Zoo::~Zoo() {
	for( int i = 0; i < Animals.size(); i++ ){
		if(Animals[i] ) Animals[i]->RemoveWorkPlace( this );
	}
	Animals.clear();
}

void Zoo::ListAnimals() {
    cout << "Zoo list:\n";
     for( int i = 0; i < Animals.size(); i++ ) {
     	if(Animals[i]) cout << Animals[i]->ToString() << endl;
//        cout << remove_reference<Animal&>::type(Animals[i]).ToString();
     }
//    for( auto a : Animals ) cout << a->ToString() << endl;
}

void Zoo::AddAnimal( Animal *animal ) {
    Animals.push_back( animal );
    animal->GetWorkPlaces()->push_back( this );
}

void Zoo::RemoveAnimal( Animal *animal ) {
	for( int i = 0; i < Animals.size(); i++ ) {
		if( Animals[i] == animal ) 
			Animals[i] = nullptr;	
	}
}

void Zoo::Performance() {
     for( int i = 0; i < Animals.size(); i++ ) {
        cout << GetName() + '\n';
        for( int i = 0; i < Animals.size(); i++ ) {
			if( Animals[i] ) 
				Animals[i]->ShowTalents();	
		}
        // cout << Animals[i].ToString();
    }
//    for(auto a: Animals ) a.ShowTalents();
}

string Zoo::GetName() {
	return Name;
}