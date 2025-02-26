#include <bits/stdc++.h>
using namespace std;
int n;
int mp, mf, ms, mv; // Min requirements
int tp, tf, ts, tv, tc; // Input vars
struct A{
    int p, f, s, v, c;
}arr[16];
map<int,vector<vector<int>>> ret_v;
int ret = 987654321;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i=0; i<n; i++){
        cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
    }

    for (int i=1; i < (1 << n); i++){
        int totalP = 0;
        int totalF = 0;
        int totalS = 0;
        int totalV = 0;
        int totalC = 0;
        vector<int>v;

        for (int j=0; j<n; j++){
            if (i & (1 << j)){
                v.push_back(j+1);
                totalP += arr[j].p;
                totalF += arr[j].f;
                totalS += arr[j].s;
                totalV += arr[j].v;
                totalC += arr[j].c;
            }
        }

        if (totalP >= mp &&  totalF >= mf && totalS >= ms && totalV >= mv){
            if (ret >= totalC){
                ret = totalC;
                ret_v[ret].push_back(v);
            }
        }
    }


    for (auto i : ret_v){
        cout << i.first << "::";
        for (auto j : i.second){
            cout << "( ";
            for (auto k : j){
                cout << k << " ";
            }
            cout << ") ";
            cout << "\n";
        }
    }
    
    // if (ret == 987654321){
    //     cout << -1 << "\n";
    // } else {
    //     sort(ret_v[ret].begin(), ret_v[ret].end());
    //     cout << ret << "\n";

    //     for (int idx : ret_v[ret][0]){
    //         cout << idx << " ";
    //     }
    // }

    return 0;
}

// 4
// 100 100 100 100
// 50 50 50 50 1
// 50 50 50 50 1
// 50 50 50 50 1
// 50 50 50 50 1

