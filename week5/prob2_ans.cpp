#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,weight,price,capacity,ret=0;
vector<pair<ll,ll>>jewels;
vector<ll>bags;
priority_queue<ll>pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> weight >> price;

        jewels.push_back({weight, price});
    }

    for (int i=0; i<k; i++){
        cin >> capacity;
        bags.push_back(capacity);
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    int j=0; 
    for (int i=0; i<k; i++){
        
        while(j<n && jewels[j].first <= bags[i]){

            cout << "Added: " << jewels[j].second << "\n";

            pq.push(jewels[j].second);
            j++;
        }

        if (pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";

    return 0;
}

// 4 4
// 1 100
// 2 200
// 13 300
// 10 500
// 10
// 10
// 10
// 14