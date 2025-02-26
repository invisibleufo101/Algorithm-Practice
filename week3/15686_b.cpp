#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
int city_min = pow(10,10);
vector<pair<int,int>>houses;
vector<pair<int,int>>chicks;
vector<vector<pair<int,int>>>comb_chicks;

int getDist(pair<int,int>s, pair<int,int>e){
    return abs(s.first - e.first) + abs(s.second - e.second);
}

void combi(int start, vector<pair<int,int>>v){
    if (v.size() == m){
        int case_min = 0;
        for (auto house : houses){
            int h_min = pow(10,10);
            for (auto chick : v){
                h_min = min(h_min, getDist(chick, house));
            }
            case_min += h_min;
        }
        city_min = min(city_min, case_min);

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
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];

            if (arr[i][j] == 1) houses.push_back({i,j});
            else if (arr[i][j] == 2) chicks.push_back({i,j});
        }
    }

    vector<pair<int,int>>v;
    combi(-1, v);

    cout << city_min << "\n";

    return 0;
}