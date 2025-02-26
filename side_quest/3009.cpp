#include <bits/stdc++.h>
using namespace std;
int x,y, ret_x, ret_y;
vector<pair<int,int>>v;

int main(){
    for (int i=0; i<3; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }    

    if (v[0].first == v[1].first){
        int height = abs(v[0].second - v[1].second);
        ret_x = v[2].first;
        
        int temp = max(v[0].second, v[1].second);
        if (v[2].second == temp){
            ret_y = v[2].second - height;
        } else if (v[2].second < temp){
            ret_y = v[2].second + height;
        }
    } else if (v[1].first == v[2].first){
        int height = abs(v[1].second - v[2].second);
        ret_x = v[0].first;
        
        int temp = max(v[1].second, v[2].second);
        if (v[0].second == temp){
            ret_y = v[0].second - height;
        } else if (v[0].second < temp){
            ret_y = v[0].second + height;
        }
    } else if (v[0].first == v[2].first){
        int height = abs(v[0].second - v[2].second);
        ret_x = v[1].first;
        
        int temp = max(v[0].second, v[2].second);
        if (v[2].second == temp){
            ret_y = v[1].second - height;
        } else if (v[1].second < temp){
            ret_y = v[1].second + height;
        }
    }

    cout << ret_x << " " << ret_y << "\n";

    return 0;
}