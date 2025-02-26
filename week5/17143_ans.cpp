#include <bits/stdc++.h>
using namespace std;
int r,c,m,sr,sc,ss,sd,sz,ret;
struct shark{
    int y,x,speed,dir,size,death;
} sharks[10004];
int arr[104][104], temp[104][104];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

// ny = (y + move) % (2 * r - 1)
// nx = (x + move) % (2 * c - 1)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> m;
    for (int i=1; i<=m; i++){
        cin >> sharks[i].y >> sharks[i].x >> sharks[i].speed >> sharks[i].dir >> sharks[i].size;
        sharks[i].y--; sharks[i].x--; sharks[i].dir--;

        if (sharks[i].dir <= 1) sharks[i].speed %= (2 * (r-1));
        else sharks[i].speed %= (2 * (c-1));

        arr[sharks[i].y][sharks[i].x] = i;
    }

    for (int t=0; t<c; t++){
        // Catch shark
        for (int y=0; y<r; y++){
            if (arr[y][t]){
                sharks[arr[y][t]].death = 1;
                ret += sharks[arr[y][t]].size;
                arr[y][t] = 0;
                break;
            }
        }

        // Reset temp array so that we can accurately record the destination coords
        // for each shark
        memset(temp, 0, sizeof(temp));

        // Sharks moving
        // Index starts at 1 because index number == shark number
        for (int i=1; i<=m; i++){
            if (sharks[i].death) continue;

            int y = sharks[i].y;
            int x = sharks[i].x;
            int speed = sharks[i].speed;
            int dir = sharks[i].dir;
            int ny,nx;

            while(true){
                // Calculate the destination coordinates
                ny = y + speed * dy[dir];
                nx = x + speed * dx[dir];

                // If the destination coordinate is in normal range, break
                if (ny < r && ny >= 0 && nx < c && nx >= 0) break;

                // If the destination is out of bounds,
                // Vertical
                if (dir == 0 || dir == 1){
                    // If going less than 0,
                    if (ny < 0){
                        // Get the remaining blocks that the shark needs to travel
                        // after hitting the wall
                        speed -= y; 
                        y = 0;
                    // If going over,
                    } else if (ny >= r) {
                        // Get the remaining blocks after hitting the wall
                        speed -= (r - 1 - y);
                        y = r - 1;
                    }
                // Horizontal
                } else if (dir == 2 || dir == 3) {
                    // Same thing as above
                    if (nx < 0){
                        speed -= x;
                        x = 0;
                    } else if (nx >= c){
                        speed -= (c - 1 - x);
                        x = c - 1;
                    }
                }

                // Toggle (Up, Down), (Left, Right) with XOR operator
                // 0 <-> 2 == (000) <=> (010)
                // 1 <-> 3 == (001) <=> (011)
                dir ^= 1;
            }

            // Bigger shark eats the smaller shark
            if (temp[ny][nx]){
                // If the newly arrived shark is bigger than the shark that's already there,
                if (sharks[temp[ny][nx]].size < sharks[i].size){
                    sharks[temp[ny][nx]].death = 1; // original shark is eaten
                    temp[ny][nx] = i; // mark the winner
                } else { 
                    // If the original shark is bigger, mark the new arrival as dead
                    sharks[i].death = 1; 
                }
            } else {
                // IF there's no sharks, the mark the map with the shark's number
                temp[ny][nx] = i;
            }

            sharks[i].y = ny;
            sharks[i].x = nx;
            sharks[i].dir = dir;
        }

        // Copy the final coordinates of sharks after they move 
        // and are done eating each other
        memcpy(arr, temp, sizeof(temp));
    }

    cout << ret << "\n";

    return 0;
}