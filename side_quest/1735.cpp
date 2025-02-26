#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli numerator1, denominator1, numerator2, denominator2;

lli euclidean(lli a, lli b){
    lli ret = a % b;
    if (ret == 0){
        return b;
    }
    return euclidean(b, ret);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> numerator1 >> denominator1 >> numerator2 >> denominator2;

    lli _gcd = euclidean(denominator1, denominator2) ;
    lli ret_denom = _gcd * (denominator1 / _gcd) * (denominator2 / _gcd);
    lli ret_numer = (ret_denom / denominator1) * numerator1 + (ret_denom / denominator2) * numerator2;

    lli tmp = euclidean(ret_numer, ret_denom);
    if (tmp == 1){
        cout << ret_numer << " " << ret_denom << "\n";
    } else {
        ret_numer /= tmp;
        ret_denom /= tmp;

        cout << ret_numer << " " << ret_denom << "\n";
    }

    return 0;
}