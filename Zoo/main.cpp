#include <iostream>
// #include "Animal.cpp"
#include "dog.cpp"
#include "count.cpp"
#include "sing.cpp"
#include "cat.cpp"
#include "zoo.cpp"


int main() {
//	Animal A;
	Dog *pDog = new Dog("Sharik", 4); cout << pDog->ToString() << endl;
	pDog->GetVoice();
	
	Count c;
//	c.Cast();
	Sing S;
	pDog->AddTalent(&c);
	Sing S1("Go go go");
	pDog->AddTalent(&S);
	pDog->AddTalent(&S1);
	pDog->ShowTalents();
	Cat Kitty;
	Kitty.AddTalent( &S );
	Kitty.AddTalent( &S1 );
	Kitty.AddTalent( &c );
	Kitty.ShowTalents();

	

	Zoo *MyZoo = new Zoo;
	Zoo *SecondZoo = new Zoo("Karabass Barabass");
	MyZoo->AddAnimal( &Kitty );
	MyZoo->AddAnimal( pDog);
	cout << "Kitty performance\n";
	MyZoo->Performance();
	
	SecondZoo->AddAnimal(pDog);
	SecondZoo->Performance();
	delete pDog;

	delete MyZoo;
	delete SecondZoo;
//	cout << "After Zoo: " << Kitty.ToString() << endl;
	Kitty.ShowTalents();
	
	return 0;
}