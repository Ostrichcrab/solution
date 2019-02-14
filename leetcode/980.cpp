class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    pair<int,int> S,T;
    int n,m,ans;
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(x<0||x>=n||y<0||y>=m||grid[x][y]==3||grid[x][y]==-1) return ;
        grid[x][y] = 3;
        if(x==T.first&&y==T.second)
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(grid[i][j]==0){
                        grid[x][y]=0;
                        return ;
                    }
            ans++;
            grid[x][y]=0;
            return ;
        }
        for(int i = 0; i < 4; i++){
            int tx = x + dx[i], ty = y + dy[i];
            dfs(grid,tx,ty);
        }
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j]==1){
                    S = make_pair(i,j);
                    grid[i][j]=0;
                }else if(grid[i][j]==2){
                    T = make_pair(i,j);
                    grid[i][j]=0;
                }
        ans = 0;
        dfs(grid,S.first,S.second);
        return ans;
    }
};