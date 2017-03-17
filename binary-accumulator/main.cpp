/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Mar 2017 12:28:58 PM CST
 ************************************************************************/

#include<iostream>
#include <array>
#include "../common.hpp"
using namespace std;

template<typename T>
T binary_accumulator(T a, T b, T& flag) {
    T sum = a + b + flag;
    flag = sum / 2;
    return sum % 2;
}

template <size_t N>
using binary = array<int, N>;

binary<9> binary_add(binary<8> k1, binary<8> k2) {
    binary<9> result;
    int flag = 0;
    for(int i = k1.size() - 1; i >= 0; i--) {
        result[i + 1] = binary_accumulator(k1[i], k2[i], flag);
    }
    result[0] = flag;
    return result;
}

int main() {
    binary<8> k1 = { 1, 1, 1, 1, 1, 1, 1, 1 };
    binary<8> k2 = { 1, 1, 1, 1, 1, 1, 1, 1 };
    auto result = binary_add(k1, k2);
    print(k1.data(), k1.size());
    print(k2.data(), k2.size());
    print(result.data(), result.size());
    return 0;
}
