#include <bits/stdc++.h>
using namespace std;
int n,c,x;
map<int, int>order_mp;
map<int, int>freq_mp;
vector<pair<int,int>>v;
pair<int, int>pr;

/**
 * My original answer!! :D
 * Surprised that it's actually similar to the provided solution
*/

bool cmp(pair<int,int>a, pair<int,int>b){
    int freq_a = a.first;
    int val_a = a.second;

    int freq_b = b.first;
    int val_b = b.second;

    if (freq_a == freq_b){
        return order_mp[val_a] < order_mp[val_b];
    } else {
        return freq_a > freq_b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> c;
    for (int i=0; i<n; i++){
        cin >> x;
        freq_mp[x]++;

        // Only store initial index of the number
        // Start from the index of 1 because comparing values to 0 
        // will cause errors later on
        if (order_mp[x] == 0){
            order_mp[x] = i+1;
        }
    }

    // Frequency Map ( Value, Frequency)
    // I thought about reversing this to get the order of the frequency from
    // greatest to least but I realized that maps don't allow duplicate key values
    // Therefore, duplicate frequency values will be omitted.
    // That's why I used pair to use sort() with a custom compare function
    for (auto i : freq_mp){
        pr = {i.second, i.first};
        v.push_back(pr);
    }
    
    sort(v.begin(), v.end(), cmp);

    // Pair: {Frequency, Value}
    // Store by greatest to least frequency
    // If two values have the same frequency, reference order_mp to see
    // which one has a higher order

    for (auto i : v){
        for (int j=0; j<i.first; j++){
            cout << i.second << " ";
        }
    }
    cout << "\n";

    return 0;
}