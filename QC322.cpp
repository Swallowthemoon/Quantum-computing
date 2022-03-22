#include<iostream>
#include <vector>
#include <math.h>
using namespace std;
const int MAXI = 100;
int i, j,k;


vector<vector<double>> multy(vector<vector<double>>m1, vector<vector<double>>m2) {
    vector<vector<double>>m3 (m1.size(),vector<double>(m1.size()));
    for (i = 0; i < m1.size(); i++) {
        for (j = 0; j < m1.size(); j++) {
            for (k = 0; k < m1.size(); k++) {
                m3[i][j] = m1[i][k] * m2[k][j] + m3[i][j];
            }
        }
    }
    return m3;
}

vector<double> marblegame(vector<vector<double>> m,vector<double> c1) {
    vector < double > c2(c1.size());
    for (i = 0; i < c1.size(); i++) {
        for (j = 0; j < c1.size(); j++){
            c2[i] = m[i][j] * c1[j]+c2[i];
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
    vector<vector<double> > m(size, vector <double> (size));
    for (i = 1; i < numofslits+1; i++) {
        m[i][0] = 1/double(numofslits);
    }
    for (i = numofslits + 1; i < size; i++) {
        cin >> m[i][1]>>m[i][2];
    }
    for (i = 0; i < numoftargets;i++) {
        m[i + 1 + numofslits][i + 1 + numofslits] = 1;
    }

    for (i=0; i < size; i++) {
        for (j = 0; j < size; j++) {
            cout << m[i][j]<<"    ";
        }
        cout << endl;
    }

    vector<double> c1(size);
    for (i = 0; i < size; i++) {
        cin >> c1[i];
    }
    vector<double> c2(size);
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
        cout << c2[i]<<endl;
    }

    return 0;
}