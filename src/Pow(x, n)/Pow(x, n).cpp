class Solution {
public:
    double myPow(double x, long long int n) {
        if (!n)
            return double(1);
        if (n == 1)
            return x;
        if (n == -1)
            return 1/x;
        if (n & 1)
        {
            if (n > 0)
                return x * myPow(x, n-1);
            else
                return ((1/x) * myPow(x, n+1));
        }
        else
        {
            double tmp = myPow(x, n/2);
            return tmp * tmp;
        }
    }
};