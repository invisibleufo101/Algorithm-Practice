#include <bits/stdc++.h>
using namespace std;
int n;
int mp,mf,ms,mv;
int tp,tf,ts,tv,tc;
struct A{
    int idx,p,f,s,v,c;
};
vector<A>options;
int visited[16];
int ret = 987654321;
map<int, vector<vector<int>>>ret_v;

bool check(vector<A>v){
    int totalP = 0;
    int totalF = 0;
    int totalS = 0;
    int totalV = 0;

    for (auto i : v){
        totalP += i.p;
        totalF += i.f;
        totalS += i.s;
        totalV += i.v;

    }

    if (totalP >= mp && totalF >= mf && totalS >= ms && totalV >= mv){
        return true;
    }
    return false;
}

pair<int, vector<int>> getCost(vector<A>v){
    int totalC = 0;
    vector<int>index;
    for (auto i : v) {
        totalC += i.c;
        index.push_back(i.idx);
    }

    return {totalC ,index};
}

void combi(int idx){
    if (idx == n){
        vector<A>temp;
        for (int i=0; i<n; i++){
            if (visited[i]) temp.push_back(options[i]);
        }

        if (check(temp)){
            int cost;
            vector<int>v;
            tie(cost, v) = getCost(temp);

            if (cost <= ret){
                ret = cost;
                ret_v[ret].push_back(v);
            }
        }

        return;
    }

    visited[idx] = 1;
    combi(idx + 1);
    visited[idx] = 0;
    combi(idx + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i=0; i<n; i++){
        cin >> tp >> tf >> ts >> tv >> tc;
        int tIdx = i+1;
        options.push_back({tIdx, tp, tf, ts, tv, tc});
    }

    combi(0);

    sort(ret_v[ret].begin(), ret_v[ret].end());

    cout << ret << "\n";
    
    for (int i : ret_v[ret][0]) cout << i << " ";
    cout << "\n";

    return 0;
}

// 4
// 100 100 100 100
// 50 50 50 50 1
// 50 50 50 50 1
// 50 50 50 50 1
// 50 50 50 50 1

// 2
// 0 0 0 10
// 0 0 0 10 1
// 0 0 0 5 0
