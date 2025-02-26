#include <bits/stdc++.h>
using namespace std;
int m,n;
vector<int>v;

bool isPrime(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i=3; i*i<=n; i++){
        if (n % i == 0) return 0;
    }

    return 1;
}

int main(){
    cin >> m >> n;
    for (int i=m; i<=n; i++){
        if (isPrime(i)){
            v.push_back(i);
        }
    }

    if (!v.size()) cout << -1 << "\n";
    else {
        cout << accumulate(v.begin(), v.end(), 0) << "\n";
        cout << *min_element(v.begin(), v.end()) << "\n";
    }

    return 0;
}