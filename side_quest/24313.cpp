#include <bits/stdc++.h>
using namespace std;
int a1, a0;
int c, n;

bool solve(int a1, int a0, int c, int n0){
    for (int i=n0; i<=100; i++){
        if (!(a1*i + a0 <= c * i)){
            return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a1 >> a0 >> c >> n;

    cout << solve(a1, a0, c, n) << "\n";

    return 0;
}