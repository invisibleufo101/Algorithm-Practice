#include <bits/stdc++.h>
using namespace std;
int n, arr[22][22];
vector<int>combos;
vector<int>playerNums;
int mn = 987654321;
int visited[21];
map<pair<int,int>,int>mp;

void getMin(int a[21]){
    vector<int>team1, team2;
    int team1Sum = 0, team2Sum = 0;

    for (int i=0; i<playerNums.size(); i++){
        if (a[i]) team1.push_back(playerNums[i]);
        else team2.push_back(playerNums[i]);
    }

    for (int i=0; i<team1.size(); i++){
        for (int j=i+1; j<team1.size(); j++){
            team1Sum += mp[{team1[i], team1[j]}];
            team2Sum += mp[{team2[i], team2[j]}];
        }
    }

    mn = min(mn, abs(team1Sum - team2Sum));
}

// Get combination of team1 and team2
void solve(int idx, int cnt){
    if (cnt == n/2){
        getMin(visited);
        return;
    } else if (idx == playerNums.size()-1){
        return;
    }

    visited[playerNums[idx]] = 1;
    solve(idx+1, cnt+1);

    visited[playerNums[idx]] = 0;
    solve(idx+1, cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        playerNums.push_back(i);
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if (arr[i][j]){
                mp[{i,j}] = arr[i][j] + arr[j][i];
            }
        }
    }

    solve(0,0);

    cout << mn << "\n";

    return 0;
}