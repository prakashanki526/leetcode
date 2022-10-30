class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid[0].size(), m = grid.size(), steps=0;
        vector<vector<int>> remains(m, vector<int>(n, INT_MIN));
        queue<array<int, 3>> q;
        q.push({0, 0, k});
        remains[0][0] = k;
        while (!q.empty()) {
            for (int it = q.size(); it > 0; it--) {
                auto cur = q.front(); q.pop();
                if (cur[0] == m - 1 && cur[1] == n - 1) return steps;
                // otherwise we can try 4 directions (up, down, left and right)
                for (int i = 0; i < 4; i++) {
                    // given we have at (x, y), we can move to (next_x, next_y)
                    int next_x = cur[0] + drow[i], next_y = cur[1] + dcol[i];
                    // however, first we need to make sure (next_x, next_y) is within the grid
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
                    // then, we check if we can eliminate an obstacle and move there
                    int remain = cur[2] - grid[next_x][next_y];
                    // we can only do that when `remain` is greater or equal to 0
                    // and the target remaining k must be less than the current remaining k
                    if(remain >= 0 && remains[next_x][next_y] < remain) {
                        // push to the queue for further process
                        q.push({next_x, next_y, remain});
                        // update the remaining k
                        remains[next_x][next_y] = remain;
                    }
                }
            }
            // increase step count
            steps += 1;
        }
        // if we reach here, 
        // then it means it is not possible to find such walk 
        return -1;
    }
};