#include<bits/stdc++.h>
using namespace std;

vector<string> split(string input_string, string delimiter){
    vector<string> return_string_vector;
    long long position = 0;
    string token = "";

    while ((position = input_string.find(delimiter)) != string::npos){
        
        token = input_string.substr(0, position);
        return_string_vector.push_back(token);
        input_string.erase(0, position + delimiter.length());
    }

    return_string_vector.push_back(input_string);
    return return_string_vector;
}

int main(){
    string x = "Hello what a beautiful world!";
    string splitter = " ";

    vector<string>a = split(x, splitter);
    // for (string b: a){
    //     cout << b << "\n";
    // }

    return 0;
}