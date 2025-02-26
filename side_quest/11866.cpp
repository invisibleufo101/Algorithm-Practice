#include <bits/stdc++.h>
using namespace std;
int n,k;
queue<int>q;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++){
        q.push(i);
    }

    while(n--){
        int iter = 1;
        while(q.size()){
            if (iter == k){
                v.push_back(q.front());
                q.pop();
                break;
            } 

            q.push(q.front());
            q.pop();

            iter++;
        }
    }

    cout << "<";
    for (int i=0; i<v.size(); i++){
        if (v[i] == v.back()) cout << v[i];
        else cout << v[i] << ", ";
    }
    cout << ">\n";
    
    return 0;
}