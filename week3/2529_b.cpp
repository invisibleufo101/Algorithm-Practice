#include <bits/stdc++.h>
using namespace std;
int k;
int visited[11];
char ops[10];
vector<char>nums;
string mx = "0000000000";
string mn = "9999999999";
vector<string>ret;

bool check(vector<char>v){
    for (int i=0; i<k; i++){
        char op = ops[i];

        if (op == '<'){
            if (v[i] > v[i+1]) return false;
        } else if (op == '>'){
            if (v[i] < v[i+1]) return false;
        }
    }
    return true;
}

void mx_cmp(string a, string b){
    for (int i=0; i<k+1; i++){
        if (a[i] > b[i]){
            
            mx = a;
        } else if (b[i] > a[i]){

            mx = b;
        }
    }
}

void mn_cmp(string a, string b){
    for (int i=0; i<k+1; i++){
        if (a[i] > b[i]){
            mn = b;
            
        } else if (b[i] > a[i]){
            mn = a;
            
        }
    }
}

void solve(vector<char>v){

    if (check(v)){
        string tmp = "";
        for (char c : v) tmp += c;

        ret.push_back(tmp);

        // mx_cmp(mx, tmp);
        // mn_cmp(mn, tmp);
    }

    return;
}

void dfs(){
    if (nums.size() == k+1){
        solve(nums);
        return;
    }

    for (int i=0; i<10; i++){
        if (visited[i] == 0){
            visited[i] = 1;
            nums.push_back(char(i + '0'));

            dfs();

            visited[i] = 0;
            nums.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> ops[i];
    }

    dfs();

    sort(ret.begin(), ret.end());

    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";

    // cout << mx << "\n" << mn << "\n";

    return 0;
}