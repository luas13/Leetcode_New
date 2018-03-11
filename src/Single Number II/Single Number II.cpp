/*
!st check this solution:

To solve this problem using only constant space, you have to rethink how the 
numbers are being represented in computers – using bits. If you sum the ith bit 
of all numbers and mod 3, it must be either 0 or 1 due to the constraint of this 
problem where each number must appear either three times or once. This will be the 
ith bit of that “single number”.

A straightforward implementation is to use an array of size 32 to keep track of 
the total count of ith bit.
*/

int singleNumber(int A[], int n) {
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}

_______________________________________________________________________________________________________
/*
    ones as a bitmask to represent the ith bit had appeared once.
    twos as a bitmask to represent the ith bit had appeared twice.
    threes as a bitmask to represent the ith bit had appeared three times.

When the ith bit had appeared for the third time, clear the ith bit of both ones and twos to 0. The final answer will be the value of ones.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int twos, ones, threes;
        twos= 0, ones= 0;
        for(int i= 0; i<nums.size(); i++)
        {
            twos |= (ones & nums[i]);   //bitmask to represent the ith bit had appeared twice.
            ones ^= nums[i];            //bitmask to represent the ith bit had appeared once.
            
            threes = ones & twos;       //bitmask to represent the ith bit had appeared three times.
            ones = ones & ~threes;
            twos = twos & ~threes;
        }
       return ones; 
    }
};
