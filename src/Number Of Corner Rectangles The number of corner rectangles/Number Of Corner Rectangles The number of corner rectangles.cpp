/*

Given a grid where each entry is only 0 or 1, find the number of corner rectangles.

A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. 
Note that only the corners need to have the value 1. Also, all four 1s used must 
be distinct.

Example 1:

Input: grid =
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
Output: 1
 Explanation: There is only one corner rectangle, with corners grid [1] [2], 
 grid [1] [4], grid [3] [2], grid [3] [4].
Example 2:

Input: grid =
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
 Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, 
 and one 3x3 rectangles.
Example 3:

Input: grid =
[[1, 1, 1, 1]]
Output: 0
 Explanation: Rectangles must have four distinct corners.
Note:

The number of rows and columns of gridwill each be in the range [1, 200].
Each grid[i][j]will be either 0or 1.
The number of 1s in the grid will be at most 6000.


Answer:

Principle of two traversal at the same time, if the two columns in the same 
column position value of 1, then the counter cnt increase by 1, then the 
last is equivalent to a (Cnt - 1) adjacent lattices, the problem is transformed 
into how many rectangles can be formed by cnt-1 adjacent lattices, which becomes 
the math problem of junior high school. There are cnt * (cnt-1) / 2 

*/


class Solution{
public:
	int countCornerRectangles (Vector <Vector < int >> & Grid) {
		int r = Grid.size();
		int c = Grid[0].size();
		int result = 0;
		
		// i & j are for travelling two rows at a time
		// & checking whether both values are 1
		for(int i=0; i<r; i++)
		{
			for(int j=i+1; j<r; j++)
			{
				int count = 0;
				for(int k=0; k<c; k++)
				{
					if (Grid[i][k] == 1 && Grid[j][k] == 1)
						count++;
				}
				result += count*(count-1)/2;
			}
		}
		return result;
	}
}