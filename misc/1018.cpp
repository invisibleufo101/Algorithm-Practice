#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
char arr[51][51];
int ret = 987654321;
string cmp1 = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
string cmp2 = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";

int count(int y, int x){
    int cnt1 = 0;
    int cnt2 = 0;
    string tmp = "";

    for (int i=y; i<y+8; i++){
        for (int j=x; j<x+8; j++){
            tmp += arr[i][j];
        }
    }

    for (int i=0; i<tmp.size(); i++){
        if (tmp[i] != cmp1[i]) cnt1++;
        if (tmp[i] != cmp2[i]) cnt2++;
    }
    
    int cnt = min(cnt1, cnt2);

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            arr[i][j] = s[j];
        }
    }

    for (int i=0; i<=n-8; i++){
        for (int j=0; j<=m-8; j++){
            ret = min(ret, count(i,j));
        }
    }

    cout << ret << "\n";

    return 0;
}