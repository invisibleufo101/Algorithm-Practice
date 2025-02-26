#include<bits/stdc++.h>
using namespace std;

vector<string> fasterSplit(const string& input, string delimiter) {
    vector<string>result;
    auto start = 0; 
    // datatype auto is kinda like a wildcard. It automatically sets into the data type that it is assigned
    // ex) auto start = 1 <- int, auto start = "yo" <- string
    auto end = input.find(delimiter);
    
    while (end != string::npos) {
        string token = input.substr(start, end - start);
        result.push_back(token);

        start = end + delimiter.length(); // <- new starting point for the next section of string to split
        end = input.find(delimiter, start); // Searches for the delimiter string after the start index
    }

    result.push_back(input.substr(start)); // <- Add the last bit of string section that has left (it doesn't have the delimiter string)
    
    return result;
}

int main(){
    string x = "Hey guys Kripperian here.";
    string splitter = " ";

    vector<string>results = fasterSplit(x, splitter);
    for (string i : results) {
        cout << i << "\n";
    }

    return 0;
}