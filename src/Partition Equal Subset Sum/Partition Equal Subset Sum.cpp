/*
Check out these first:
https://discuss.leetcode.com/topic/63049/my-simple-c-dp-code-with-comments
https://discuss.leetcode.com/topic/62334/simple-c-4-line-solution-using-a-bitset

eg. [1, 1, 1, 5]
Initial bits array, let's say the size is 16

0000 0000 0000 0001

i=0: val= 1: 
    0000 0000 0000 0001
    0000 0000 0000 0010
    -------------------
    0000 0000 0000 0011
    
updated bits after i=0: 0000 0000 0000 0011
this shows that we can reach value 0 and value 1 after seeing the value 1

i=1: val =1:
    0000 0000 0000 0011
    0000 0000 0000 0110     // OR operation
    -------------------
    0000 0000 0000 0111
    
updated bits after i=1: 0000 0000 0000 0111
this shows that we can reach value 0, 1 & 2 after seeing value 1 again

i=2: val =1:
    0000 0000 0000 0111
    0000 0000 0000 1110     // OR operation
    -------------------
    0000 0000 0000 1111
    
updated bits after i=2: 0000 0000 0000 1111
this shows that we can reach value 0, 1, 2 & 3 after seeing value 1 again


i=3: val =5:
    0000 0000 0000 1111
    0000 0001 1110 0000     // OR operation
    -------------------
    0000 0001 1110 1111
    
updated bits after i=3: 0000 0001 1110 1111
this shows that we can reach value 
0, 1, 2, 3, 5, 6, 7, 8 after seeing value 5 but can't reach 4

Also check what we are doing is checking all the values which
can be reached just by previous bits << n (current no), meaning
it shows if we add n to 1 or n to 2 or n to 3, what all values
can be reached by using bitset


Check the dp solution using bool first to understand

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};
