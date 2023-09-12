
#pragma once
#include "Animal.cpp"

class Cat : public Animal {
	public:
		void GetVoice();
		Cat( string , int );
};