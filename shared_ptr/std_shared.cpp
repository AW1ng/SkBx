#include <iostream>
#include <memory>

using namespace std;

class Toy {
    protected:
        string Name;
    public:
        string GetName() { return Name; }
        Toy( string name = "Ball" ) {
            Name = name; 
            cout<<Name+" created\n";
            }
        ~Toy() { cout << Name + " was dropped.\n"; }
    };

class Dog {
    protected:
        string Name;
        shared_ptr<Toy> InTeeth;
    public:
        Dog( string name = "Sharik" ) { Name = name; }
        ~Dog() { cout<<Name + " destructed.\n"; };
        string ToString() { return Name + " " + to_string( InTeeth.use_count() ); }
        bool GetToy( shared_ptr<Toy> toy ) {
            if( toy.use_count() > 2 ) {
                cout<<Name+" cannot take "+toy->GetName()+". Toy is busy now.\n";
                return false;
                }
            if( InTeeth ) {
                cout<<Name+" cannot take "+toy->GetName()+". Teeth are busy now.\n";
                return false;
                }
            cout<<Name+" getting "+toy->GetName()<<endl;
            InTeeth = toy;
            return true;
            }
        bool DropToy() {
            if( InTeeth ) {
                cout<<Name + " dropping " + InTeeth->GetName() << endl;
                InTeeth.reset();
                return true;
                }
            else {
                cout<<Name+" has nothing to drop\n";
                return false;
                }
            }
    };

int main() {
    shared_ptr<Toy> Ball( new Toy );
    shared_ptr<Toy> Bone( new Toy("Bone") );
    //cout << Ball->GetName()<< endl;
    Dog *Sharik = new Dog;
    cout<< Sharik->ToString()<<endl;
    Dog *Rex = new Dog("Rex");
    cout<< Rex->ToString()<<endl;

    cout<< Ball.use_count()<<endl;
    cout<< Bone.use_count()<<endl;
    Sharik->GetToy( Ball );
    cout<< Ball.use_count()<<endl;
    cout<< Sharik->ToString()<<endl;
    Sharik->GetToy( Ball );
    Rex->GetToy( Ball );
    Rex->GetToy( Bone );
    Sharik->GetToy( Bone );

    Sharik->DropToy();
    Sharik->GetToy( Ball );
    cout<< Sharik->ToString()<<endl;
    cout<< Ball.use_count()<<endl;
    Sharik->DropToy();
    Sharik->GetToy( Bone );
    cout<< Sharik->ToString()<<endl;
    cout<< Ball.use_count()<<endl;

    delete Sharik;
    return 0;
    }
