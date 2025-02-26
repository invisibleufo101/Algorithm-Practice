#include <bits/stdc++.h>
using namespace std;
int n,op;
int mx = -1000000002, mn = 1000000002;
int arr[12], visited[12];
int ops[4];
vector<char>v;

int calculate(vector<char>t){
    int ret = arr[0];

    for (int i=1; i<n; i++){
        if (t[i-1] == '+') ret = ret + arr[i];
        else if (t[i-1] == '-') ret = ret - arr[i];
        else if (t[i-1] == '*') ret = ret * arr[i];
        else if (t[i-1] == '/') ret = ret / arr[i];
    }

    return ret;
}

void solve(int cnt){
    if (cnt == n-1){
        int buffer = calculate(v);
        mx = max(mx, buffer);
        mn = min(mn, buffer);
        return;
    }

    for (int i=0; i<4; i++){
        if (ops[i] == 0) continue;

        if (i == 0) v.push_back('+');
        else if (i == 1) v.push_back('-');
        else if (i == 2) v.push_back('*');
        else if (i == 3) v.push_back('/');

        ops[i]--;

        solve(cnt+1);

        v.pop_back();
        ops[i]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    for (int i=0; i<4; i++){
        cin >> ops[i];
    }

    solve(0);
    cout << mx << "\n" << mn << "\n";

    return 0;
}