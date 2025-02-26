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
            stck.push(i);
        }

        if (stck.size() && s[i] == ')'){

            arr[i] = 1;
            arr[stck.top()] = 1;

            stck.pop();
        }
    }

    int cnt = 0;
    for (int i=0; i<n; i++){
        if (arr[i]){
            cnt++;
            ret = max(ret, cnt);
        } else {       
            cnt = 0;
        }
    }

    cout << ret << "\n";

    return 0;
}