#include "QuadProbe.h"


QuadProbe::QuadProbe(int size){
        table_size = size;
        table = new string[table_size];
        for (int i = 0; i < table_size; i++) {
            table[i] = "";
        }
}

unsigned int QuadProbe::hashfunction(string &word){
    unsigned int key = 0;
    for (char ch : word){
        key = 37*key+ch;
    }
    
    return key % table_size;
}

void QuadProbe::insert(string word) {
        int index = hashfunction(word);
        for (int i = 1; i < table_size; i++) {
            if (table[index] == "") {
                table[index] = word;
                break;
            } else {
                index = (index + i * i) % table_size;
            }
        }
}

string QuadProbe::search(string word){
    int index = hashfunction(word);

    for (int i = 1; i < table_size; i++) {
        if (table[index] == "") {
            return "WNF";
        } else if (table[index] == word) {
            return table[index];
        } else {
            index = (index + i * i) % table_size;
        }
    }
    return "WNF";
}


bool QuadProbe::isPrime(int n){
    if(n<=1){
        return false;
    }
    int upper_lim = sqrt(n);
    for (int i = 2; i <= upper_lim; i++){
        if (n % i == 0){
            return false;
        }
    }

    return true;
}

int QuadProbe::nextPrime(int n){
    if (n < 2){
        return 2;
    }

    int prime = n;
    bool found = false;
    while(!found){
        prime++;
        if(isPrime(prime)){
            found = true;
        }
    }
    return prime;
}