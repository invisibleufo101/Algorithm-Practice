#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[21];
int ret = 450;

void solve(int idx){
    if (idx == n+1){

        int sum = 0;
        for (int i=1; i<=(1 << (n-1)); i*=2){
            int cnt = 0;
            for (int j=1; j<=n; j++){
                // Counting all tails for each row
                if (arr[j] & i){
                    cnt++;
                }    
            }

            // The reason for min() here is because
            // even though we are counting the tails
            // If the number of tails (cnt) is more than heads (n - cnt)
            // we can still technically "flip" the column
            // We don't actually do the flipping but by determining 
            // which count of heads or tails is greater,
            // the built-in funciton min() lets us take the least number of counts
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }


    solve(idx + 1);

    arr[idx] = ~arr[idx];
    solve(idx + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> s;
        int val = 1;
        for (int j=0; j<s.length(); j++){
            if (s[j] == 'T'){
                arr[i] |= val;
            }
            val *= 2;
        }
    }

    solve(1);
    cout << ret << "\n";
    

    return 0;
}