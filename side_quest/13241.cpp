#include <bits/stdc++.h>
using namespace std;
long long int a,b;

long long int getGCD(long long int a, long long int b){
    long long int ret = min(a,b);
    while (ret > 0){
        if (a % ret == 0 && b % ret == 0) break;
        ret--;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    long long int cmns = getGCD(a,b);
    long long int ret = (a / cmns) * (b / cmns) * cmns;
    cout << ret << "\n";
    
    return 0;
}