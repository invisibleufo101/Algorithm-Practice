#include <bits/stdc++.h>
using namespace std;
string s;

string check(string str){
    stack<char>stk;

    for (int i=0; i<str.length(); i++){

        char c = str[i];

        if (c != '(' && c != ')' && c != '[' && c != ']') {
            continue;
        }

        if (stk.size() && c == ')' && stk.top() == '('){
            stk.pop();
        } else if (stk.size() && c == ']' && stk.top() == '['){
            stk.pop();
        } else {
            stk.push(c);
        }
        
    }

    if (stk.size()){
        return "no";
    } 
    return "yes";
}

int main(){

    while (getline(cin, s) && s != "."){

        cout << check(s) << "\n";
    }
    return 0;
}