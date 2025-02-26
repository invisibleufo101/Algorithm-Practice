#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[65][65];

void dfs(int u){
    

}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<n; j++){
            arr[i][j] = s[j] - '0';
        }
    }
    return 0;
}