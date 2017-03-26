/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Mar 2017 05:40:15 PM CST
 ************************************************************************/

#include<iostream>
#include <array>
#include <assert.h>
using namespace std;


int maximum_subarray(int *plist, int len) {
    if(len <= 0)
        return 0;
    int sum = 0, max = plist[0];
    int start, = 0, maxstart = 0, maxend = 0;
    for(int i = 0; i < len; i++) {
        sum += plist[i];
        if(sum > max) {
            max = sum;
            maxstart = start;
            maxend = i;
        }
        if(sum < 0) {
            sum = 0;
            start = i + 1;
        }
    }
    cout << "start: " << maxstart << " end: " << maxend << " max: " << max << endl;
    return max;
}

//[a, m] [m+1, b]
int find_max_crossing_subarray(int *plist, int a, int b, int m) {
    int sum = 0, max = 0;
    for(int i = m; i >= a; i--) {
        sum += plist[i];
        if(sum > max)
            max = sum;
    }
    sum = max;
    for(int i = m + 1; i <= b; i++) {
        sum += plist[i];
        if(sum > max)
            max = sum;
    }
    return max;
}

int maximum_subarray2(int *plist, int a, int b) {
    assert(a <= b);
    if(a == b)
        return plist[a];
    int m = (a + b) / 2;
    int maxa = maximum_subarray2(plist, a, m);
    int maxb = maximum_subarray2(plist, m + 1, b);
    int maxm = find_max_crossing_subarray(plist, a, b, m);
    int max = maxa > maxb ? maxa : maxb;
    max = max > maxm ? max : maxm;
    return max;
}


int main() {
    array<int, 16> stock = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7  };
    array<int, 3> ex = { -2, -1, -3 };
    maximum_subarray(stock.data(), stock.size());
    maximum_subarray(ex.data(), ex.size());
    int max = maximum_subarray2(stock.data(), 0, stock.size() - 1);
    cout << max << endl;
}
