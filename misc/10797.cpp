#include <bits/stdc++.h>
using namespace std;
int n, temp, cnt=0;

int main(){
    cin >> n;
    for (int i=0; i<5; i++){
        cin >> temp;
        if (temp == n) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}