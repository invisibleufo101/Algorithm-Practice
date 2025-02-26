#include <bits/stdc++.h>
using namespace std;
string password;
map<char, int>vowel_mp;
map<char, int>consonant_mp;

// Check priority list
// 1. Check if the same 2 letters come in twice (except for oo and ee)
// 2. Check if consonants or vowels are coming in 3 times consecutively
// 3. Check if password has at least 1 vowel (a,e,i,o,u)
bool check(string password){
    bool hasVowel = 0;
    stack<char>stck;
    for (int i=0; i<password.length(); i++){
        char ltr = password[i];

        // If 2 same letters are consecutively coming in
        // except for 'ee' and 'oo'
        if (stck.size()){
            if (stck.top() == ltr){
                if (stck.top() != 'o' && stck.top() != 'e'){
                    return false;
                } 
            } 

            // Check if more than 2 letters have stacked
            // so that we can compare the third one to the last two letters
            if (stck.size() >= 2){
                // If letter is vowel
                if (vowel_mp[ltr]){
                    // Compare the current letter to the last one (stck.top())
                    // AND the one before that (password[i-2])
                    if (vowel_mp[stck.top()] && vowel_mp[password[i-2]]){
                        return false;
                    }
                } else { // If letter is consonant
                    if (consonant_mp[stck.top()]){
                        // Compare the current letter to the last one (stck.top())
                        // AND the one before that ( password[i-2] )
                        if (consonant_mp[stck.top()] && consonant_mp[password[i-2]]){
                            return false;
                        }
                    }
                }
            }
        }

        if (vowel_mp[ltr]){
            hasVowel = 1;
        }

        stck.push(ltr);
    }
    // Finally check if there's a vowel
    return hasVowel;
}

int main(){

    vowel_mp['a'] = 1;
    vowel_mp['e'] = 1;
    vowel_mp['i'] = 1;
    vowel_mp['o'] = 1;
    vowel_mp['u'] = 1;

    for (int i=0; i<26; i++){
        char x = i + 'a';
        if (!vowel_mp.count(x)){
            consonant_mp[x] = 1;
        }
    }

    while (cin >> password && password != "end"){
        if (check(password)){
            cout << "<" + password + "> is acceptable.\n";
        } else {
            cout << "<" + password + "> is not acceptable.\n";
        }
    }
    return 0;
}