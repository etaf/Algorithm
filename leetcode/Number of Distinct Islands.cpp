class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        set<vector<pair<int, int>>> S;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = -1;
                    bfs(i, j, grid, S);
                }
            }
        }
        return S.size();
    }
    void bfs(int start_x, int start_y, vector<vector<int>>& grid, set<vector<pair<int, int>>>& S) {
        int m = grid.size();
        int n = grid[0].size();
        std::queue<std::pair<int, int>> Q;
        Q.push(std::make_pair(start_x, start_y));
        int directs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<pair<int,int>> path;
        while(!Q.empty()){
            std::pair<int, int> now = Q.front();
            Q.pop();
            int x = now.first;
            int y = now.second;

            for(int d = 0; d < 4; ++d){
                int x1 = x + directs[d][0];
                int y1 = y + directs[d][1];
                if(x1 >= 0 && x1 < m && y1 >=0 && y1 < n && grid[x1][y1] == 1) {
                    Q.push(std::make_pair(x1, y1));
                    grid[x1][y1] = -1;
                    path.push_back(make_pair(x1 - start_x, y1 - start_y));
                }
            }
        }
        S.insert(path);
    }
};
