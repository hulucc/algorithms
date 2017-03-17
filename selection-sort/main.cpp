/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Mar 2017 02:42:20 PM CST
 ************************************************************************/

#include<iostream>
#include<array>
#include "../common.hpp"
using namespace std;

void selection_sort(int *plist, int len) {
    for(int i = 0; i < len; i++) {
        int min = i;
        for(int j = i; j < len; j++) {
            if(plist[j] < plist[min])
                min = j;
        }
        swap(plist[min], plist[i]);
    }
}

int main() {
    array<int, 8> normal = { 5, 8, 4, 7, 6, 2, 0, 9 };
    selection_sort(normal.data(), normal.size());
    print(normal.data(), normal.size());
}
