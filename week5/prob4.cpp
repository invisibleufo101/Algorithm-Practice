#include <bits/stdc++.h>
using namespace std;
int n,t,x,cnt=0;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }
    cin >> x;

    sort(v.begin(), v.end());

    int lPoint = 0;
    int rPoint = n-1;

    while(lPoint < rPoint){
        if (v[lPoint] + v[rPoint] > x){
            rPoint--;
        } else if (v[lPoint] + v[rPoint] < x){
            lPoint++;
        } else if (v[lPoint] + v[rPoint] == x){
            cnt++;
            rPoint--;
        }
    }

    cout << cnt << "\n";

    return 0;
}