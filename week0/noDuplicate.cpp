#include <bits/stdc++.h>
using namespace std;

map <int, int> mp;
vector<int>v = {1,3,5,5,6,8,4,2,4,3,5,6,7,8,9};

int main(){

    /**
     * We've used this logic before in pyton when crawling
     *
     * dict = {}
     * for i in v:
     *    if v[i]:
     *       continue
     *    else:
     *       v[i] = 1
     */
    for (int i: v){
        if (mp[i]){
            continue;
        } else {
            mp[i] = 1;
        }
    }

    vector<int>ret;
    for (auto i : mp) {
        
        ret.push_back(i.first);
    }

    for (int x : ret){
        cout << x << "\n";
    }
    
    return 0;
}
