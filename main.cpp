#include "Decoder.hpp"

//Exception and return value definitions
#define INVALID_N_ARG -1
#define INVALID_LIMIT -2
#define STD_EXEC      -3

int main(int argc, char *argv[]){
	int int1, int2, limit;
	string str1, str2;
	list<string> str_list;

	//Simple exceptions are created for limiting the "limit" arguments and the minimum value of arguments
	try{
        if (argc >4){
            int1 = stoi(argv[1]);
            int2 = stoi(argv[2]);

            limit  = stoi(argv[3]);

            if(limit < 1 || limit > 100 ){
                throw INVALID_LIMIT;
            }

            str1 = argv[4];
            str2 = argv[5];
        } else {
            throw INVALID_N_ARG;
        }
    } catch(int i){
        if (i == INVALID_N_ARG){
            cout << "Invalid number of arguments. Ex: fizzbuzz int1 int2 limit str1 str2" <<endl;
            return INVALID_N_ARG;
        } else {
            cout << "Invalid limit value. Range: 1 <= limit <= 100" <<endl;
            return INVALID_LIMIT;
        }
    }


    //Body of the code
    try{
        //The functions for decoding the series of number and showing the string list are called from the Decode class
        Decoder *dec = new Decoder(int1, int2, limit, str1, str2);
        dec->decodeString();
        dec->showList();
    } catch(const exception& e){
        //Standard Exceptions are catch
        cout << "Standard exception " << e.what() << endl;
        return STD_EXEC;
    }

	return 0;
}
