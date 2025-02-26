#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char temp;
vector<int>nums;
vector<char>ops;
int mx = pow(-2, 31);

int calculate(int a, char b, int c){
    if (b == '+') return a + c;
    else if (b == '-') return a - c;
    else if (b == '*') return a * c;
}

void solve(int idx, int sum){
    if (idx == nums.size() - 1){
        mx = max(mx, sum);
        return;
    }

    solve(idx+1, calculate(sum, ops[idx], nums[idx+1]));

    if (idx + 2 <= nums.size() - 1){
        int buffer = calculate(nums[idx+1], ops[idx+1], nums[idx+2]);
        solve(idx+2, calculate(sum, ops[idx], buffer));
    }
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
    cout << mx << "\n";

    return 0;
}