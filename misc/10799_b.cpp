#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    cin >> s;
    stack<char>stck;
    int cnt = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i] == '('){
            stck.push(s[i]);
        } else if (s[i] == ')'){

            // If laser
            if (s[i-1] == '('){
                stck.pop();
                cnt += stck.size();
            
            // If end of stick
            } else {
                stck.pop();
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}