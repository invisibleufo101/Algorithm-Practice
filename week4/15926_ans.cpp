#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[200002];
int ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;

    stack<int>stck;
    for (int i=0; i<n; i++){
        if (s[i] == '('){
            // Store the idx
            stck.push(i);
        } else if (stck.size() && s[i] == ')'){

            // If the bracket is properly closed 
            // then mark both the indexes of 
            // starting point and the ending point as 1

            arr[i] = 1;
            arr[stck.top()] = 1;

            stck.pop();
        }
    }

    int cnt = 0;
    for (int i=0; i<n; i++){
        if (arr[i] == 1){
            cnt++;
        } else if (arr[i] == 0){
            ret = max(ret, cnt);
            cnt = 0;
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