#include<iostream>
#include <vector>
using namespace std;
const int MAXI = 100;
int i, j,k;


vector<int> marblegame(vector<vector<int>> m,vector<int> c1) {
    vector<int> c2(c1.size());
    for (i = 0; i < c1.size(); i++) {
        for (j = 0; j < c1.size(); j++){
            c2[i] = m[i][j] * c1[j]+c2[i];
        }
    }

    return c2;
}

int main() {
    _resetstkoflw;
    int size1;
    cin >> size1;
    vector<vector<int> > m(size1, vector<int>(size1));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size1; j++) {
            cin>>m[i][j];
        }
        cout << endl;
    }
    vector<int> c1(size1);
    for (i = 0; i < size1; i++) {
        cin >> c1[i];
    }
    vector<int> c2(size1);
    c2 = c1;
    int times;
    cin >> times;
    for (i = 0; i < times; i++) {
        c2 = marblegame(m, c2);
    }
    cout << endl;
    cout << endl;
    for (i = 0; i < size1; i++) {
        cout << c2[i]<<endl;
    }

    return 0;
}