class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>dy = {0,1,0,-1};
        vector<int>dx = {1,0,-1,0};
        vector<vector<int>> visited(10, vector<int>(10,0));
        vector<int>v;

        int n = matrix.size();
        int m = matrix[0].size();

        int dir = 0;
        int y = 0; int x = 0;

        for (int i=0; i<n*m; i++) {
            visited[y][x] = 1;
            v.push_back(matrix[y][x]);

            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) {
                dir = (dir + 1) % 4;
                ny = y + dy[dir];
                nx = x + dx[dir];
            }

            y = ny;
            x = nx;
        }

        return v;
    }
};
