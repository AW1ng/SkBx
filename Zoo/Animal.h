#pragma once
#include "talent.h"
#include <vector>
#include "zoo.h"

using namespace std;
class Zoo;

class Animal {
	protected:
		string Name;
		int Age;
		vector<Talent *> Talanted;
		vector<Zoo*> WorkPlaces;
	public:
		Animal( string , int );
		~Animal();
		string ToString();
		virtual void GetVoice() = 0;
		void AddTalent( Talent *talent );
		void ShowTalents();
		vector<Zoo*> *GetWorkPlaces();
		void RemoveWorkPlace(Zoo *zoo );

};
