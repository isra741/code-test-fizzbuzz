#ifndef DECODER_H
#define DECODER_H

#include <list>
#include <iostream>
#include <experimental/iterator>

using namespace std;

class Decoder {      
  private:  
	//Decoder Proprieties 
    int multiple1;
	int multiple2;
	int limit;
    string pattern1;
	string pattern2;
	list<string> decodedString;
	
   public:
	//Constructor 
	Decoder(int multiple1, int multiple2, int limit,
			string pattern1, string pattern2);
	
	//Destructor
	~Decoder();
	
	//Sring list generator
	void decodeString();
	
	//Method to show string list
	void showList();
};

#endif