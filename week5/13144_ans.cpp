#include <bits/stdc++.h>
using namespace std;
int n,t;
vector<int>v;
int visited[100001];
unsigned long long ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    int s=0, e=0;
    while (e < n){
        if (!visited[v[e]]){
            visited[v[e]] = 1;
            e++;
        } else {
            ret += (e - s);
            visited[v[s]] = 0;
            s++;
        }
    }

    ret += (long long) (e - s) * (e - s + 1) / 2;
    cout << ret << "\n";

    return 0;
}