class Solution {
public:
    int compress(vector<char>& a) {
        int i = 0, cnt = 0, t = 0;
        for (int j = 0; j < a.size(); ++j) 
            if (j+1 == a.size() || a[j+1] != a[j]) 
            {
                int m = t;
                a[t++] = a[j];
                if (j > i) {
                    string s = to_string(j-i+1);
                    for (char c:s) a[t++] = c;
                }
                i = j + 1;
                cnt += t-m;
            }
        return cnt;
    }
};