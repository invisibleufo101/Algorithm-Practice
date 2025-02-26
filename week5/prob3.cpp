#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll x,y,ret=0;
vector<pair<ll,ll>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end());

    ll startPoint = v[0].first;
    ll endPoint = v[0].second;
    
    for (int i=1; i<v.size(); i++){
        ll nextStart = v[i].first;
        ll nextEnd = v[i].second;

        if (nextStart <= endPoint && nextEnd > endPoint){
            endPoint = nextEnd;
        } else if (nextStart > endPoint){
            // If line can't be continued anymore,
            // hand off the start & end point to the new discontinued point
            ret += (endPoint - startPoint);

            startPoint = nextStart;
            endPoint = nextEnd;
        }
    }

    ret += (endPoint - startPoint);

    cout << ret << "\n";

    return 0;
}