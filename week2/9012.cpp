#include <bits/stdc++.h>
using namespace std;
int t;
string vps;

string check(string str){
    stack<char>stk;
    for (int i=0; i<str.length(); i++){
        char c = str[i];

        if (stk.size() && c == ')' && stk.top() == '('){
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    if (stk.size()){
        return "NO";
    }
    return "YES";
}

int main(){
    cin >> t;
    while (t--){
        cin >> vps;

        cout << check(vps) << "\n";
    }
    return 0;
}