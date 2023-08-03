#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_

#include <iostream>
using namespace std;
/* Note: the hashNode is only how we're representing the data in your hash map.  It is not
 * the hash map.  In essence, in this activity, the hash Node is equivalent to a student class.
 * In our student class analogy, the keyword is equivalent to the student id, and the value
 * array is the other information about the student (first name, last name, year, major, etc.)
 */
class hashNode {
	friend class hashMap;
	string keyword;
	string *values;  // an array of all the words that follow the keyword in all the text documents
					// I initiallly made the arraysize 100, and then increased as I needed by
					//doubling its size
					//NOTE:: This is definitely a case where, when you're doubling the array, you'd want
					// to explicitly delete the old values array after you're done iwth it or you'd be
					//creating a boatload of garbage
	int valuesSize;  // keeping track of the current size of the array of values (I didn't make this
					//a linked list because I wanted to easily select randomly from the array)
	int currSize;  // the current number of values in the values array - when it gets full, we'll
					// have to make a new, larger sized values array and copy over all the old values.
public:
	hashNode();
	hashNode(string s);
	hashNode(string s, string v);
	void addValue(string v); //adds a word to the list of words (teh values array) that follow the keyword
	void dblArray();  // if the values array is full, makes a new array twice the size of the current
					//array and then copies over all the old values.  No hashing involved.  Just plain copying.
					//NOTE:: (I'm repeating this, but it bears repeating...
					//This is definitely a case where, when you're doubling the array, you'd want
					// to explicitly delete the old values array after you're done iwth it or you'd be
					//creating a boatload of garbage
	string getRandValue();  // generates a random number between 0 and the current size of the values array, and
							// returns the word in the values array at that random number.
};




#endif /* HASHNODE_HPP_ */
