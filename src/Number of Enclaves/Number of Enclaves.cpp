class Solution {
public:
    void dfs_boundary(vector<vector<int>>& A, int i, int j, int R, int C){
        if (!A[i][j])
            return;
        A[i][j]=0;
        if (i+1 < R && A[i+1][j])
            dfs_boundary(A, i+1, j, R, C);
        if (i-1 >= 0 && A[i-1][j])
            dfs_boundary(A, i-1, j, R, C);
        if (j-1 >= 0 && A[i][j-1])
            dfs_boundary(A, i, j-1, R, C);
        if (j+1 < C && A[i][j+1])
            dfs_boundary(A, i, j+1, R, C);
    }
    
    void dfs(vector<vector<int>>& A, int i, int j, int R, int C, int& count){
        if (!A[i][j])
            return;
        
        A[i][j]=0;
        count++;
        
        if (i+1 < R && A[i+1][j])
            dfs(A, i+1, j, R, C, count);
        if (i-1 >= 0 && A[i-1][j])
            dfs(A, i-1, j, R, C, count);
        if (j-1 >= 0 && A[i][j-1])
            dfs(A, i, j-1, R, C, count);
        if (j+1 < C && A[i][j+1])
            dfs(A, i, j+1, R, C, count);
    }
    int numEnclaves(vector<vector<int>>& A) {
        int count=0;
        int R = A.size();
        int C = A[0].size();
        
        for (int i=0; i< R; i++)
            for (int j=0; j<C; j++)
            if (!i || !j || i==R-1 || j==C-1)
                dfs_boundary(A, i, j, R, C);
        
        for (int i=1; i< A.size()-1; i++)
            for (int j=1; j<A[0].size()-1; j++)
            {
                dfs(A, i, j, R, C, count);
            }
        
        return count;
    }
};