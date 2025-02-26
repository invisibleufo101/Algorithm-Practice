#include <bits/stdc++.h>
using namespace std;
int n; 
int team;
string cur_goal_time, prev_goal_time;

string convert(int total){
    string min = "00" + to_string(total / 60);
    string sec = "00" + to_string(total % 60);

    return min.substr(min.length() - 2, 2) + ":" + sec.substr(sec.length() - 2, 2);
}

// Convert the duration of win time in seconds
int getSum(string cur, string prev){
    int cur_min = atoi(cur.substr(0,2).c_str());
    int cur_sec = atoi(cur.substr(3).c_str());
    int cur_total = cur_min * 60 + cur_sec;

    int prev_min = atoi(prev.substr(0,2).c_str());
    int prev_sec = atoi(prev.substr(3).c_str());
    int prev_total = prev_min * 60 + prev_sec;

    return cur_total - prev_total;
}

int main(){
    cin >> n;
    int score_one=0, score_two=0;
    int total_one=0, total_two=0;
    while (n--){
        cin >> team >> cur_goal_time;

        if (score_one > score_two){
            total_one += getSum(cur_goal_time, prev_goal_time);
        } else if (score_two > score_one){
            total_two += getSum(cur_goal_time, prev_goal_time);
        }

        team == 1 ? score_one++ : score_two++;

        prev_goal_time = cur_goal_time;
    }

    if (score_one > score_two){
        total_one += getSum("48:00", prev_goal_time);
    } else if (score_two > score_one){
        total_two += getSum("48:00", prev_goal_time);
    }

    cout << convert(total_one) << "\n";
    cout << convert(total_two) << "\n";
    return 0;
}