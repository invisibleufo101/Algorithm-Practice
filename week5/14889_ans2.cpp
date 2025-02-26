#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, arr[24][24], visited[24];
int mn = INF;

int getMin(vector<int>&v1, vector<int>&v2){
    pair<int,int>ret;
    for (int i=0; i<n/2; i++){
        for (int j=0; j<n/2; j++){
            ret.first += arr[v1[i]][v1[j]];
            ret.second += arr[v2[i]][v2[j]];
        }
    }

    return abs(ret.first - ret.second);
}

void combi(int start, vector<int>v){
    if (v.size() == n/2){
        vector<int>team1, team2;
        for (int i=0; i<n; i++){
            if (visited[i]) team1.push_back(i);
            else team2.push_back(i);
        }
        mn = min(mn, getMin(team1, team2));
        return;
    }

    for (int i=start+1; i<n; i++){
        visited[i] = 1;
        v.push_back(i);

        combi(i,v);

        visited[i] = 0;
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int>t;
    combi(-1, t);

    cout << mn << "\n";

    return 0;
}