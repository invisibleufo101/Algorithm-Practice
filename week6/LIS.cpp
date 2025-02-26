#include <bits/stdc++.h>
using namespace std;
int n,arr[1004], cnt[1004], ret=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    // Optional <- If we are not going to use cnt[i] = 1
    // fill(&cnt[0], &cnt[1004], 1);

    for (int i=0; i<n; i++){
        cnt[i] = 1;
        for (int j=0; j<i; j++){
            if (arr[j] < arr[i]){
                cnt[i] = max(cnt[i], cnt[j] + 1);
            }
        }
        ret = max(ret, cnt[i]);
    }

    cout << ret << "\n";
    
    return 0;
}