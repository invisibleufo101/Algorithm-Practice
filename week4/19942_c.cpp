#include <bits/stdc++.h>
using namespace std;
int n;
int mp, mf, ms, mv;
int tp, tf, ts, tv, tc;
struct nutri{
    int idx, p, f, s, v, c;
};
vector<nutri>options;
vector<vector<nutri>>temps;
int ret = 987654321;

bool check(vector<nutri>v){
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

int getCost(vector<nutri>v){
    int totalC = 0;
    for (auto i : v) totalC += i.c;
    return totalC;
}

void dfs(int idx, vector<nutri>v){
    if (check(v) && getCost(v) <= ret){
        ret = getCost(v);
        temps.push_back(v);
        return;
    } else if (getCost(v) > ret){
        return;
    } else if (idx == n){
        return;
    }

    // Excludes the current element
    dfs(idx + 1, v);

    // Includes the current element
    v.push_back(options[idx]);
    dfs(idx + 1, v);
    v.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i=0; i<n; i++){
        cin >> tp >> tf >> ts >> tv >> tc;
        int tidx = i + 1;

        options.push_back({tidx, tp, tf, ts, tv, tc});
    }

    vector<nutri>t;
    dfs(0, t);

    // If no adequate combination has been found
    if (!temps.size()){
        cout << -1 << "\n";
        return 0;
    }

    // Else...
    cout << ret << "\n";

    vector<vector<int>>ans;
    for (auto temp : temps){
        if (getCost(temp) == ret){
            vector<int>buffer;
            for (auto i : temp){
                buffer.push_back(i.idx);
            }
            ans.push_back(buffer);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i : ans[0]) cout << i << " ";
    cout << "\n";

    return 0;
}