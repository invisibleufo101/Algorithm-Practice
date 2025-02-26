#include <bits/stdc++.h>
using namespace std;
int n;

void solve(int n){
    int cnt = 0;
    int newVal = n;
    while(true){
        int a = newVal / 10;
        int b = newVal % 10;
        int res = (a + b) % 10;

        newVal = b*10 + res;
        cnt++;
       
        if (newVal == n){
            cout << cnt << "\n";
            break;
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    solve(n);

    return 0;
}