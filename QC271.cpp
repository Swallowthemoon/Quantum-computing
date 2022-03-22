#include<iostream>
#include <vector>
using namespace std;
const int MAXI = 100;
int i, j,k;
typedef struct complex {
    double a;
    double b;
};


complex mult(complex c1, complex c2) {
    complex d;
    d.a = c1.a * c2.a - c1.b * c2.b;
    d.b = c1.a * c2.b + c2.a * c1.b;
    return d;
}

complex plus1(complex c1, complex c2) {
    complex d;
    d.a = c1.a + c2.a;
    d.b = c1.b + c2.b;
    return d;
}

vector<vector<complex>>tensorproduct(vector<vector<complex> > c1, vector<vector<complex> > c2) {
    vector<vector<complex>> c3(c1.size() * c2.size(), vector<complex>(c1.size() * c2.size()));
    for (i = 0; i < c3.size(); i++) {
        for (j = 0; j < c3.size(); j++) {
            c3[i][j] = mult(c1[i / c2.size()][j / c2.size()],c2[i%c2.size()][j % c2.size()]);
        }
    }
    return c3;
}

int main() {
    _resetstkoflw;
    int size1;
    cin >> size1;
    vector<vector<complex> > c1(size1, vector<complex>(size1));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size1; j++) {
            cin >> c1[i][j].a >> c1[i][j].b;

        }
        cout << endl;
    }
    int size2;
    cin >> size2;
    vector<vector<complex> > c2(size2, vector<complex>(size2));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size1; j++) {
            cin >> c2[i][j].a >> c2[i][j].b;

        }
        cout << endl;
    }
    vector<vector<complex>> c3;
    c3 = tensorproduct(c1, c2);
    for (i = 0; i < size1 * size2; i++) {
        for (j = 0; j < size1 * size2; j++) {
            cout <<"(" << c3[i][j].a <<"," << c3[i][j].b<<")";
        }
        cout << endl;
    }
    return 0;
}