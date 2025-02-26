#include<bits/stdc++.h>
using namespace std;
string name, ret, reversed_ret;
map<char, int>mp;

int main(){
    cin >> name;
    for (int i=0; i<name.length(); i++){
        mp[name[i]]++;
    }    

    // When String has odd length
    if (name.size()%2 == 1){
        int odd_cnt = 0;
        string odd_chr;
        
        // Check if there is more than one odd number of characters
        for (auto i: mp){
            if (i.second%2 == 1){
                odd_cnt++;
                odd_chr = i.first;
            }
        }
        
        if (odd_cnt > 1) cout << "I'm Sorry Hansoo\n";
        else {
            // Make the palindrome
            for (auto i: mp){
                ret += string(i.second / 2, i.first);
            }
            reversed_ret = ret;
            reverse(reversed_ret.begin(), reversed_ret.end());
            ret += odd_chr + reversed_ret;
            cout << ret << "\n";
        }
            
    } else { // When the string has even length
        int odd_cnt = 0;
         
        for (auto i : mp){
            if (i.second%2 == 1){
                odd_cnt++;
            }
        }

        // Check if there are ANY odd number of characters in the string
        if (odd_cnt > 0) cout << "I'm Sorry Hansoo\n";
        else {
            // Make palindrome
            for (auto i: mp){
                ret += string(i.second/2, i.first);
            }
            reversed_ret = ret;
            reverse(reversed_ret.begin(), reversed_ret.end());
            ret += reversed_ret;
            cout << ret << "\n";
        }
    }
    return 0;
}