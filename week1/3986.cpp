#include<bits/stdc++.h>
using namespace std;
int n;
string wrd;
int cnt = 0;

int main(){
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> wrd;
        stack<char>stk;
        for (int j=0; j<wrd.length(); j++){

            if (!stk.empty() && stk.top() == wrd[j]){
                stk.pop();
                continue;
            }

            stk.push(wrd[j]);
        }

        if (stk.size() == 0) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}