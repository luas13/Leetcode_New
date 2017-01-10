class Solution {
public:
    // ab % k = (a%k)(b%k)%k
    const int base = 1337;
    int powmod(int a, int k)
    {
        a %= base;
        int result = 1;
        for (int i=1; i<=k; i++)
            result = (result * a) % base;
        return result;
    }
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};