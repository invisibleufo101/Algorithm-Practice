#include<bits/stdc++.h>
using namespace std;
string str;
string result = "";

int main(){
    getline(cin, str);

    for(int i=0; i<str.length(); i++){
        if (isupper(str[i])){

            result += char(int(str[i] + 13 - 65) % 26 + 65);
        }  else if (islower(str[i])){

            result += char(int(str[i] + 13 - 97) % 26 + 97);
        } else {
            result += str[i];
        } 
    }

    cout << result << "\n";

    return 0;
}