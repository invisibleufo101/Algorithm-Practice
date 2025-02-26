#include <bits/stdc++.h>
using namespace std;
/**
 * One thing I learned about using BFS algorithm:
 * You really need to think about which order of movement has the greatest priority
 * int dir[] = {u * 2, u + 1, u - 1} 
 * For example, here the instant TP has the best outcome therefore needs to be put first
 * instead of : int dir[] = {u - 1, u + 1, u * 2}
*/

int n,k;
int visited[100001];

void zeroOne(int u){
    visited[u] = 1;
    deque<int>dq;
    dq.push_front(u);
    while(dq.size()){
        u = dq.front();
        dq.pop_front();

        if (u == k){
            cout << visited[u] - 1 << "\n";
            return;
        }

        // int dir[] = {u - 1, u + 1, u * 2};
        int dir[] = {u * 2, u + 1, u - 1};
        for (int i=0; i<3; i++){
            int nu = dir[i];

            if (nu < 0 || nu >= 100001) continue;
            if (visited[nu]) continue;

            if (i == 0){
                visited[nu] = visited[u];
                dq.push_front(nu);

            } else {

                visited[nu] = visited[u] + 1;
                dq.push_back(nu);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    zeroOne(n);

    return 0;
}