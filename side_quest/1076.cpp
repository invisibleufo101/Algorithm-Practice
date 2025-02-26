#include <bits/stdc++.h>
using namespace std;
string color1, color2, color3;
map<string, int>val;
map<string, int>mut;

long long int setup(string color, string mode){
    if (color == "black"){

        if (mode == "val"){
            return 0;
        } else if (mode == "mut"){
            return 1;
        }
    } else if (color == "brown"){
        if (mode == "val"){
            return 1;
        } else if (mode == "mut"){
            return 10;
        }
    } else if (color == "red"){
        if (mode == "val"){
            return 2;
        } else if (mode == "mut"){
            return 100;
        }
    } else if (color == "orange"){
        if (mode == "val"){
            return 3;
        } else if (mode == "mut"){
            return 1000;
        }
    } else if (color == "yellow"){
        if (mode == "val"){
            return 4;
        } else if (mode == "mut"){
            return 10000;
        }
    } else if (color == "green"){
        if (mode == "val"){
            return 5;
        } else if (mode == "mut"){
            return 100000;
        }
    } else if (color == "blue"){
        if (mode == "val"){
            return 6;
        } else if (mode == "mut"){
            return 1000000;
        }
    } else if (color == "violet"){
        if (mode == "val"){
            return 7;
        } else if (mode == "mut"){
            return 10000000;
        }
    } else if (color == "grey"){
        if (mode == "val"){
            return 8;
        } else if (mode == "mut"){
            return 100000000;
        }
    } else if (color == "white"){
        if (mode == "val"){
            return 9;
        } else if (mode == "mut"){
            return 1000000000;
        }
    }
}

int main(){
    cin >> color1 >> color2 >> color3;

    int val = setup(color1, "val")*10 + setup(color2, "val");

    long long int ret = val * setup(color3, "mut");
    cout << ret << "\n";

    return 0;
}