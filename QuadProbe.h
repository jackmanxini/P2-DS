#include <iostream>
#include <cmath>
#include <cctype>
#include <regex>

using namespace std;

struct Node{
    string word;
    Node *nPtr;
};

class QuadProbe{
    private:
        int table_size;
        Node **table;

    public:
        QuadProbe(int);
        int hashfunction(string&);
        void insert(string);
        string search(string);
        bool isPrime(int n);
        int nextPrime(int n);
};

