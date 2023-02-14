#include "QuadProbe.h"
#include "Chaining.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;

using namespace std;

int main(int argc, const char * argv[]){
    const int TABLE_SIZE = 100000007;

    ifstream quad_dictionary_file;
    ifstream quad_input_file;

    ifstream chaining_dictionary_file;
    ifstream chaining_input_file;


    QuadProbe qp(TABLE_SIZE);
    Chaining c(TABLE_SIZE);

    duration<double, nano> quad_hash_time;
    duration<double, nano> chaining_hash_time;

    int chaining_num_wrong = 0;
    int quad_num_wrong = 0;

    quad_dictionary_file.open(argv[1]);
    quad_input_file.open(argv[2]);


    if(!quad_dictionary_file || !quad_input_file){
        cout << "Error opening dictionary file or Input File" << endl;
        return 0;
    }
    else{

    string quad_dict_word;
    auto quadStart = high_resolution_clock::now();
    while(quad_dictionary_file >> quad_dict_word){
        qp.insert(quad_dict_word);
    }
    auto quadEnd = high_resolution_clock::now();
    quad_hash_time = quadStart - quadEnd;


    string quad_check_word;
    while(quad_input_file >> quad_check_word){
        if(qp.search(quad_check_word) == "WNF"){
            quad_num_wrong++;
            cout << "Quadratic Probing Found Incorrectly Spelt Word : "  << quad_check_word << endl;
        }
        else{
            continue;
        }

    }
    }

    quad_dictionary_file.close();
    quad_input_file.close();

// END OF QUADRATIC PROBING FOR COLLISIONS

// BEGINNING OF CHAINING FOR COLLISIONS

    chaining_dictionary_file.open(argv[1]);
    chaining_input_file.open(argv[2]);

    if(!chaining_dictionary_file || !chaining_input_file){
        cout << "Error opening dictionary file or Input File" << endl;
        return 0;
    }
    else{

        string chaining_dict_word;
        auto chainingStart = high_resolution_clock::now();
        while(chaining_dictionary_file >> chaining_dict_word){
        c.insert(chaining_dict_word);
    }
        auto chainingEnd = high_resolution_clock::now();
        chaining_hash_time = chainingStart - chainingEnd;


    string chaining_check_word;
    while(chaining_input_file >> chaining_check_word){
        if(c.search(chaining_check_word) == "WNF"){
            chaining_num_wrong++;
            cout << "Incorrectly Spelt Word : "  << chaining_check_word << endl;
        }
        else{
            continue;
        }

    }

    }

    cout << "QUADRATIC PROBING FOUND : " << quad_num_wrong << " INCORRECTLY SPELLED WORDS \n TIME SPENT CREATING HASH TABLE (QUADRATIC PROBING): " << quad_hash_time.count() << endl;
    cout << "CHAINING FOUND : " << chaining_num_wrong << " INCORRECTLY SPELLED WORDS \n TIME SPENT CREATING HASH TABLE (CHAINING) : " << chaining_hash_time.count() << endl;

    chaining_dictionary_file.close();
    chaining_input_file.close();

return 0;
}