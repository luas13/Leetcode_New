/*
We calculate the LPS of the new string which is string + "#" + mirrored_string
LPS[i] = for string [0 to i], it is length of the longest proper suffix which is
also the longest proper prefix.

Here len = length of longest proper prefix which is also proper suffix for 
the substring [0 to i-1]
*/

void computeLPS(string pat, int* lps, int n)
{
	lps[0] = 0;
	int len = 0;
	int i = 1;
	while(i < n)
	{
		if (pat[i] == pat[len])
		{
			lps[i] = len + 1;
			i++;
			len++;
		}
		else
		{
			if (len != 0)
				len = lps[len - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}

}

class Solution {
public:
    string shortestPalindrome(string s) {
        int l = s.length();
	    string s_with_mirror = s + '#' + string(s.rbegin(), s.rend());

	    int* lps = (int*)malloc(sizeof(int) * (2*l + 1));
	    computeLPS(s_with_mirror, lps, (2*l+1));

	    int pos = s.length() - lps[2*l];
	    
	    free(lps);
	    
	    return string(s.rbegin(), s.rbegin() + pos) + s;
    }
};
