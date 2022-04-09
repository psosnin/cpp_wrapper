#include <iostream>
#include <math.h>
#include <vector>
#include "example.hpp"

using namespace std;

MyClass::MyClass() {
    cout << "hello world" << endl;
}

int MyClass::square(int x) {
    return x*x;
}

vector<int> MyClass::returnList() {
    return {1, 2, 3, 4};
}

int MyClass::sum(vector<int> v) {
    int sum = 0;
    for (int i : v) {
        sum += i;
    }
    return sum;
}

int exampleFunction() {
    return 1203;
}