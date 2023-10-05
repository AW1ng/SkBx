#include <iostream>
#include "own_shared_ptr.h"

using namespace std;

class Temp {
	int TEMP;	
	public:
		//конструктор
		Temp() { TEMP = 25; }
        ~Temp() { cout<<"Temp D-tor is here\n"; }
		//функция показа на экран
		void TempFunction() { cout<<"TEMP = "<<TEMP<<"\n\n"; } 
		//функция установки значения
		void TempSet(int T){ TEMP=T; }
    };


int main() {
	//создаем объект
	Temp *main_ptr = new Temp;
	//инициализируем этим объектом умный указатель
	SmartPtr< Temp > PTR(main_ptr);
    cout<<"PTR usecount is "<<PTR.use_count()<<endl;
	//проверяем работу умного указателя
	PTR->TempSet( 100 );
	PTR->TempFunction();
	cout<<"создаем копию (работа конструктора копирования)\n";
	SmartPtr< Temp > PTR2; 
    cout<<"PTR usecount is "<<PTR.use_count()<<endl;
    PTR2 = PTR;
    cout<<"PTR usecount is "<<PTR.use_count()<<endl;
    cout<<"Reset PTR\n";
    PTR.reset();
    cout<<"PTR usecount is "<<PTR.use_count()<<endl;
    cout<<"PTR2 usecount is "<<PTR2.use_count()<<endl;
    cout<<"Gonna return zero\n"<<flush;    
    return 0;
    }

