/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Mar 2017 02:29:51 PM CST
 ************************************************************************/

#include<iostream>
#include<array>
#include "../common.hpp"
using namespace std;

void bubble_sort(int *plist, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(plist[j] < plist[i])
                swap(plist[i], plist[j]);
        }
    }
}

int main() {
    array<int, 8> normal = { 4, 6, 1, 3, 9, 8, 6, 2 };
    bubble_sort(normal.data(), normal.size());
    print(normal.data(), normal.size());
}

