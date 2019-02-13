class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> parent(m*n, -1);
        int directs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int cur_ans = 0;
        vector<int> ans;
        for(auto p : positions){
            bool connected = false;
            int idp = p.first * n + p.second;
            if(parent[idp] == -1) parent[idp] = idp;
            for(int d=0; d<4; ++d){
                int x = p.first + directs[d][0];
                int y = p.second + directs[d][1];
                if(!(x >=0 && x < m && y>=0 && y<n)) continue;
                int idx = x * n + y;
                if(parent[idx] != -1) {
                    if(merge(parent, idx, idp) && connected) --cur_ans;
                    connected = true;
                }
            }
            if(!connected) ++cur_ans;
            ans.push_back(cur_ans);

        }
        return ans;
    }
    int find_root(vector<int>& parent, int x){
        int root_x = x;
        while(parent[root_x] != root_x){
            root_x = parent[root_x];
        }
        int tmp;
        while(parent[x] != x){
            tmp = parent[x];
            parent[x] = root_x;
            x = tmp;
        }
        return root_x;
    }
    bool merge(vector<int>& parent, int x, int y){
        x = find_root(parent, x);
        y = find_root(parent, y);
        if(x != y){
            parent[x] = y;
            return true;
        }
        return false;
    }
    
};
