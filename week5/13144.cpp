#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,t;
vector<int>v;
int visited[100004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    int e = 0;
    ull cnt = 0;

    // Worst case scenario:
    // 10^10
    // Therefore, unsigned long long is REQUIRED to avoid overflow
    for (int s = 0; s < n; s++){

        cout << "---------------------\n";
        while(e < n){
            if (visited[v[e]]) break;
            visited[v[e]] = 1;
            e++;

            for (int i=1; i<=n; i++) cout << visited[i] << " ";
            cout << "\n";
        }
        cout << "---------------------\n";

        cout << "Start: " << s << " End: " << e << "\n";

        cnt += (e - s);
        visited[v[s]] = 0;

        cout << "Visited: ";
        for (int i=1; i<=n; i++) cout << visited[i] << " ";
        cout << "\n";
    }

    cout << cnt << "\n";
    
    return 0;
}