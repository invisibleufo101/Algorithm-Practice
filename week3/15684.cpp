#include <bits/stdc++.h>
using namespace std;
int n,m,h;
int a,b;
int arr[12][272]; // m,n

int dx[] = {-1,1,0};
int dy[] = {0,0,1}; // Right, Left, Down

map<pair<int,int>,pair<int,int>> joints; // 420

void print(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

bool check(){
    
}

void dfs(int x, int y, int cnt){
    

    

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> h;

    // Recieving info about ladder joints
    for (int i=0; i<m; i++){
        cin >> a >> b;
        joints[{a,b}] = {a,b+1};
        joints[{a,b+1}] = {a,b};
    }

    

    return 0;
}