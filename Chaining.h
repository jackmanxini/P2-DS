#include <iostream>
#include <cctype>
#include <cmath>
#include <regex>

using namespace std;

struct chain_node{
    string word;
    chain_node *nPtr;
};

class Chaining{
    private:
        int table_size;
        chain_node **table;

    public:
        Chaining(int);
        int hashfunction(string&);
        void insert(string);
        string search(string);
        bool isPrime(int n);
        int nextPrime(int n);
};