#include <bits/stdc++.h>
using namespace std;
string s,r;
vector<char>v;
stack<char>stck;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> r;
    
    for (int i=0; i<s.size(); i++){

        stck.push(s[i]);

        // If current char is equal to the last char of the target
        // Take out all the elements equal to the size of the target
        // If the total is equal to target, do nothing
        // Else, put them back in
        if (s[i] == r.back() && stck.size() >= r.size()){
            int iter = r.size();
            string buffer;

            while(iter--){
                buffer += stck.top();
                stck.pop();
            }

            reverse(buffer.begin(), buffer.end());

            if (buffer != r){
                for(int j=0; j<buffer.size(); j++){
                    stck.push(buffer[j]);
                }
            }
        }
    }

    if (stck.size()){
        string ret = "";
        while(stck.size()){
            ret += stck.top();
            stck.pop();
        }

        reverse(ret.begin(), ret.end());
        cout << ret << "\n";
    } else {
        cout << "FRULA\n";
    }

    return 0;
}