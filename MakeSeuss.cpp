
#include "MakeSeuss.hpp"
#include "HashMap.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

makeSeuss::makeSeuss(string f1,string f2,bool hash1, bool coll1) {
	ht = new hashMap(hash1,coll1);
	newfile = f2;
	fn = f1;

	readFile();
	writeFile();
}
void makeSeuss::readFile() {
	ifstream infile(fn.c_str(),ios::in);     // open file
	string key = "";
	string value="";
	infile>> key;

	infile >> key;
	ht->first = key;

	while (infile >> value) {          // loop getting single characters
		//cout << key <<": " << value << endl;
		ht->addKeyValue(key,value);
		key = value;
		value = "";
	}
	ht->addKeyValue(key,value);
	cout << endl;
	infile.close();

	ht->printMap();
}
void makeSeuss::writeFile() {
	ofstream outfile(newfile.c_str(),ios::out);
	float hashfloat = (float)ht->hashcoll/(float)ht->numKeys;
	float collfloat =  (float)ht->collisions/(float)ht->numKeys;
	if (ht->hashfn && ht->collfn) {
		outfile << "Collisions using hash 1: "<< hashfloat << ", and collision handling 1: " << collfloat <<endl;
	}
	else if (ht->hashfn) {
		outfile << "Collisions using hash 1: "<< hashfloat << ", and collision handling 2: " << collfloat<<endl;
	}
	else if (ht->collfn) {
		outfile << "Collisions using hash 2: "<< hashfloat << ", and collision handling 1: " << collfloat<<endl;
	}
	else {
		outfile << "Collisions using hash 2: "<< hashfloat << ", and collision handling 2: " << collfloat<<endl;
	}
	outfile<<endl;
	outfile << ht->first << " ";
	string key = "";
	string value = ht->map[ht->getIndex(ht->first)]->getRandValue();
	int ct = 0;
	int len = 0;
	while (ct < 500 &&  value != "") {
		key = value;
		outfile << key << " ";
		if (len == 11) {
			outfile << "\n";
			len = 0;
		}
		else len++;
		value = ht->map[ht->getIndex(key)]->getRandValue();
		ct ++;
	}
	outfile.close();
}


