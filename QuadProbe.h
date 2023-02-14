#include <iostream>
#include <cmath>
#include <cctype>
#include <regex>
#include <string>


using namespace std;

class QuadProbe{
    private:
        int table_size;
        string* table;
    public:
        QuadProbe(int);
        int hashfunction(string&);
        void insert(string);
        string search(string);
        bool isPrime(int n);
        int nextPrime(int n);
};

