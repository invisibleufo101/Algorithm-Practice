#include <bits/stdc++.h>
using namespace std;

void printFourDirections(){

    int y=0, x=0;
    // Prints directions in clockwise (up, right, down, left)
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << ny << " : " << nx << "\n";
    }

    return;
}

void printEightDirections(){

    int y = 0, x = 0;
    // Prints directions in clockwise 
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    string directions[] = {"North", "NE", "East", "SE", "South", "SW", "West", "NW"};

    for (int i=0; i<8; i++){
        string direction = directions[i];
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << direction << " = " << ny << " : " << nx << "\n";
    }

    return;
}

int main(){
    printFourDirections();
    printEightDirections();
    return 0;
}