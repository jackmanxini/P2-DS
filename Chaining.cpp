#include "Chaining.h"



Chaining::Chaining(int size){
    table_size = size;

    table = new chain_node*[table_size];

    for (int i = 0; i < table_size; i++){
        table[i] = nullptr;
    }
}

int Chaining::hashfunction(string &word){
    int key = 0;
    for (char ch : word){
        key = 37*key+ch;
    }
    
    return key % table_size;
}

void Chaining::insert(string word){
    int index = hashfunction(word);
    chain_node *insertNode = new chain_node();
    insertNode->word = word;
    insertNode->nPtr = table[index];
    table[index] = insertNode;
}

string Chaining::search(string word){
    int index = hashfunction(word);
    chain_node *temp = table[index];
    while(temp != nullptr){
        if(temp->word == word){
            return temp->word;
        }
        temp = temp->nPtr;
    }
    return "WNF";
}

bool Chaining::isPrime(int n){
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

int Chaining::nextPrime(int n){
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
