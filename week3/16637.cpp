#include <bits/stdc++.h>
using namespace std;
int n, ret = -987654321;
string s;
vector<int>nums;
vector<int>ops;

int calc(int a, char b, int c){
    if (b == '*') return a * c;
    else if (b == '+') return a + c;
    else if (b == '-') return a - c;
}

void solve(int idx, int cur_num){
    if (idx == nums.size() - 1){
        ret = max(ret, cur_num);
        return;
    }

    solve(idx + 1, calc(cur_num, ops[idx], nums[idx+1]));

    if (idx + 2 <= nums.size() - 1){
        int temp = calc(nums[idx+1], ops[idx+1], nums[idx+2]);
        solve(idx + 2, calc(cur_num, ops[idx], temp));
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> s;

    for (int i=0; i<n; i++){
        if (i % 2 == 0){
            nums.push_back(s[i] - '0');
        } else {
            ops.push_back(s[i]);
        }
    }

    solve(0, nums[0]);
    cout << ret << "\n";

    return 0;
}