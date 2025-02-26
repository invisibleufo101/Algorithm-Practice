#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
int visited[14];

vector<pair<int,int>>chicks;
vector<pair<int,int>>houses;
int cityMin = 987654321;


int getDist(pair<int,int>p1, pair<int,int>p2){
    int dist = abs(p1.first - p2.first) + abs(p1.second - p2.second);
    return dist;
}

void getMin(vector<pair<int,int>>sel_chicks){
    int minForEachCase = 0;
    for (auto house : houses){

        int minHouse = 987654321;
        // Get the chicken shop closest to each individual house 
        for (auto chick : sel_chicks){
            int dist = getDist(house, chick);
            minHouse = min(minHouse, dist);
        }
        // Add up each minimum distance of each house
        minForEachCase += minHouse;
    }

    // Compare it to the total minimum outcome
    cityMin = min(cityMin, minForEachCase);

    return;
}

void combi(int start, vector<pair<int,int>>v){
    if (v.size() == m){
        getMin(v);
        return;
    }

    for (int i=start+1; i<chicks.size(); i++){
        v.push_back(chicks[i]);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];

            if (arr[i][j] == 2){
                chicks.push_back({i,j});
            } else if (arr[i][j] == 1){
                houses.push_back({i,j});
            }
        }
    }
    vector<pair<int,int>>tmp;

    combi(-1, tmp);

    cout << cityMin << "\n";

    return 0;
}