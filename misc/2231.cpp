#include <bits/stdc++.h>
using namespace std;
int n;
string tmp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    tmp = to_string(n);
    if (tmp.length() == 1 && n % 2 == 1){
        cout << 0 << "\n";
        return 0;
    }

    int iter=1;
    bool flag = 0;
    while(iter <= 1000000){
        int t = iter;
        int sum = iter;

        while(t > 0){
            sum += (t % 10);
            t /= 10;
        }

        if (sum == n){
            cout << iter << "\n";
            break;
        }

        iter++;
        if (iter == 1000000) flag = 1;
    }

    if (flag) cout << 0 << "\n";

    return 0;
}

// 1000000