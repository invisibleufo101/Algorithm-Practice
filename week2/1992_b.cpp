#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[65][65];

bool check(int s, int y, int x) {

    int val = arr[y][x];

    for (int i = y; i < y+s; i++) {
        for (int j = x; j < x+s; j++) {
            cout << arr[i][j] << " ";

            if (val != arr[i][j]){
                return false;
            }
        }
        cout << "\n";
    }

    return true;
}

void divide(int s, int y, int x) {
    
    if (check(s, y, x)){
        cout << arr[y][x];
    } else {
        cout << "(";
        int ns = s / 2;
        for (int i = y; i < y + s; i += ns) {
            for (int j = x; j < x + s; j += ns) {
                divide(ns, i, j);
            }
        }
        cout << ")";
    }
}

int main()
{
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<n; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    divide(n, 0, 0);
    
    return 0;
}