#include <iostream>
#include <vector>
#include <string>

using namespace std;
class List {
    vector<int> list;
    public:
    List(int x);
    void add(int x);
    void print();
    ~List();
};

class Str {
    string str;
    public:
        Str(const char* s) {str = string(s);}
        Str operator + (Str & s)
        {
            Str res = *this;
            res.str = str + s.str;
            return res;
        }
        ~Str() {str.clear();}
        void print() {cout << str;}
};

