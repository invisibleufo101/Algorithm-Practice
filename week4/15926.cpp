#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[200002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;

    char c; int idx;
    stack<pair<char,int>>stck;

    for (int i=0; i<n; i++){
        if (stck.size()){
            tie(c, idx) = stck.top();
            if (c == '(' && s[i] == ')'){
                stck.pop();
                continue;
            }
        }

        stck.push({s[i], i});
    }

    while(stck.size()){
        tie(c, idx) = stck.top();

        arr[idx] = 1;

        stck.pop();
    }

    
    int cnt = 0;
    int ret = 0;
    for (int i=0; i<n; i++){
        if (arr[i]){
            ret = max(ret, cnt);
            cnt = 0;
        } else if (arr[i] == 0) {
            cnt++;
        }
    }

    ret = max(ret, cnt);

    cout << ret << "\n";

    return 0;
}

// 13
// ()()((((())))
// Ans: 8

// 10
// ()()((()))
// Ans: 10