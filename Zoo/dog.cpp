#include "dog.h"

using namespace std;


void Dog::GetVoice() {
	cout << "Wow-wow\n";
}

Dog::Dog( string Name = "dog", int Age = -1 ) : Animal( Name, Age ) {
	
}