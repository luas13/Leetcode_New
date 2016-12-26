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