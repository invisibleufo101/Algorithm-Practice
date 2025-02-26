#include <bits/stdc++.h>
using namespace std;
int n;
string str;

bool check(string s){
    int letters[26];

    for (int i=0; i<s.length(); i++){
        char c = s[i];

        if (i > 0 && s[i] != s[i-1] && letters[c - 'a']) return false;
        letters[c - 'a']++;
    }

    return true;
}

int main(){
    cin >> n;

    int cnt = 0;
    for (int i=0; i<n; i++){
        cin >> str;
        if (check(str)){
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}