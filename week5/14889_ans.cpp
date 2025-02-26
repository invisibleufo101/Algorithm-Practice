#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, arr[24][24];
int mn = INF;

int solve(vector<int>&v1, vector<int>&v2){
    pair<int,int>ret;
    for (int i=0; i<n/2; i++){
        for (int j=0; j<n/2; j++){
            if (arr[i][j] == 0) continue;

            ret.first += arr[v1[i]][v1[j]];
            ret.second += arr[v2[i]][v2[j]];
        }
    }

    return abs(ret.first - ret.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=1; i<(1 << n); i++){
        // __builtin_popcount(): Counts the number of 1s in a binary number
        if (__builtin_popcount(i) != n/2) continue;
        // if (bitset<21>(i).count() != n/2) continue; // <- Alternative

        vector<int>team1, team2;
        for (int j=0; j<n; j++){
            if (i & (1 << j)) team1.push_back(j);
            else team2.push_back(j);
        }

        mn = min(mn, solve(team1, team2));
    }

    cout << mn << "\n";

    return 0;
}