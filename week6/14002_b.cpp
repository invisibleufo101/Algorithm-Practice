#include <bits/stdc++.h>
using namespace std;
int n,arr[1004],cnt[1004], traces[1004],ret=1,idx;
vector<int>v;

void solve(int idx){
    if (idx == -1) return;
    v.push_back(arr[idx]);
    solve(traces[idx]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    fill(&cnt[0], &cnt[1004], 1);
    fill(&traces[0], &traces[1004], -1);

    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            // If the current number is greater than the previous number
            // AND the length of cnt of that previous number + 1 is greater
            if (arr[j] < arr[i] && cnt[j]+1 > cnt[i]){
                cnt[i] = cnt[j] + 1;
                traces[i] = j; // <- storing the traces 

                if (cnt[i] > ret){
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }

    solve(idx);
    cout << ret << "\n";
    for (int i=v.size()-1; i>=0; i--) cout << v[i] << " ";

    return 0;
}

// 13
// 3 4 5 6 2 3 1 7 4 3 5 6 7