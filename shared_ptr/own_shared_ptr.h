#pragma once
#include <iostream>
using namespace std;

template <typename T> 
class SmartPtr {
    protected:
        T *ptr = nullptr;
        int *counter = nullptr;
    public:
        SmartPtr() { cout<<"No params = nothing to do.\n"; }
        SmartPtr( T *p ) {
            cout<<"SmartPtr C-tor is here.\n";
            counter = new int(1);
            ptr = p;
        }
        SmartPtr( const SmartPtr &obj ) {
            ptr = obj.ptr;
            counter = obj.counter;
            (*counter)++;
        }

        SmartPtr( SmartPtr &&obj ) {
            ptr = obj.ptr;
            counter = obj.counter;
            obj.ptr = nullptr;
            obj.counter = nullptr;
        }

        SmartPtr operator=( const SmartPtr &obj ) {
            cout << "Operator=  is here\n";
            ptr = obj.ptr;
            cout<<"counter is now "<<*obj.counter<<endl<<flush;
            counter = obj.counter;
            (*counter)++;
            return *this;
        }

        ~SmartPtr() {
            cout<<"Destructing with counter "<<use_count()<<flush;
            if( counter && *counter > 1 ) {
                cout<<" not last ";
                (*counter)--;
                cout<<"counter is now "<<*counter<<endl;
                return;
            }
            cout<<" Destructing the last\n"<<flush;
            if( ptr ) delete ptr;
            ptr = nullptr;
            cout<<"Killing the counter\n";
            if( counter ) delete counter;
            cout<<"Zeroing the counter\n";
            counter = nullptr;
            cout<<"Destruction complete\n";
        }

        T* operator->() const { return  ptr; }  
        T& operator*() const{ return  *ptr; }    
        operator bool() {return ptr != NULL;}
        int use_count() { 
            if( counter ) return *counter; 
            else return 0;
            }
        void reset()  { 
            cout<<"Resetting...   ";
            if( *counter ) (*counter)--;
            counter = nullptr; ptr = nullptr;
            cout<<"reset complete.\n"<<flush;
            } 

};

