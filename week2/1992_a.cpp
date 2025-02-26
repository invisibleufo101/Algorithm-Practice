#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char arr[101][101];

void print(char a[65][65]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

string solve(int s, int y, int x){
    if (s == 1){
        return string(1, arr[y][x]);
    }

    char val = arr[y][x];
    string ret = "";
    for (int i=y; i<y+s; i++){
        for (int j=x; j<x+s; j++){
            if (val != arr[i][j]){
                ret += "(";

                // 1st Quadrant
                ret += solve(s/2, y, x);
                // 2nd Quadrant
                ret += solve(s/2, y, x+s/2);
                // 3rd Quadrant
                ret += solve(s/2, y+s/2, x);
                // 4th Quadrant
                ret += solve(s/2, y+s/2, x+s/2);

                ret += ")";
                return ret;
            }
        }
    }
    return string(1, arr[y][x]);
}

int main(){
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<n; j++){
            arr[i][j] = s[j];
        }
    }

    cout << solve(n, 0, 0) << "\n";

    return 0;
}