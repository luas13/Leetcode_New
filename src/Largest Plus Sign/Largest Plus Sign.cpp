/*
Algorithms: For each position (i, j) of the grid matrix, we try to extend in each of the 
four directions (left, right, up, down) as long as possible, then take the minimum length 
of 1's out of the four directions as the order of the largest axis-aligned plus sign 
centered at position (i, j).

Optimizations: Normally we would need a total of five matrices to make the above idea work – 
one matrix for the grid itself and four more matrices for each of the four directions. However, 
these five matrices can be combined into one using two simple tricks:

    For each position (i, j), we are only concerned with the minimum length of 1's out of the 
    four directions. This implies we may combine the four matrices into one by only keeping 
    tracking of the minimum length.

    For each position (i, j), the order of the largest axis-aligned plus sign centered at it 
    will be 0 if and only if grid[i][j] == 0. This implies we may further combine the grid 
    matrix with the one obtained above.

Implementations:

    Create an N-by-N matrix grid, with all elements initialized with value N.
    Reset those elements to 0 whose positions are in the mines list.
    For each position (i, j), find the maximum length of 1's in each of the four directions 
    and set grid[i][j] to the minimum of these four lengths. Note that there is a simple 
    recurrence relation relating the maximum length of 1's at current position with previous 
    position for each of the four directions (labeled as l, r, u, d).
    Loop through the grid matrix and choose the maximum element which will be the largest 
    axis-aligned plus sign of 1's contained in the grid.


If loops are complicated check this out:

            for (int i = 0; i < N; i++) {

                for (int j=0, l=0; j < N; j++) {
                    // j is a column index, iterate from left to right
                    // every time check how far left it can reach.
                    // if grid[i][j] is 0, l needs to start over from 0 again, otherwise increment
                    grid[i][j] = Math.min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));
                }

                for (int k = N-1, r=0; k >= 0; k--) {
                    // k is a column index, iterate from right to left
                    // every time check how far right it can reach.
                    // if grid[i][k] is 0, r needs to start over from 0 again, otherwise increment
                    grid[i][k] = Math.min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));
                }

                for (int j = 0, u=0; j < N; j++) {
                    // j is a row index, iterate from top to bottom
                    // every time check how far up it can reach.
                    // if grid[j][i] is 0, u needs to start over from 0 again, otherwise increment
                    grid[j][i] = Math.min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));
                }

                for (int k = N-1, d=0; k >= 0; k--) {
                    // k is a row index, iterate from bottom to top
                    // every time check how far down it can reach.
                    // if grid[k][i] is 0, d needs to start over from 0 again, otherwise increment
                    grid[k][i] = Math.min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));
                }
                
                // after four loops each time taking Math.min over the grid value itself
                // all grid values will eventually take the min of the 4 direcitons.
            }

*/

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N,N));
        int order = INT_MIN;
        
        for(auto m : mines)
            grid[m[0]][m[1]] = 0;
        
        // loop over all rows, for each row we anyhow traverse in 4 directions
        // we need 2 indexes to loop inside j & k
        // we just need to check j<N, not for k, that will anyway work
        for(int i=0; i<N; i++)
        {
            for(int j=0, k=N-1, l=0, r=0, u=0, d=0; j<N, k>=0; j++, k--)
            {
                // left
                grid[i][j] = min(grid[i][j], l= grid[i][j] == 0? 0: l+1);
                // right
                grid[i][k] = min(grid[i][k], r= grid[i][k] == 0? 0: r+1);
                
                // up
                grid[j][i] = min(grid[j][i], u= grid[j][i] == 0? 0: u+1);
                // down
                grid[k][i] = min(grid[k][i], d= grid[k][i] == 0? 0: d+1);
            }
        }
        
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                order = max(order, grid[i][j]);
        
        return order;
    }
};