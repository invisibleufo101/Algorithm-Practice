#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a,b;

lli euclidean(lli a, lli b){
    lli ret = a % b;
    if (ret == 0){
        return b;
    }
    return euclidean(b, ret);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;

    lli cmns = euclidean(a,b);
    lli ret = (a / cmns) * (b / cmns) * cmns;

    cout << ret << "\n";

    return 0;
}