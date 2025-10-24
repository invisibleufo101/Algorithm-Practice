#include <bits/stdc++.h>
using namespace std;

class Solution {
    // indices represent position
    // array[i] represents size
    // array[i] +/- sign represents direction (minus is left, plus is right)
    // if two asteroid collide, smaller one explode. if same size, both explode
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stck;
        for (auto asteroid : asteroids) {
            if (stck.empty()) {
                stck.push(asteroid);
                continue;
            }

            // The only case where asteroids collide is if stck.top() is positive and current asteroid is negative
            while(true) {
                // Check if it's a colliding case
                if (stck.size() && stck.top() > 0 && asteroid < 0) {
                    if (abs(stck.top()) > abs(asteroid)) { // If stck.top() is bigger, then break
                        break;
                    } else if (abs(stck.top()) < abs(asteroid)) { // If current asteroid is bigger, then delete the stck.top()
                        stck.pop();
                    } else { // Else, if two asteroids are same size, then delete the stck.top() and break
                        stck.pop();
                        break;
                    }
                } else { // Else, then add asteroid to the stack
                    stck.push(asteroid);
                    break;
                }
            }
        }

        vector<int>ret;
        while(stck.size()) {
            ret.push_back(stck.top());
            stck.pop();
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};