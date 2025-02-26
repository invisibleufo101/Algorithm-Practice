#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    cin >> n >> s;
    int sum = 0;
    for (int i=0; i<n; i++){
        int x = s[i] - '0';
        sum += x;
    }
    cout << sum << "\n";
    return 0;
}