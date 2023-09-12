#include "cat.h"

using namespace std;

void Cat::GetVoice() {
	cout << "Mew-mew\n";
}

Cat::Cat( string Name = "cat", int Age = -1 ) : Animal( Name, Age ) {
	
}