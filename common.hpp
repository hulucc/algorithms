/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Mar 2017 02:23:58 AM UTC
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

#include<iostream>
using namespace std;

template <typename T>
void print(T* plist, int len) {
    for(int i = 0; i < len; i++) {
        cout << plist[i] << " ";
    }
    cout << endl;
}
#endif
