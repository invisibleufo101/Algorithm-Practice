#include <bits/stdc++.h>
using namespace std;
long long n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    long long ret = (n * (n-2) * (n-1)) / 6;
    cout << ret << "\n" << 3 << "\n";

    return 0;
}