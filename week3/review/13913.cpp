#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[200002];
int visited[200002];
int cnt[200002];

void bfs(int u){
    visited[u] = 1;
    
    queue<int>q;
    q.push(u);

    while(q.size()){
        u = q.front();
        q.pop();
    
        int dir[] = {u * 2, u + 1, u - 1};
        for (int i=0; i<3; i++){
            int nu = dir[i];

            if (nu < 0 || nu >= 100002) continue;
            if (visited[nu]) continue;
            
            cnt[nu] = u;
            visited[nu] = visited[u] + 1;
            q.push(nu);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if (n == k){
        cout << 0 << "\n" << n << "\n";
        return 0;
    }

    bfs(n);

    cout << visited[k] - 1 << "\n";
    vector<int>v;

    for (int i=k; i != n; i = cnt[i]){
        v.push_back(i);
    }
    v.push_back(n);

    reverse(v.begin(), v.end());
    
    for (auto i : v) cout << i << " ";
    
    
    return 0;
}