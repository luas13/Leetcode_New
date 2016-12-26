class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (!r)
            return 0;
        int c = matrix[0].size();
        if (r == 1 && c == 1)
            return matrix[0][0] - '0';
        
        int max_area = 0;
        
        // Given matrix contains char matrix, we need integer matrix
        // To optimise space we just use 2rows with no of columns same as given matrix 
        // and not r rows of given matrix
        
        //This problem can be done by taking just 1 row also, i.e. O(n) space
        
        vector<int> introwpair(c,0);
        for (int i =0; i<c; i++)
        {
            introwpair[i] = matrix[0][i] - '0';
            if (introwpair[i])
                max_area = 1;
        }
        
        for (int i=0; i<r; i++)
        {
            if (matrix[i][0] - '0')
                max_area = 1;
        }

        int maxv = INT_MIN;
        
        for (int i=1; i<r; i++)
        {
            int diaog = introwpair[0];
            introwpair[0] = matrix[i][0] - '0';
            
            for (int j=1; j<c; j++)
            {
                //cout<<left<<endl;
                int tmp;
                if (matrix[i][j] == '1')
                {
                    tmp = introwpair[j];
                    introwpair[j] = min (diaog, min(introwpair[j-1], introwpair[j])) + 1;
                    diaog = tmp;
                }
                else 
                {
                    tmp = introwpair[j];
                    introwpair[j] = 0;
                    diaog = 0;
                }
                    
                if (maxv <= introwpair[j])
                    maxv = introwpair[j];
                //cout<<"introwpair[j] "<<introwpair[j]<<endl;
            }
        }
        
        if (maxv == INT_MIN)
            return max_area;
        else
            return max(max_area, maxv*maxv);
        
        return max_area;
        
    }
};


/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (!r)
            return 0;
        int c = matrix[0].size();
        if (r == 1 && c == 1)
            return matrix[0][0] - '0';
        
        int max_area = 0;
        //int maxi= 0;
        //int maxj =-1;
        
        // Given matrix contains char matrix, we need integer matrix
        // To optimise space we just use 2rows with no of columns same as given matrix 
        // and not r rows of given matrix
        
        //This problem can be done by taking just 1 row also, i.e. O(n) space. See above
        
        vector<vector<int>> introwpair(2,vector<int>(c,0));
        for (int i =0; i<c; i++)
        {
            introwpair[0][i] = matrix[0][i] - '0';
            if (introwpair[0][i])
            {
                max_area = 1;
                //maxj = j;
            }
        }
        
        for (int i=0; i<r; i++)
        {
            if (matrix[i][0] - '0')
                max_area = 1;
        }

        int maxv = INT_MIN;
        
        for (int i=1; i<r; i++)
        {
            introwpair[i%2][0] = matrix[i][0] - '0';
            
            for (int j=1; j<c; j++)
            {
                if (matrix[i][j] == '1')
                    introwpair[i%2][j] = min (introwpair[i%2][j-1], min(introwpair[1-i%2][j-1], introwpair[1-i%2][j])) + 1;
                else 
                    introwpair[i%2][j] = 0;
                    
                if (maxv <= introwpair[i%2][j])
                {
                    maxv = introwpair[i%2][j];
                    //maxi = i;
                    //maxj = j;
                }
            }
        }
        
        if (maxv == INT_MIN)
            return max_area;
        else
            return max(max_area, maxv*maxv);
        
        return max_area;
        
    }
};
*/