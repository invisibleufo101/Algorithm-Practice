#include <bits/stdc++.h>
using namespace std;
int n,l,a, b;
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    
    // Consider all points here to be starting points
    // Assume that every end point (puddleEnd, plankEnd) 
    // are indicating where they START to end

    int iniStart = v[0].first;
    int iniEnd = v[0].second - 1;
    int puddleLen = iniEnd - iniStart + 1;
    int totalCnt = puddleLen / l + bool(puddleLen % l);
    int plankEnd = iniStart + (totalCnt * l) - 1;

    for (int i=1; i<v.size(); i++){
        // If the laid down plank exceeds the puddle
        if (plankEnd > v[i].second - 1) continue;

        int nextStart = v[i].first;
        // If the previously laid down plank extends to the next puddle
        if (plankEnd >= nextStart){
            nextStart = plankEnd + 1;
        }
        int nextEnd = v[i].second - 1;

        int nextLen = nextEnd - nextStart + 1;
        int curCnt = nextLen / l + bool(nextLen % l);

        plankEnd = nextStart + (curCnt * l) - 1;
        totalCnt += curCnt;
    }

    cout << totalCnt << "\n";

    return 0;
}

// 3 10
// 1 6
// 7 8
// 11 15
// Ans: 1
