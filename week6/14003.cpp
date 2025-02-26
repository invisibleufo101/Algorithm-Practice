#include <bits/stdc++.h>
using namespace std;
int n,arr[1000004],traces[1000004];
vector<int>lis,indexes,ret;

void getTrace(int idx){
    if (idx == -1) return;
    ret.push_back(arr[idx]);
    getTrace(traces[idx]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(traces, -1, sizeof(traces));

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++){
        int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

        // If the current number is bigger than the last number in LIS array
        if (pos == lis.size()){
            lis.push_back(arr[i]);
            indexes.push_back(i);
        
        // If the current number is not bigger than the last number in LIS array,
        } else {
            lis[pos] = arr[i];
            indexes[pos] = i;
        }

        if (pos > 0){
            traces[i] = indexes[pos - 1];
        }


        // Debug
        cout << "------------\n";
        cout << "Index: " << i << ", " << arr[i] << "\n";
        for (int k : lis) cout << k << " ";
        cout << "\n";
        for (int k : indexes){
            if (arr[k] >= 10) cout << " " << k << " ";
            else cout << k << " ";
        }
        cout << "\n";

        cout << "\n";

        for (int k=0; k<n; k++) cout << " " << k << " ";
        cout << "\n";
        for (int k=0; k<n; k++){
            if (traces[k] != -1) cout << " " << traces[k] << " ";
            else cout << traces[k] << " ";
        }
        cout << "\n";
    }

    getTrace(indexes.back());

    cout << ret.size() << "\n";
    for (int i=ret.size()-1; i>=0; i--) cout << ret[i] << " ";
    cout << "\n";

    return 0;
}