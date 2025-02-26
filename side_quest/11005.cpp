#include <bits/stdc++.h>
using namespace std;
long long n;
int b;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> b;
    while (n > 1){
        v.push_back(n % b);
        n /= b;
    }

    if (n == 1) v.push_back(1);
    reverse(v.begin(), v.end());

    for (int i : v){
        if (i >= 10) cout << char(i + 55);
        else cout << i;
    }

    return 0;
}