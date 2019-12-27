class Solution {

    void dfs_helper(vector<vector<char>>& grid, int i, int j, int R, int C)
    {
        if ( i >= R || j >= C)
        {
            return;
        }

        if (i < 0 || j < 0)
        {
            return;
        }

        assert(i < R);
        assert(j < C);

        if (grid[i][j] == '#'|| grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '#';

        dfs_helper(grid, i + 1, j , R, C);
        dfs_helper(grid, i - 1, j, R, C);
        dfs_helper(grid, i , j + 1, R, C);
        dfs_helper(grid, i, j - 1, R, C);
    }

    public:
    int numIslands(vector<vector<char>>& grid) 
    {

        int cnt = 0;
        int R = grid.size();

        if (!R) return 0;

        int C = grid[0].size();

        if (!C)
        {
            return 0;
        }


        for (int i = 0; i < R ; i++)
        {
            for (int j = 0; j < C; j++)
            {
                printf("at i:%d j:%d\n", i, j);
                if (grid[i][j] == '1')
                {
                    cnt++;
                    dfs_helper(grid, i, j, R, C);
                }

            }
        }

        return cnt;

    }

}; 
