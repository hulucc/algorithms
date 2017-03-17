/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Mar 2017 03:12:46 PM CST
 ************************************************************************/

#include <iostream>
#include <array>
#include <vector>
#include "../common.hpp"
using namespace std;

//[a, m] [m + 1, b]
void merge(int *plist, int a, int m, int b) {
    vector<int> l1(plist + a, plist + m + 1);
    vector<int> l2(plist + m + 1, plist + b + 1);
    int i = 0, j = 0, k = a;
    while(i < l1.size() && j < l2.size()) {
        if(l1[i] < l2[j])
            plist[k++] = l1[i++];
        else
            plist[k++] = l2[j++];
    }
    while(i < l1.size())
        plist[k++] = l1[i++];
    while(j < l2.size())
        plist[k++] = l2[j++];
}
//[a, b]
void merge_sort(int *plist, int a, int b) {
    if(b - a <= 0)
        return;
    int m = (a + b) / 2;
    merge_sort(plist, a, m);
    merge_sort(plist, m + 1, b);
    merge(plist, a, m, b);
}

int main() {
    array<int, 8> normal = {5, 7, 3, 1, 8, 9, 2, 4};
    merge_sort(normal.data(), 0, normal.size() - 1);
    print(normal.data(), normal.size());
    return 0;
}
