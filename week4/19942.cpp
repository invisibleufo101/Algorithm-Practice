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
int ret = 7600;
int visited[16];

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
    for (auto i : v){
        totalC += i.c;
    }
    return totalC;
}

void combi(int start, vector<nutri>v){
    if (check(v) && getCost(v) <= ret){
        ret = getCost(v);
        temps.push_back(v);
        return;
    } else if (getCost(v) > ret){
        return;
    } else if (v.size() == options.size()){
        return;
    }

    for (int i=start+1; i<options.size(); i++){
        v.push_back(options[i]);
        combi(i, v);
        v.pop_back();
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i=0; i<n; i++){
        cin >> tp >> tf >> ts >> tv >> tc;
        int ti = i+1;
        options.push_back({ti, tp, tf, ts, tv, tc});
    }

    vector<nutri>t;
    combi(-1, t);

    if (!temps.size()){
        cout << -1 << "\n";
        return 0;
    }

    cout << ret << "\n";

    vector<vector<int>>answer;
    for (auto temp : temps){
        if (getCost(temp) == ret){
            vector<int>buffer;
            for (auto i : temp){
                buffer.push_back(i.idx);
            }
            answer.push_back(buffer);
        }
    }

    sort(answer.begin(), answer.end());
    for (int i : answer[0]) cout << i << " ";
    cout << "\n";

    return 0;
}