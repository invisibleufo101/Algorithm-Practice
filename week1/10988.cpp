#include<bits/stdc++.h>
using namespace std;
string str, tmp;

int main(){
    cin >> str;
    tmp = str;
    reverse(tmp.begin(), tmp.end());
    if (tmp == str) cout << 1 << "\n";
    else cout << 0 << "\n";
    return 0;
}