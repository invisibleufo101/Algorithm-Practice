#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;

    long long ret = pow(pow(2,n)+1, 2);
    cout << ret << "\n";

    return 0;
}