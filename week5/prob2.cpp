#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,weight,price,capacity,ret=0;
vector<ll>bags;
map<ll,ll>jewels;
map<ll,ll>jewelPrices;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> weight >> price;
        jewels[weight] = price;
        jewelPrices[price] = weight;
    }

    for (int i=0; i<k; i++){
        cin >> capacity;
        bags.push_back(capacity);
    }

    sort(bags.begin(), bags.end());

    auto it = jewels.begin();
    vector<ll>v;
    for (int i=0; i<k; i++){
        ll curCapacity = bags[i];

        while(it->first <= curCapacity && it != jewels.end()){
            v.push_back(it->second);
            it++;
        }

        if (v.size()){
            sort(v.begin(), v.end());
            ret += v.back();
            v.pop_back();
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
// Ans: 1100

// 9 5
// 4 5
// 4 9
// 4 10
// 8 55
// 14 20
// 9 15
// 8 55
// 8 5
// 11 54
// 10
// 5
// 4
// 15
// 20
// Ans: 183