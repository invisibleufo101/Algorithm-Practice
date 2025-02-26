#include <bits/stdc++.h>
using namespace std;

int matrix [10][10];
int visited[10];

void print(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void visit(int from){
    visited[from] = 1;
    cout << from << "\n";

    for (int to=0; to<10; to++){
        if (visited[to]) {
            continue; // <- Skip visiting the already visited node
        }

        if (matrix[from][to]) {
            visit(to);
        }
    }  

    return;
}

int main() {
    matrix[1][2] = 1; matrix[2][1] = 1;

    matrix[1][3] = 1; matrix[3][1] = 1;

    matrix[3][4] = 1; matrix[4][3] = 1;

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (matrix[i][j] && visited[i] == 0){
                visit(i);
            }
        }
    }
    
    return 0;
}