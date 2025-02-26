#include <bits/stdc++.h>
using namespace std;
int k, temp;
vector<int>nodes;
vector<int>ret [1040];

void solve(int mid, vector<int>v, int depth){
    if (v.size() == 3){
        ret[depth].push_back(v[mid - 1]);
        ret[depth].push_back(v[mid + 1]);
        return;
    }

    vector<int>left (v.begin(), v.begin()+mid);
    vector<int>right (v.begin() + mid + 1, v.end());

    // Mid point for both split vectors
    int new_mid = left.size() / 2; 

    // To get the mid point of left and right vectors
    int diff = mid - new_mid;

    ret[depth].push_back(v[mid - diff]);
    ret[depth].push_back(v[mid + diff]);

    solve(new_mid, left, depth + 1);
    solve(new_mid, right, depth + 1);

    return;
}

int main(){
    cin >> k;
    for (int i=1; i<=pow(2,k)-1; i++){
        cin >> temp;
        nodes.push_back(temp);
    }

    int mid = nodes.size() / 2;
    ret[1].push_back(nodes[mid]);

    solve(mid, nodes, 2);

    for (int i=1; i<=k; i++){
        for (int j : ret[i]){
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}