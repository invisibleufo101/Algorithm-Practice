#include <bits/stdc++.h>
using namespace std;
int n, numer, denom;

int main(){
    cin >> n;

    int cnt = 1;
    while (n > cnt){
        n -= cnt;
        cnt++;
    }

    if (cnt % 2 == 0){
        numer = n;
        denom = cnt - n + 1;
    } else if (cnt % 2 == 1){
        numer = cnt - n + 1;
        denom = n;
    }

    cout << numer << "/" << denom << "\n";

    return 0;
}
