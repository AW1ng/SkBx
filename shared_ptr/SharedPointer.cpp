#pragma once
#include <iostream>

using namespace std;

// Класс, реализующий умный указатель
template < typename T > class SmartPointer  {
	protected:
	    T *ptr; // Инкапсулированный указатель
	    int count_copy; //счётчик копий
    public:
    //конструктор
	SmartPointer( T *p = NULL ) {
		cout<< "SmartPointer C-tor is here...\n";
        //записываем 0 при создании копий нет
		count_copy = 0;
		ptr=p;
	    }
    // конструктор копирования
	SmartPointer( const SmartPointer &obj ) {
		//создается копия - увеличиваем счётчик
		ptr=obj.ptr; 	//count_copy++;
        count_copy = obj.count_copy + 1;
        //obj.count_copy++;
	    }
    //перегрузка оператора равно
	SmartPointer operator=( const SmartPointer &obj ) {
        cout<< "Operator= is here\n";
		//создается копия - увеличиваем счётчик
		ptr=obj.ptr; 	//count_copy++;
        count_copy = obj.count_copy + 1;
		//возвращаем сам объект для ситуации a=b=c
		return *this;
	    }
    // уничтожение объекта
	~SmartPointer() {
		//если объект есть и копий нет
		if( ptr != NULL && count_copy == 0 ) {
			cout<<"\n~Delete Object\n";
			delete ptr;	//уничтожаем объект
		    }
		//в противном случае(уничтожается копия)
		else {
			//уменьшаем счётчик
			count_copy--;
			cout<<"\n~Delete Copy\n";
		    }
	    }
    //старая добрая перегрузка селектора
	T* operator->() { return ptr; }
    operator bool() { return ptr != NULL; }    
    int use_count() { return count_copy; }
    void reset() { ~SmartPointer(); }
    };
