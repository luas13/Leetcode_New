// Think of 3x3 matrix, first Swap the end points, top left, top right
// bottom left, bottom right & make sure they are in their correct place
// Then the middle diamond elements
// So we 1st make the outer boundary to it's rotated position, then
// enter to inner boundary and change it to their rotated position

/*
while loop controls the radius of the boundary as it decreases inwards
& for loop make sure each element in current boundary reaches it's 
rotated position

Example image:

1 2 3
4 5 6
7 8 9

a=0 & b=2 in this case

while loop runs once bcz after completeion of 1st for loop
a = 1 & b= 1 & this violates the while condition

    1)
        for loop calls 3 swap function each till b-a (twice in this case)
        1st
            1st swap changes 3 <-> 1
            3 2 1
            4 5 6
            7 8 9

            2nd swap changes 3 <-> 9
            9 2 1
            4 5 6
            7 8 3

            3rd swap changes 9 <-> 7
            7 2 1
            4 5 6
            9 8 3

        2nd
            1st swap changes 2 <-> 6
            7 6 1
            4 5 2
            9 8 3

            2nd swap changes 6 <-> 8
            7 8 1
            4 5 2
            9 6 3

            3rd swap changes 8 <-> 4
            7 4 1
            8 5 2
            9 6 3
            
 5 remains untouched
 at the end, result is
 
 7 4 1
 8 5 2
 9 6 3

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        
        // this loop controls the radius of the boundary
        // as it decreases
        while(a < b)
        {
            // this loop changes one boundary elements to it's
            // rotated positions
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



// In case you need it ANTI-clockwise
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
                // 1 trick, write matrix[a+i][b] thrice
                swap(matrix[a+i][b], matrix[a][a+i]);
                swap(matrix[a+i][b], matrix[b-i][a]);
                swap(matrix[a+i][b], matrix[b][b-i]);
            }
            
            a++;
            b--;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
};
