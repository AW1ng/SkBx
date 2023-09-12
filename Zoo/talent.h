#pragma once
#include <string>
using namespace std;

class Talent {
	protected:
		int Level;
	public:
		Talent( int level );
		virtual void Cast() = 0;
		string GetLevel();
};