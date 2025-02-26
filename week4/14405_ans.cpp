#include <bits/stdc++.h>
using namespace std;
string s;

bool solve(string str){
    string tmp = "";
    for (int i=0; i<str.size(); i++){
        tmp += str[i];
        if (tmp == "pi" || tmp == "ka" || tmp == "chu"){
            tmp = "";
        }
    }

    if (tmp.empty()) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> s;
    
    bool flag = 0;
    for (int i=0; i<s.size(); i++){
        if (i < s.size() - 1 && (s.substr(i, 2) == "pi" || s.substr(i,2) == "ka")){
            i += 1;
        } else if (i < s.size() - 2 && s.substr(i, 3) == "chu"){
            i += 2;
        } else {
            flag = 1;
        }
    }

    if (flag) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}