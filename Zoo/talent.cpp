#pragma once
#include <string>
#include "talent.h"

using namespace std;

Talent::Talent( int level = 0) {
	if( level < 0 ) Level = 0;
	else if( level > 100 ) Level = 100;
	else Level = level;
}

string Talent::GetLevel() {
	return "Level: " + to_string( Level );
}