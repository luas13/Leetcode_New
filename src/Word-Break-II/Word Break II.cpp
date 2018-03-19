/*
Due to the addition of new test case this solution does not work.
TLE in 
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

Check second solution:

Soln: 1

  Thanks to haoel for the beautiful dp solution :)
  
  Notes:
  Define substring[i, j] is the sub string from i to j.

  It's better to evaluate it backward.Going backwards:
  if(substring[i,j] == word in dictionary) then   result[i] = substring[i,j] + { result[j] }

  For example

  s = "catsanddog",
  dict = ["cat", "cats", "and", "sand", "dog"].


string s at index {0 - 9 }                      result[i] at index {0 - 9 }
		                     +-----+
	  c	                     |  0  | -> { "cat sand dog" , "cats and dog" }  "cat"  -- word[0,2] + {result[3]}  ==> "cat sand dog"
		                     |     |                                         "cats" -- word[0,3] + {result[4]}  ==> "cats and dog"
				     +-----+                                         
	  a	                     |  1  | -> ""
		                     +-----+
	  t	                     |  2  | -> ""
		                     +-----+
	  s	                     |  3  | -> { "sand dog" }                       "sand" --  word[3,6] + {result[7]} ==> "sand dog" 
		                     +-----+
	  a	                     |  4  | -> { "and dog" }                        "and"  --  word[4,6] + {result[7]} ==> "and dog"
		                     +-----+
	  n	                     |  5  | -> ""
		                     +-----+
	  d	                     |  6  | -> "" 
		                     +-----+
	  d	                     |  7  | -> { "dog" }                            "dog"  --  word[7,9] will be pushed as j == s.size()
		                     +-----+
	  o	                     |  8  | -> ""
                                     +-----+
                                     |  9  | -> "" 
                                     +-----+
		
	( declaration of v which is basically an empty vector of strings — a vector that contains zero elements )

*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
    
    vector< vector<string> > result(s.size());

    for(int i=s.size()-1; i>=0; i--) 
    {
        vector<string> v;
        result[i] = v;
        for(int j=i+1; j<=s.size(); j++) 
	{
            string word = s.substr(i, j-i);
            if (dict.find(word) != dict.end())
		{
                    if (j==s.size())
		    {
                        result[i].push_back(word);
                    }
		    else
                    for(int k=0; k<result[j].size(); k++)
                        result[i].push_back(word + " " + result[j][k]);
                }
        } 
    }

    return result[0]; 
    }
};



____________________________________________________________________________________________________________

/*
2nd Soln: Using unordered_map to save whether a mini-solution 
for a substring exists. if present just return it.

Then use a recursive call to append soln.
*/

class Solution {
    unordered_map<string, vector<string>> mymap;
    unordered_set<string> myset;
    
    vector<string> combine(string word, vector<string> prev)
    {
        int i=0;
        for(string s: prev)
        {
            s = s + " " + word;
            prev[i++] = s;
        }
        return prev;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        myset.insert(wordDict.begin(), wordDict.end());
        
        if (mymap.find(s) != mymap.end())
            return mymap[s];
        
        vector<string> result;
        
        if (myset.find(s) != myset.end())
            result.push_back(s);
        
        // i starts from 1
	for(int i=1; i<s.size(); i++)
        {
            string tmp = s.substr(i);
            if (myset.find(tmp) != myset.end())
            {
                string prefix = s.substr(0, i);
                vector<string> vs = combine(tmp, wordBreak(prefix, wordDict));
                // insert in the end
		result.insert(result.end(), vs.begin(), vs.end());
            }
        }
        mymap[s] = result;
        return result;
    }
};
