#include "expressions.h"
using namespace std;

List::List(int x) {
    add(x);
}

void List::add(int x) {
    list.push_back(x);
}

void List::print() {
    for (auto i : list)
        cout << i << " ";
    cout << endl;
}

List::~List() {
    list.clear();
}