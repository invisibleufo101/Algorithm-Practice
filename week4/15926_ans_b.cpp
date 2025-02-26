#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;

    stack<int>stck;
    stck.push(-1);

    for (int i=0; i<n; i++){
        if (s[i] == '('){
            stck.push(i);
        }

        if (s[i] == ')'){
            stck.pop();
            if (stck.size()){
                ret = max(ret, i - stck.top());
            } else {
                stck.push(i);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}