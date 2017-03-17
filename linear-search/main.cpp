/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Mar 2017 11:53:56 AM CST
 ************************************************************************/

#include<iostream>
#include <array>
#include "../common.hpp"
using namespace std;

int linear_search(int *plist, int len, int x) {
    if(plist == nullptr || len <= 0)
        return -1;
    for(int i = 0; i < len; i++) {
        if(plist[i] == x)
            return i;
    }
    return -1;
}

int main() {
    array<int, 8> normal = { 8, 5, 9, 1, 0, 6, 7, 4 };
    int x1 = 6;
    int x2 = 2;
    int i1 = linear_search(normal.data(), normal.size(), x1);
    int i2 = linear_search(normal.data(), normal.size(), x2);
    print(normal.data(), normal.size());
    cout << x1 << " pos: " << i1 << endl;
    cout << x2 << " pos: " << i2 << endl;
    return 0;
}
