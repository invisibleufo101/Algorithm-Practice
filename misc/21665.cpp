#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
char arr[101][101];
char wrng[101][101];
char rght[101][101];

char flip(char c){
    if (c == 'W') return 'B';
    else return 'W';
}

void print(char a[101][101]){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin >> n >> m;
    int cnt = 0;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            arr[i][j] = s[j];
            rght[i][j] = flip(s[j]);
        }
    }

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            wrng[i][j] = s[j];
            if (wrng[i][j] != rght[i][j]) cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}