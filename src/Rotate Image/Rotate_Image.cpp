// Think of 3x3 matrix, first Swap the end points, top left, top right
// bottom left, bottom right & make sure they are in their correct place
// Then the middle diamond elements
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        
        while(a < b)
        {
            for(int i=0; i<(b-a); i++)
            {
                // 1 trick, write matrix[a][a+i] thrice
                // On right side, column becomes row, like b->b, b-i -> b-i
                // end with starting row
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            
            a++;
            b--;
        }
    }
};