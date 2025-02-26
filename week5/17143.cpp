#include <bits/stdc++.h>
using namespace std;
int r,c,m,sr,sc,ss,sd,sz;
int arr[104][104];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
struct shark{
    int num, y, x, speed, dir, sze;
};
map<int, shark>sharks;
map<pair<int,int>, vector<int>>pos;
int ret;

void print(){
    cout << "-----------------------\n";
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<int> getCoord(int y, int x, int speed, int dir){
    int vert = speed % (2 * (r - 1));
    int horz = speed % (2 * (c - 1));

    if (dir <= 1) {
        for (int i = 0; i < vert; i++) {
            y += dy[dir];
            if (y <= 0) {
                y = 2;
                dir = 1; 
            } else if (y > r) {
                y = r - 1;
                dir = 0; 
            }
        }
    } else if (dir >= 2) { 
        for (int i = 0; i < horz; i++) {
            x += dx[dir];
            if (x <= 0) {
                x = 2;
                dir = 2; 
            } else if (x > c) {
                x = c - 1;
                dir = 3; 
            }
        }
    }

    return {y, x, dir};
}

void addPos(int y, int x, int sharkNum){
    pos[{y,x}].push_back(sharkNum);
}

void erasePos(int y, int x, int sharkNum){
    vector<int>tmp;

    for (int k : pos[{y,x}]){
        if (k == sharkNum) continue;
        tmp.push_back(k);
    }

    pos.erase({y,x});
    if (tmp.size()) pos[{y,x}] = tmp;
}

void eatSharks(){
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            if (arr[i][j] >= 2){

                int maxSharkNum = -1;
                int maxSharkSize = -1;
                vector<int>fightSharks = pos[{i,j}];
                pos.erase({i,j});

                for (int k : fightSharks){
                    int curSharkSize = sharks[k].sze;
                    int curSharkNum = k;

                    if (curSharkSize > maxSharkSize){

                        sharks.erase(maxSharkNum);

                        maxSharkSize = curSharkSize;
                        maxSharkNum = curSharkNum;

                    } else {
                        arr[i][j]--;
                        sharks.erase(curSharkNum);
                    }
                }

                pos[{i,j}].push_back(maxSharkNum);
            } 
        }
    }
}

void moveSharks(){
    int tmpBuffer[104][104];
    memset(tmpBuffer, 0, sizeof(tmpBuffer));

    queue<shark>sharkQ;
    for (auto it : sharks) sharkQ.push(it.second);

    while(sharkQ.size()){
        shark curShark = sharkQ.front(); sharkQ.pop();
        int num = curShark.num;
        int y = curShark.y;
        int x = curShark.x;
        int speed = curShark.speed;
        int dir = curShark.dir;

        erasePos(y,x,num);

        vector<int>t = getCoord(y,x,speed,dir);

        y = t[0];
        x = t[1];
        dir = t[2];
        
        tmpBuffer[y][x]++;
        
        addPos(y,x,num);

        sharks[num].y = y;
        sharks[num].x = x;
        sharks[num].dir = dir;

        // if (tmpBuffer[y][x]){}
            // if (tmpBuffer[y][x].size > sharks[num].size){}
            // else sharks.erase(num)
        // else if (!tmpBuffer[y][x]){ tmpBuffer[y][x] = num}


    }
    memset(arr, 0, sizeof(arr));
    memcpy(arr, tmpBuffer, sizeof(arr));
}

void catchShark(){
    
    for (int j=1; j<=c; j++){
        for (int i=1; i<=r; i++){
            if (arr[i][j]){
                int caughtSharkKey = pos[{i,j}][0];

                ret += sharks[caughtSharkKey].sze;
                
                sharks.erase(caughtSharkKey);
                pos.erase({i,j});

                arr[i][j] = 0;

                break;
            }
        }

        moveSharks();
        eatSharks();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> m;
    for (int i=0; i<m; i++){
        cin >> sr >> sc >> ss >> sd >> sz;
        sharks[i+1] = {i+1, sr, sc, ss, sd-1, sz};
        pos[{sr, sc}].push_back(i+1);
        arr[sr][sc] = 1;
    }

    catchShark();

    cout << ret << "\n";

    return 0;
}