#include<iostream>
#include <vector>
#include <math.h>
using namespace std;
const int MAXI = 100;
int i, j,k;

typedef struct complex {
    double a;
    double b;
};

complex plus1(complex c1, complex c2) {
    complex d;
    d.a = c1.a + c2.a;
    d.b = c1.b + c2.b;
    return d;
}

complex mult(complex c1, complex c2) {
    complex d;
    d.a = c1.a * c2.a - c1.b * c2.b;
    d.b = c1.a * c2.b + c2.a * c1.b;
    return d;
}


vector<vector<complex>> multy(vector<vector<complex>>m1, vector<vector<complex>>m2) {
    vector<vector<complex>>m3 (m1.size(),vector<complex>(m1.size()));
    for (i = 0; i < m1.size(); i++) {
        for (j = 0; j < m1.size(); j++) {
            for (k = 0; k < m1.size(); k++) {
                m3[i][j] = plus1(mult(m1[i][k] , m2[k][j]) , m3[i][j]);
            }
        }
    }
    return m3;
}

vector<complex> marblegame(vector<vector<complex>> m,vector<complex> c1) {
    vector < complex > c2(c1.size());
    for (i = 0; i < c1.size(); i++) {
        for (j = 0; j < c1.size(); j++){
            c2[i] = plus1(mult( m[i][j] , c1[j]) , c2[i]);
        }
    }

    return c2;
}

int main() {
    _resetstkoflw;
    int numofslits;
    int numoftargets;
    cin >> numofslits;
    cin >> numoftargets;
    int size = numofslits + numoftargets+1;
    vector<vector<complex> > m(size, vector <complex> (size));
    for (i = 1; i < numofslits+1; i++) {
        m[i][0].a = 1/sqrt(double(numofslits));
        m[i][0].b = 0;
    }
    for (i = numofslits + 1; i < size; i++) {
        cin >> m[i][1].a>>m[i][1].b;
        cin >> m[i][2].a >> m[i][2].b;
    }
    for (i = 0; i < numoftargets;i++) {
        m[i + 1 + numofslits][i + 1 + numofslits].a = 1;
        m[i + 1 + numofslits][i + 1 + numofslits].b = 0;
    }

    for (i=0; i < size; i++) {
        for (j = 0; j < size; j++) {
            cout <<"("<< m[i][j].a << ","<<m[i][j].b<<")";
        }
        cout << endl;
    }

    vector<complex> c1(size);
    for (i = 0; i < size; i++) {
        cin >> c1[i].a>>c1[i].b;
    }
    vector<complex>c2(size);
    c2 = c1;
    int times;
    cin >> times;
    for (i = 0; i < times; i++) {
        m = multy(m, m);
    }
    c2 = marblegame(m, c1);
    cout << endl;
    cout << endl;
    for (i = 0; i < size; i++) {
        cout << "(" << c2[i].a <<"," <<c2[i].b<<")"<< endl;
    }

    return 0;
}