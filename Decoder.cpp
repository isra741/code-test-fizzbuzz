#include "Decoder.hpp"

// Decoder constructor
Decoder::Decoder(int multiple1=3, int multiple2=5, int limit=16,
			string pattern1="fizz", string pattern2="buzz")
{
	this->multiple1 = multiple1;
    this->multiple2 = multiple2;
    this->limit     = limit;
	this->pattern1  = pattern1;
	this->pattern2  = pattern2;
}

// Decoder destructor
Decoder::~Decoder()
{
	delete[] this;
}

/**
 * Generate decode string list
 *
 * This function verifies if every number in a range is a multiple 
 * and replace those number by pre-defined string patterns
 *
 * @param class object
 * @return no return
 */
void Decoder::decodeString()
{
	string str_tmp = "";
	
	//For loop to iterate the different 
	for(int i = 1; i<=limit;i++){
		
		//Initialize temporaty string to be concatenated
		str_tmp = "";
		
		//Detect if the current value is a multiple of the 2 numbers
		if(i%multiple1==0 || i%multiple2==0){
			if(i%multiple1==0){
				str_tmp = pattern1;
			}
			//Concatenat the temp string to generate the composed string 
			if(i%multiple2==0){
				str_tmp += pattern2;
			}
		} else {
			//Number is converted to string
			str_tmp = to_string(i);
		}
		
		//Add the new string to the end of the list
		decodedString.push_back(str_tmp);
	}
}

/**
 * Show the genereated decoded string list
 *
 * This function walks in a list, join each value in a ostream 
 * and separate the different values by a comma
 *
 * @param  class object
 * @return no return
 */
void Decoder::showList()
{
    copy(decodedString.begin(),decodedString.end(),
            experimental::make_ostream_joiner(std::cout, ","));
}
