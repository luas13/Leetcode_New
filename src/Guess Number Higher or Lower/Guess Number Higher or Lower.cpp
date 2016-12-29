// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if (n<=0)
            return 0;
        int s =1;
        
        while (s<=n)
        {
            int mid = s + (n-s)/2;
            int v = guess(mid);
        
            if (!v)
                return mid;
            else if (v == -1)
                n = mid-1;
            else
                s = mid+1;
        }
        return -1;
    }
};