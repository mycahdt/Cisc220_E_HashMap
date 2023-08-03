#include <iostream>
#include "MakeSeuss.hpp"
#include <time.h>
#include <stdlib.h>

using namespace std;
int main() {
	srand(time(NULL));
	makeSeuss voice1("DrSeuss.txt","Seussout1.txt",true,true);
	makeSeuss voice2("DrSeuss.txt","Seussout2.txt",false,true);
	makeSeuss voice3("DrSeuss.txt","Seussout3.txt",true,false);
	makeSeuss voice4("DrSeuss.txt","Seussout4.txt",false,false);
//OR

	/*
	makeSeuss voice5("GEChap1a.txt","GEout1.txt",true,true);
	makeSeuss voice6("GEChap1a.txt","GEout2.txt",false,true);
	makeSeuss voice7("GEChap1a.txt","GEout3.txt",true,false);
	makeSeuss voice8("GEChap1a.txt","GEout4.txt",false,false);
	*/

	return 0;
}
