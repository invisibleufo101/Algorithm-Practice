#include <bits/stdc++.h>
using namespace std;
int n,k;
int s_visit[500004];
// int bro_check[500004];
int bro_check[1000004];

void solve(int u, int target){
    s_visit[u] = 1;
    bro_check[0] = target;

    if (u == target){
        cout << 0 << "\n";
        return;
    } 
    
    queue<int>q;
    q.push(u);

    while (q.size()){
        u = q.front();
        q.pop();

        cout << "DEPTH LEVEL: " << s_visit[u] << "\n";

        cout << "U value: " << u << "\n";
        bro_check[s_visit[u]] = bro_check[s_visit[u]-1] + s_visit[u];
        cout << "Bro check at cur LEVEL: " << bro_check[s_visit[u]-1] << "\n";

    
        int dir[] = {u - 1, u + 1, u * 2};

        cout << "--------------\n";
        for (int i=0; i<3; i++){
            int nu = dir[i];

            if (nu < 0 || nu >= 500001) continue;

            

            if (bro_check[s_visit[u]] > 500000){
                cout << -1 << "\n";
                return;
            }

            // -------- Debug --------
            // this_thread::sleep_for(std::chrono::milliseconds(300));
            cout << "Subin next step # " << i+1 << ": " << nu << "\n";
            cout << "Bro step: " << bro_check[s_visit[u]-1] << "\n";
            // ------------------------

            if (nu == bro_check[s_visit[u]-1]){
                cout << "UP HERE!\n";
                cout << s_visit[u] << "\n";
                return;
            }
            
            if (nu == bro_check[s_visit[u]]){
                cout << s_visit[u] << "\n";
                return;
            }

            if (s_visit[nu]) continue; 
            
            s_visit[nu] = s_visit[u] + 1;
            q.push(nu);
        }
        cout << "--------------\n";
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    solve(n, k);

    return 0;
}