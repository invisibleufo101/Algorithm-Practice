#include <bits/stdc++.h>
using namespace std;
int n,k,order[104],cnt;
int visited[104];
vector<int>v;
int const INF = 987654321;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=0; i<k; i++) cin >> order[i];
    
    for (int i=0; i<n; i++){
        if (!visited[order[i]]){
            if (v.size() == n){
                int lastIdx = 0,pos;
                for (int x : v){
                    int idx = INF;
                    for (int j = i+1; j<k; j++){
                        if (x == order[j]){
                            idx = j;
                            break;
                        }
                    }

                    if (idx > lastIdx){
                        lastIdx = idx;
                        pos = x;
                    }
                }

                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            v.push_back(order[i]);
            visited[order[i]] = 1;
        }
    }

    cout << cnt << "\n";
    
    return 0;
}