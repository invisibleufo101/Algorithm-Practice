#include <bits/stdc++.h>
using namespace std;
int t,k,gearNum,dir,ret;
string s[1004];

void _rotate(int pos, int dir){
    // dir == 1 -> clockwise
    // dir == 0 -> counter-clockwise
    if (!dir) rotate(s[pos].begin(), s[pos].begin()+1, s[pos].end());
    else rotate(s[pos].begin(), s[pos].begin() + s[pos].size()-1, s[pos].end());
}

// Based on the current gear, find the leftmost spot where the gears stop turning
int findL(int pos){
    for (int i=pos; i>=1; i--){
        if (s[i][6] == s[i-1][2]){
            return i;
        }
    }
    // If there's nothing that gets stuck at IF, then return the left-most spot(0)
    return 0;
}

// Find the right-most spot where the gears stop turning
int findR(int pos){
    for (int i=pos; i <= t-2; i++){
        if (s[i][2] == s[i+1][6]){
            return i;
        }
    }

    // If all right-side gears turn, then return the last gear
    return t-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for (int i=0; i<t; i++){
        cin >> s[i];
    }

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> gearNum >> dir;
        gearNum--;
        // If dir is -1, then turn it into 0
        // else, turn it into 1
        dir = (dir == -1 ? 0 : 1);
        int left = findL(gearNum); // Get the left-most gear that needs to turn
        int right = findR(gearNum); // Get the right-most gear that needs to turn
        int cnt = 0;
        // cnt % 2 == 0 ? dir : !dir
        // This code simply means switches the direction that the gears need to turn
        // clockwise -> counter-clockwise -> clockwise... (vice versa)
        for (int pos = gearNum; pos >= left; pos--){
            _rotate(pos, cnt % 2 == 0 ? dir : !dir);
            cnt++;
        }
        cnt = 1;
        for (int pos = gearNum+1; pos <= right; pos++){
            _rotate(pos, cnt % 2 == 0 ? dir : !dir);
            cnt++;
        }
    }

    for(int i=0; i<t; i++){
        if (s[i][0] == '1') ret++;
    }

    cout << ret << "\n";

    return 0;
}