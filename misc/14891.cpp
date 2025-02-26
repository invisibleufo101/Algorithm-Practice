#include <bits/stdc++.h>
using namespace std;
int gearNum, turnDir,t;
string s;
vector<vector<int>>gears;
vector<pair<int,int>>instr;


vector<int> rotateClockwise(vector<int>t){
    rotate(t.rbegin(), t.rbegin()+1, t.rend());
    return t;
}

vector<int> rotateCounterClockwise(vector<int>t){
    rotate(t.begin(), t.begin()+1, t.end());
    return t;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i=0; i<4; i++){
        cin >> s;
        vector<int>gear;
        for (int j=0; j<s.size(); j++){
            gear.push_back(s[j] - '0');
        }
        gears.push_back(gear);
    }

    cin >> t;
    for (int i=0; i<t; i++){
        cin >> gearNum >> turnDir;
        instr.push_back({gearNum - 1, turnDir});
    }

    for (int i=0; i<instr.size(); i++){
        int curGear = instr[i].first;
        int turnDir = instr[i].second;

        int curLeft = gears[curGear][6];
        int curRight = gears[curGear][2];

        vector<int>scheduledTurns;

        scheduledTurns.push_back(turnDir);

        // Starting from curPoint -> Left
        for (int j=curGear-1; j>=0; j--){
            int nextLeft = gears[j][6];
            int nextRight = gears[j][2];

            if (curLeft == nextRight){
                for (int k=j; k>=0; k--) scheduledTurns.push_back(0);
                break;
            } else if (curLeft != nextRight){
                turnDir = turnDir == 1 ? -1 : 1;
                scheduledTurns.push_back(turnDir);
            }

            curLeft = nextLeft;
        }

        reverse(scheduledTurns.begin(), scheduledTurns.end());

        curLeft = gears[curGear][6];
        curRight = gears[curGear][2];
        turnDir = instr[i].second;

        for (int j=curGear+1; j<gears.size(); j++){
            int nextLeft = gears[j][6];
            int nextRight = gears[j][2];

            if (curRight == nextLeft){
                for (int k=j; k<gears.size(); k++) scheduledTurns.push_back(0);
                break;
            } else if (curRight != nextLeft){
                turnDir = turnDir == 1 ? -1 : 1;
                scheduledTurns.push_back(turnDir);
            }

            curRight = nextRight;
        }

        for (int i=0; i<scheduledTurns.size(); i++){
            if (scheduledTurns[i] == 1) gears[i] = rotateClockwise(gears[i]);
            else if (scheduledTurns[i] == -1) gears[i] = rotateCounterClockwise(gears[i]);
        }

        scheduledTurns.clear();
    }

    int ret = 0;
    if (gears[0][0] == 1) ret++;
    if (gears[1][0] == 1) ret += 2;
    if (gears[2][0] == 1) ret += 4;
    if (gears[3][0] == 1) ret += 8;

    cout << ret << "\n";

    return 0;
}