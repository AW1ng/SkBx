#include "sing.h"
#include <iostream>

void Sing::Cast() {
    cout << Song << endl;
}

Sing::Sing(string song = "Nothing else matters") {
    Song = song;
}