#include <bits/stdc++.h>
using namespace std;
int n,arr[1004],dp[1004],prevArr[1004],ret=1,idx;
vector<int>v;

void print(int idx){
    if (idx == -1) return;

    v.push_back(arr[idx]);
    print(prevArr[idx]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // dp array => counts the length of LIS for each number
    fill(&dp[0], &dp[1004], 1);
    // prevArr => records the previous indexes 
    fill(&prevArr[0], &prevArr[1004], -1);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    
    
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            // If the previous num is smaller than the current number
            // AND 
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                prevArr[i] = j;
                if (dp[i] > ret){
                    ret = dp[i];
                    idx = i;
                }
            }
        }
    }

    cout << ret << "\n";
    print(idx);
    for (int i=v.size()-1; i>=0; i--) cout << v[i] << " ";
    cout << "\n";

    return 0;
}

// 5
// 999 1000 1 2 3