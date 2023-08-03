//By: Mycah Detorres and Karl Antonio

#include "HashMap.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



hashNode::hashNode(string s){
	keyword = s;
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(){
	keyword = "";
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(string s, string v){

	keyword = s;
	values = new string[100];
	values[0] = v;
	valuesSize = 100;
	currSize = 1;
}
void hashNode::addValue(string v) {
	// adding a valu to the end of the value array associated 
	// with a key

	/* 11-29-2021 */
	/*
	for(int i = 0; i<valuesSize; i++){
		if(values[i] == ""){
			values[i] = v;
			break;
		}
	}
	*/


	/* 11-30-2021 */


	/* 12-3-2021 */


	values[currSize] = v;
	currSize++;
	if(valuesSize == currSize){
		dblArray();
	}



	//values[currSize] = v;
	//currSize++;

	//cout << "Incremented currSize (it should be +=1 from prev): " << currSize << endl;




}
void hashNode::dblArray() {
	// when the value array gets full, you need to make a new 
	// array twice the size of the old one (just double, no 
	//going to next prime) and then copy over the old values 
	//to the new values, then de-allocate the old array.  
	//Again, just copying over, no hash functiosn involved 
	//here.

	/* 11-29-2021 */
	string *tmp = values;
	values = new string[2*valuesSize];
	for(int i = 0; i<valuesSize; i++){
		values[i] = tmp[i];
	}
	valuesSize *= 2;
	delete[]tmp;

	/*
	string *dblValues = new string[2*valuesSize];
	for(int i; i<valuesSize; i++){
		dblValues[i] = values[i];
	}
	valuesSize *= 2;
	delete[]values;
	*/

}

string hashNode::getRandValue() {
	//Every key has a values array - an array of words that 
	// follow that key in the text document.  You're going to 
	//randomly select one of those words and return it.  That 
	//will be the word that follows your key in your output 
	//function, and it will also be the next key.

	/* 11-29-2021 */
	int x;
	string a = "";
	if(currSize != 0){
		x = rand()%currSize;
		a = values[x];
	}


	return a;

}
