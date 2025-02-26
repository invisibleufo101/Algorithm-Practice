#include <bits/stdc++.h>
using namespace std;
int x;
vector<int>sticks;

int cut(int target){
    
    while (true){

        int sum = accumulate(sticks.begin(), sticks.end(), 0);

        if (sum == target){
            return sticks.size();
        } 
        
        if (sum > target){            
            // Cut the shortest stick in half
            int half = sticks.back() / 2;
            sticks.pop_back();

            // Rest of the stick length after the shortest has been cut off
            int rest = accumulate(sticks.begin(), sticks.end(), 0);

            if (half + rest > target){
                // Discard the other half
                sticks.push_back(half);
            } else if (half + rest < target){
                // Keep both 
                sticks.push_back(half);
                sticks.push_back(half);
            } else if (half + rest == target){
                // Add 1 to vector size to include the stick that was cut in half
                return sticks.size() + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> x;

    sticks.push_back(64);
    cout << cut(x) << "\n"; 

    return 0;
}