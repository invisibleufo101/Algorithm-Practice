#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int arr[104];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    int plugCheck[104];
    vector<int>plugs;
    // Local arrays need to be initialized
    // Local vs Global:
    // Global variables are automitcally set to 0 
    // But local variables will hold garbage values until
    // we assign a proper value to it (initialization).
    memset(plugCheck, 0, sizeof(plugCheck)); 
    for (int i=0; i<m; i++){

        if (plugCheck[arr[i]]){
            continue;
        } 
        
        if (plugs.size() < n){
            plugCheck[arr[i]] = 1;
            plugs.push_back(arr[i]);
        } else if (plugs.size() == n){
            
            int maxIdx = -1;
            int plugIdx = -1;

            for (int j=0; j<plugs.size(); j++){
                int idx = -1;
                for (int k=i+1; k<m; k++){

                    if (plugs[j] == arr[k]){
                        idx = k;
                        break;
                    }
                }

                if (idx == -1){
                    plugIdx = j;
                    break;
                }

                if (idx > maxIdx){
                    maxIdx = idx;
                    plugIdx = j;
                }
            }

            plugCheck[plugs[plugIdx]] = 0;
            plugs.erase(plugs.begin()+plugIdx);

            plugs.push_back(arr[i]);
            plugCheck[arr[i]] = 1;
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}

