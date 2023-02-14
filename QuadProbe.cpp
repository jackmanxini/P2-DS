#include "QuadProbe.h"


QuadProbe::QuadProbe(int size){
    table_size = size;
    table = new Node*[table_size];

    for (int i = 0; i < table_size; i++){
        table[i] = nullptr;
    }
}

int QuadProbe::hashfunction(string &word){
    int key = 0;
    for (char ch : word){
        key = 37*key+ch;
    }
    
    return key % table_size;
}

void QuadProbe::insert(string word) {
  int index = hashfunction(word);

  for (int i = 1; i < table_size; i++) {
    if (table[index] == nullptr) {
      Node *newNode = new Node();
      newNode->word = word;
      table[index] = newNode;
      break;
    } else {
      index = (index + i * i) % table_size;
    }
  }
}

string QuadProbe::search(string word){
    int index = hashfunction(word);

    for (int i = 1; i < table_size; i++) {
        if (table[index] == nullptr) {
            return "WNF";
        } else if (table[index]->word == word) {
            return table[index]->word;
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