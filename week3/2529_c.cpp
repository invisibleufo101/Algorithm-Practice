#include <bits/stdc++.h>
using namespace std;
int k, visited[10];
char arr[20];
vector<string>ret;
vector<char>nums;

bool check(char a, char b, char op){
    if (a > b && op == '>') return true;
    else if (a < b && op == '<') return true;
    
    return false;
}

void solve(int idx, string num){
    if (idx == k + 1){
        ret.push_back(num);
        return;
    }

    for (int i=0; i<10; i++){
        if (visited[i]) continue;
        if (idx == 0 || check(num[idx - 1], char(i + '0'), arr[idx - 1])){        
            visited[i] = 1;
            solve(idx + 1, num + to_string(i));
            visited[i] = 0;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> arr[i];
    }

    solve(0, "");

    sort(ret.begin(), ret.end());

    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";

    return 0;
}