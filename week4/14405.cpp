#include <bits/stdc++.h>
using namespace std;
string s;

bool solve(string str) {

    map<string,int>mp;

    mp["pi"] = 1;
    mp["ka"] = 1;
    mp["chu"] = 1;
    
    string temp = "";
    for (int i=0; i<str.length(); i++){

        temp += str[i];

        if (mp.find(temp) != mp.end()){
            temp = "";
        } 
    }
    
    if (temp.length() == 0) return true;

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    if (solve(s)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}