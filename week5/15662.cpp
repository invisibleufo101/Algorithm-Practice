#include <bits/stdc++.h>
using namespace std;
int t,k,gearNum, dir;
string s;
vector<vector<int>>gears;
vector<pair<int,int>>turns;

void print(vector<vector<int>>v){
    cout << "------------------\n";
    for (int i=0; i<gears.size(); i++){
        cout << "Gear " << i+1 << ": ";
        for (int j=0; j<gears[i].size(); j++){
            cout << gears[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------------------\n";
}

vector<int> turnCounterClockwise(vector<int>v){
    rotate(v.begin(), v.begin()+1, v.end());
    return v;
}

vector<int> turnClockwise(vector<int>v){
    rotate(v.rbegin(), v.rbegin()+1, v.rend());
    return v;
}

// Check if there are gears on the left
// Then check if there's any gears on the right
// Record gears that need to be turned
// If the search on both left and right are finished,
// then turn each gear in their respective directions.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i=0; i<t; i++){
        cin >> s;
        vector<int>tmp;
        for (int j=0; j<s.size(); j++){
            tmp.push_back(int(s[j] - '0'));
        }
        gears.push_back(tmp);
    }

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> gearNum >> dir;
        turns.push_back({gearNum - 1, dir});
    }

    // Record how each gear has to turn in the future
    vector<int>scheduledTurns;

    // Index 2 & 6 are the ones that determine whether to turn or not
    for (int k=0; k<turns.size(); k++){
        int startPoint = turns[k].first;
        int selectedLeftPole = gears[turns[k].first][6];
        int selectedRightPole = gears[turns[k].first][2];
        int turnDir = turns[k].second;

        scheduledTurns.push_back(turnDir);

        // Check left side first
        for (int i=startPoint-1; i>=0; i--){
            int nextRightPole = gears[i][2];

            if (selectedLeftPole == nextRightPole){
                for (int j=i; j>=0; j--) scheduledTurns.push_back(0);
                break;
            } else if (selectedLeftPole != nextRightPole){
                if (turnDir == 1){
                    turnDir = -1;
                    scheduledTurns.push_back(turnDir);
                } else if(turnDir == -1){
                    turnDir = 1;
                    scheduledTurns.push_back(turnDir);
                }
            }

            int nextLeftPole = gears[i][6];
            selectedLeftPole = nextLeftPole;
        }

        reverse(scheduledTurns.begin(), scheduledTurns.end());
    
        selectedLeftPole = gears[turns[k].first][6];
        selectedRightPole = gears[turns[k].first][2];
        turnDir = turns[k].second;
        
        // Then check right 
        for (int i=startPoint+1; i<gears.size(); i++){
            int nextLeftPole = gears[i][6];
            if (selectedRightPole == nextLeftPole){
                for (int j=i; j<gears.size(); j++) scheduledTurns.push_back(0);
                break;
            } else if (selectedRightPole != nextLeftPole){
                if (turnDir == 1){
                    turnDir = -1;
                    scheduledTurns.push_back(turnDir);
                } else if (turnDir == -1){
                    turnDir = 1;
                    scheduledTurns.push_back(turnDir);
                }
            }

            int nextRightPole = gears[i][2];
            selectedRightPole = nextRightPole;
        }

        for (int i=0; i<scheduledTurns.size(); i++){
            if (scheduledTurns[i] == 1){
                gears[i] = turnClockwise(gears[i]);
            } else if (scheduledTurns[i] == -1){
                gears[i] = turnCounterClockwise(gears[i]);
            }
        }
        
        scheduledTurns.clear();
    }

    int cnt = 0;
    for (int i=0; i<gears.size(); i++){
        if (gears[i][0] == 1) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
