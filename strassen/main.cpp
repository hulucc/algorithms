/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Mar 2017 03:51:26 PM CST
 ************************************************************************/

#include<iostream>
#include <memory>
#include <cassert>
using namespace std;
//best practice for smart point
//http://stackoverflow.com/questions/28294620/what-is-the-best-smart-pointer-return-type-for-a-factory-function
//http://stackoverflow.com/questions/13061979/shared-ptr-to-an-array-should-it-be-used
//http://stackoverflow.com/questions/15648844/using-smart-pointers-for-class-members
//https://katyscode.wordpress.com/2012/10/04/c11-using-stdunique_ptr-as-a-class-member-initialization-move-semantics-and-custom-deleters/
//http://stackoverflow.com/questions/13125632/when-does-move-constructor-get-called
//http://stackoverflow.com/questions/18290523/does-a-default-move-constructor-equals-to-a-member-wise-move-constructor
class matrix {
public:
    matrix(int n) {
        m_matrix = unique_ptr<int[]>(new int[n * n]);
        m_n = n;
    }
    matrix(const matrix& m) = delete;
    matrix& operator=(const matrix& m) = delete;
    matrix(matrix&& m) {
        if(this != &m)
            m_matrix = move(m.m_matrix);
        cout << "move ctor called" << endl;
    }
    matrix& operator=(matrix&& m) {
        if(this != &m)
            m_matrix = move(m.m_matrix);
        cout << "= move ctor called" << endl;
        return *this;
    }
    size_t size() {
        return m_n;
    }
    int& at(int x, int y) {
        assert(x < m_n && y < m_n);
        return *(m_matrix.get() + y * m_n + x);
    }
    matrix create(bool cond) {
        matrix r(m_n);
        matrix s(m_n);
        if(cond)
            return r;
        else
            return s;
    }
private:
    size_t m_n;
    unique_ptr<int[]> m_matrix;
};

void strassen(int *a, int *b, int *c, int n) {

}

int main() {
    matrix m(3);
    m.at(1, 1) = 7;
    cout << m.at(1, 1) << endl;
    auto a = m.create(false);
    cout << a.at(1, 1) << endl;
    return 0;
}
