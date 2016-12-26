class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        for(int i=0; i<=num; i++)
        {
            int tones = 0;
            int j = i;
            while(j != 0)
            {
                j = j & (j-1);
                tones++;
            }
            result[i] = tones;
        }
        return result;
    }
};