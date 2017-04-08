/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Mar 2017 03:51:26 PM CST
 ************************************************************************/

#include<iostream>
#include <memory>
#include <cassert>
#include <iomanip>
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
        m_matrix = shared_ptr<int>(new int[n * n], default_delete<int[]>());
        //m_matrix = unique_ptr<int[]>(new int[n * n]);
        m_n = n;
        m_size = n;
        m_orginx = 0;
        m_orginy = 0;
    }
    size_t size() const{
        return m_n;
    }

    int& at(int x, int y) const {
        assert(x >= 0 && x < m_n && y >= 0 && y < m_n);
        return *(m_matrix.get() + (m_orginx + x) * m_size + (m_orginy + y));
    }
    matrix submatrix(int orginx, int orginy, int n) {
        assert(orginx >= 0 && orginy >= 0 && n > 0);
        assert(orginx + n <= m_n && orginy + n <= m_n);
        matrix sub = *this;
        sub.m_orginx = m_orginx + orginx;
        sub.m_orginy = m_orginy + orginy;
        sub.m_n = n;
        return sub;
    }
    matrix operator+(const matrix& other) const {
        assert(m_n == other.size());
        matrix c(m_n);
        for(int i = 0; i < m_n; i++) {
            for(int j = 0; j < m_n; j++) {
                c.at(i, j) = at(i, j) + other.at(i, j);
            }
        }
        return c;
    }
    matrix operator-(const matrix& other) const {
        assert(m_n == other.size());
        matrix c(m_n);
        for(int i = 0; i < m_n; i++) {
            for(int j = 0; j < m_n; j++) {
                c.at(i, j) = at(i, j) - other.at(i, j);
            }
        }
        return c;
    }
    void print() const {
        for(int i = 0; i < m_n; i++) {
            for(int j = 0; j < m_n; j++) {
                cout << setfill(' ') << setw(4) << at(i, j);
            }
            cout << endl;
        }
        cout << endl;
    }
private:
    size_t m_n;
    size_t m_size;
    int m_orginx;
    int m_orginy;
    shared_ptr<int> m_matrix;
    //unique_ptr<int[]> m_matrix;
};

void strassen(int *a, int *b, int *c, int n) {

}

int main() {
    matrix a(3), b(3);
    a.at(1, 1) = 7;
    b.at(0, 0) = 1;
    b.at(1, 1) = 5;
    auto c = a + b;
    auto d = c.submatrix(1, 1, 2);
    c.at(1, 1) = 5;
    c.print();
    d.print();
    return 0;
}
