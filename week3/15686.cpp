#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
int visited[14];
int city_min = pow(10, 10);
vector<pair<int,int>>houses;
vector<pair<int,int>>chicks;
vector<pair<int,int>>picked;

int getDist(pair<int,int>s, pair<int,int>e){
    return abs(s.first - e.first) + abs(s.second - e.second);
}

void combi(int idx, int length){
    if (length == m){
        // Total minimum distance for each CASE
        int t_min = 0;
        for (auto house : houses){
            // Minimum distance of each HOUSE
            int h_min = pow(10,10);
            for (auto pick : picked){
                h_min = min(h_min, getDist(pick, house));
            }
            t_min += h_min;
        }
        city_min = min(city_min, t_min);
        return;
    }

    for (int i=idx; i<chicks.size(); i++){
        if (visited[i] == 0){

            visited[i] = 1;
            picked.push_back(chicks[i]);

            combi(i, length+1);

            visited[i] = 0;
            picked.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 1){
                houses.push_back({i,j});
            } else if (arr[i][j] == 2){
                chicks.push_back({i,j});
            }
        }
    }

    combi(0,0);
    cout << city_min << "\n";

    return 0;
}