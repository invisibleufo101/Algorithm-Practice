#include <bits/stdc++.h>
using namespace std;
int a,b,c;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    v = {a,b,c};
    sort(v.begin(), v.end());

    if (v[0] + v[1] <= v[2]){
        v[2] = v[0] + v[1] - 1;
    } 
        
    cout << accumulate(v.begin(), v.end(), 0) << "\n";
    
    return 0;
}