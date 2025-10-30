#include <bits/stdc++.h>
using namespace std;

int n = 5;
vector<int>nums = {1,2,3,4,5};
int visited[10];

// Logic for Permutation (where order DOES matter)
void solve(vector<int>v) {
    if (v.size() == 3) {
        for (int i : v) cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i=0; i<n; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        v.push_back(nums[i]);

        solve(v);

        visited[i] = 0;
        v.pop_back();
    }
}

// Logic for Combination (where order doesn't matter, just the composition)
void combi(int start, const vector<int> &nums, vector<int>v) {
    if (v.size() == 3) {
        for (int i : v) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i=start+1; i<n; i++) {
        v.push_back(nums[i]);
        combi(i,nums, v);
        v.pop_back();
    }
}

int main() {
    
    vector<int>t;
    // combi(-1, nums, t);
    solve(t);
    return 0;
}