#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
bool isPossible = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    while (n > 0){

        if (n >= 5 && n % 5 == 0){
            cnt += (n / 5);
            n = 0;
        } else if (n >= 3){
            n -= 3;
            cnt++;
        } else if (n < 3){
            isPossible = 0;
            break;
        }
    }

    if (isPossible) cout << cnt << "\n";
    else cout << -1 << "\n";

    return 0;
}