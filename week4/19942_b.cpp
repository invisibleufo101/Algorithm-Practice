#include <bits/stdc++.h>
using namespace std;
int n;
int mp, mf, ms, mv; // Minimum nutrition
int tp, tf, ts, tv, tc;
int visited[16];
struct A {
    int idx, p, f, s, v, c;
};
vector<A>options;
int ret = 7600; // Max cost = 7500
vector<vector<A>>tmp;

// Only checks if the group meets the min nutritional requirements
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

int getCost(vector<A>v){
    int totalC = 0;
    for (A i : v){
        totalC += i.c;
    }
    return totalC;
}

int main(){
    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i=0; i<n; i++){
        cin >> tp >> tf >> ts >> tv >> tc;
        int tIdx = i+1;
        options.push_back({tIdx, tp, tf, ts, tv, tc});
    }

    for (int i=1; i<(1 << n); i++){
        vector<A>temp;
        for (int j=0; j<n; j++){
            if (i & (1 << j)){
                temp.push_back(options[j]);
            }
        }

        int tCost = getCost(temp);
        // Check if items meet the minimum nutrition cost 
            if (check(temp) && ret >= tCost){
            ret = tCost;
            tmp.push_back(temp);
        }
    }

    if (!tmp.size()){
        cout << -1;
        return 0;
    }

    // Print minimum cost
    cout << ret << "\n";

    // Logic for getting the group(s) of items with min cost
    vector<vector<int>>indexes;
    for (auto v : tmp){
        // Only if the group is equal to min cost, add the
        if (getCost(v) == ret){
            vector<int>buffer;
            for (auto i : v){
                buffer.push_back(i.idx);
            }
            indexes.push_back(buffer);
        }
    }

    // Logic for finding the item with the earliest order degree
    sort(indexes.begin(), indexes.end());
    
    for (int i : indexes[0]) cout << i << " ";
    cout << "\n";

    return 0;
}


// 4
// 100 100 100 100
// 50 50 50 50 1
// 50 50 50 50 1
// 50 50 50 50 1
// 50 50 50 50 1

// 3
// 0 0 0 1
// 0 0 0 1 1
// 0 0 0 0 0
// 0 0 0 0 0

// 4
// 10 10 10 10
// 8 8 8 8 3
// 2 2 2 2 2
// 6 6 6 6 1
// 4 4 4 4 4

// 15
// 1 2 2 4
// 0 0 0 1 420
// 1 1 2 2 420
// 2 2 0 2 420
// 0 0 1 2 420
// 2 2 0 1 420
// 2 2 0 2 420
// 1 0 0 0 420
// 2 2 0 1 420
// 0 2 2 0 420
// 0 1 1 1 420
// 0 2 0 0 420
// 2 2 2 0 420
// 1 0 0 1 420
// 2 1 1 2 420
// 0 1 2 2 420

// 6
// 5 5 5 5
// 3 2 3 2 100
// 2 3 2 3 100
// 4 1 4 1 100
// 1 4 1 4 100
// 3 3 3 3 100 
// 2 2 2 2 100

// 2
// 0 0 0 10
// 0 0 0 10 1
// 0 0 0 5 0