/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Mar 2017 02:06:58 AM UTC
 ************************************************************************/

#include <iostream>
#include <array>
#include "../common.hpp"
using namespace std;

void insertion_sort(int *plist, int len) {
    if(len <= 1)
        return;
    if(plist == nullptr)
        return;
    for(int i = 1; i < len; i++) {
        int key = plist[i];
        int j = i;
        while(j > 0 && key < plist[j - 1]) {
            plist[j] = plist[j - 1];
            j--; 
        }
        plist[j] = key;
    }
}

int main() {
    array<int, 9> normal = {8, 7, 5, 5, 6, 1, 0, 2, 9};
    insertion_sort(normal.data(), normal.size());
    print(normal.data(), normal.size());
    return 0;
}
