#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;

    unsigned long long int ret = 0;
    for (int i=1; i<n; i++){
        ret += i;
    }

    cout << ret << "\n" << 2 << "\n";
    
    return 0;
}