/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Mar 2017 04:39:47 PM CST
 ************************************************************************/

#include<iostream>
#include <array>
using namespace std;

//[a, b]
int binary_search(int *plist, int a, int b, int x) {
    if(a > b)
        return -1;
    int m = (a + b) / 2;
    if(x < plist[m])
        return binary_search(plist, a, m - 1, x);
    else if(x > plist[m])
        return binary_search(plist, m + 1, b, x);
    else
        return m;
}

int binary_search_iteration(int *plist, int len, int x) {
    int a = 0;
    int b = len - 1;
    while(a < b) {
        int m = (a + b) / 2;
        if(x < plist[m])
            b = m - 1;
        else if(x > plist[m])
            a = m + 1;
        else {
            return m;
        }
    }
    return -1;
}

int main() {
    array<int, 8> normal = { 1, 3, 4, 5, 6, 8, 10 };
    int x1 = 3, x2 = 2;
    int i1 = binary_search(normal.data(), 0, normal.size() - 1, x1);
    int i2 = binary_search(normal.data(), 0, normal.size() - 1, x2);
    int i3 = binary_search_iteration(normal.data(), normal.size(), x1);
    int i4 = binary_search_iteration(normal.data(), normal.size(), x2);
    cout << x1 << " pos: " << i1 << endl;
    cout << x2 << " pos: " << i2 << endl;
    cout << x1 << " pos: " << i3 << endl;
    cout << x2 << " pos: " << i4 << endl;
}
