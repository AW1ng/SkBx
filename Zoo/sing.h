#include "talent.h"
#include <iostream>
class Sing : public Talent{
    protected:
        string Song;
	public:
        Sing( string song );
        void Cast();
};