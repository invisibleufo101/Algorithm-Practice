#include <bits/stdc++.h>
using namespace std;
int n, temp, mx = -1;
int cnt = 0;
vector<int>v;

void go(int idx, int sum){

    if (mx % 11 == 10) return;

    if (idx == n){

        // if (sum % 11 != 10) return;

        cnt++;
        mx = max(mx, sum % 11);
        return;
    }

    go(idx + 1, sum + v[idx]);
    go(idx + 1, sum);

    return;
}

int main(){
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    go(0,0);

    cout << mx << "\n";
    cout << "Function ran: " << cnt << " time(s)\n";

    return 0;
}
// 10
// 24 35 38 40 49 59 60 67 83 98