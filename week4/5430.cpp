#include <bits/stdc++.h>
using namespace std;
int t;
string p;
int n;
string x;

deque<int> split(string input, string delimiter){
    deque<int>ret;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos){
        ret.push_back(atoi(input.substr(start, end-start).c_str()));
        start = end + delimiter.length();
        end = input.find(delimiter, start);
    }

    ret.push_back(atoi(input.substr(start).c_str()));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> p; // string of commands
        cin >> n; // number of elements
        cin >> x; // array represented in string

        bool hasError = 0;
        string direction = "frontToBack";
        deque<int>tmp;

        // Getting rid of brackets
        x.erase(0,1);
        x.pop_back();

        if (n == 0) tmp = {};
        else tmp = split(x, ",");
        
        for (int i=0; i<p.length(); i++){
            char instruction = p[i];

            if (instruction == 'R'){

                if (direction == "frontToBack"){
                    direction = "backToFront";
                } else if (direction == "backToFront"){
                    direction = "frontToBack";
                }
            } else if (instruction == 'D'){
                
                if (!tmp.size()){
                    hasError = 1;
                    break;
                }

                if (direction == "frontToBack"){
                    tmp.pop_front();
                } else if (direction == "backToFront"){
                    tmp.pop_back();
                }
            }
        }

        // Print result
        if (hasError){
            cout << "error\n";
        } else {
            cout << "[";
            if (direction == "frontToBack"){

                while (tmp.size()){
                    if (tmp.size() == 1){
                        cout << tmp.front();
                    } else {
                        cout << tmp.front() << ",";
                    }
                    tmp.pop_front();
                }

            } else if (direction == "backToFront"){

                while (tmp.size()){
                    if (tmp.size() == 1){
                        cout << tmp.back();
                    } else {
                        cout << tmp.back() << ",";
                    }
                    tmp.pop_back();
                }

            }
            cout << "]\n";
        }
    }

    return 0;
}