#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
vector<vector<int>>arr;
vector<int>ret;

void print(vector<vector<int>>a){
    cout << "----------------\n";
    for (int i=0; i<n; i++){
        for (int j : a[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "----------------\n";
}

// Edge Number
// 1: North, 2: West, 3: South, 4: East
void cutOffEdge(int edgeNum){
    vector<vector<int>>v;
    if (edgeNum == 1){

        for (int i=1; i<n; i++){
            vector<int>temp;
            for (int j=0; j<m; j++){
                temp.push_back(arr[i][j]);
            }
            v.push_back(temp);
        }

        // Since we took off the 0th row, subtract value of n
        n = n-1;
        arr = v;

    } else if (edgeNum == 2){

        for (int i=0; i<n; i++){
            vector<int>temp;
            for (int j=1; j<m; j++){
                temp.push_back(arr[i][j]);
            }
            v.push_back(temp);
        }

        // Since we took off the 0th col, subtract value of m
        m = m-1;
        arr = v;

    } else if (edgeNum == 3){

        for (int i=0; i<n-1; i++){
            vector<int>temp;
            for (int j=0; j<m; j++){
                temp.push_back(arr[i][j]);
            }
            v.push_back(temp);
        }
        
        // Since we took off the last row, subtract value of n
        n = n-1;
        arr = v;

    } else if (edgeNum == 4){

        for (int i=0; i<n; i++){
            vector<int>temp;
            for (int j=0; j<m-1; j++){
                temp.push_back(arr[i][j]);
            }   
            v.push_back(temp);
        }   

        // Since we took off the last col, subtract value of m
        m = m-1;
        arr = v;
    }
}

vector<int> getNumbersHorizontal(){

    vector<int>rowNums;
    for (int i=0; i<n; i++){
        string rowNum = "";
        for (int j=0; j<m; j++){
            rowNum += to_string(arr[i][j]);
        }
        rowNums.push_back(atoi(rowNum.c_str()));
    }

    int iN1 = rowNums[0];
    int iN3 = rowNums.back();
        
    int rowSum = accumulate(rowNums.begin(), rowNums.end(), 0);

    int edgeNum = -1; 
    int mx = 0;

    if (iN1 > iN3){
        edgeNum = 1;
        mx = iN1;
    } else if (iN1 < iN3){
        edgeNum = 3;
        mx = iN3;
    } else if (iN1 == iN3){
        edgeNum = 1;
        mx = iN1;
    }

    return {rowSum, edgeNum, mx};
}

vector<int> getNumbersVertical(){

    vector<int>colNums;
    for (int j=0; j<m; j++){
        string colNum = "";
        for (int i=0; i<n; i++){
            colNum += to_string(arr[i][j]);
        }
        colNums.push_back(atoi(colNum.c_str()));
    }
    
    int iN2 = colNums[0];
    int iN4 = colNums.back();

    int colSum = accumulate(colNums.begin(), colNums.end(), 0);
    int edgeNum = -1;
    int mx = 0;

    if (iN2 > iN4){
        edgeNum = 2;
        mx = iN2;
    } else if (iN2 < iN4){
        edgeNum = 4;
        mx = iN4;
    } else if (iN2 == iN4){
        edgeNum = 2;
        mx = iN2;
    }

    return {colSum, edgeNum, mx};
}

int cmp(){
    
    vector<int>horz = getNumbersHorizontal();
    vector<int>vert = getNumbersVertical();

    if (horz[0] > vert[0]){

        ret.push_back(horz[2]);
        return horz[1];
    } else if (horz[0] < vert[0]){

        ret.push_back(vert[2]);
        return vert[1];
    }

    ret.push_back(horz[2]);
    return horz[1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> s;
        vector<int>buffer;
        for (int j=0; j<m; j++){
            buffer.push_back(s[j] - '0');
        }
        arr.push_back(buffer);
    }

    while (true){
    
        int edge = cmp();
        cutOffEdge(edge);

        print(arr);

        if (n == 1){

            string lastNum = "";
            for (int j : arr[0]){
                lastNum += to_string(j);
            }
            ret.push_back(atoi(lastNum.c_str()));

            break;
        } else if (m == 1){

            string lastNum = "";
            for (auto row : arr){
                lastNum += to_string(row[0]);
            }
            ret.push_back(atoi(lastNum.c_str()));
            
            break;
        }
    }

    for (int i : ret) cout << i << " ";
    cout << "\n";

    int sum = accumulate(ret.begin(), ret.end(), 0);
    cout << sum << "\n";

    return 0;
}

// 3 4
// 2000
// 0012
// 0001

// 4 4
// 0000
// 0005
// 0000
// 5110
