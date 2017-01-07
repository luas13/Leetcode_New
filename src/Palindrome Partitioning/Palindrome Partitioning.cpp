class Solution {
public:
    // Below code has O(n* 2^n) complexity but here ~189 ms
    // This is overall timing including time taken to create table
    // If ispalindrome() is not used and some table saves whether
    // is the substring palindrome or not, then time complexity would
    // come down O(2^n) but space compl O(n*n), can realise this as DP.
    
    void ispalindrome1(string str, vector<vector<int>>& arr)
    {
        for(int i=0;i<str.size();i++)
            arr[i][i]= 1;
            
        for(int i=0;i<str.size()-1;i++)
        {
            if(str[i] == str[i+1])
                arr[i][i+1]= 1;
        }
        
        int length=3;
        while(length<=str.size())
        {
            for(int i=0;i<=(str.size()-length);i++)
            {
                if(str[i]==str[(i+length-1)] && arr[i+1][(i+length-1)-1]== 1)
                {
                    arr[i][(i+length-1)]= 1;
                }
            }
            length++;
        }
    }
    
    void findallpartition(vector<vector<string>>& allpart, vector<string>& currpart, string s, int start, int l, vector<vector<int>> arr)
    {
        if (start>=l)
        {
            allpart.push_back(currpart);
            return;
        }
        
        // Pick all possible ending points for substrings
        for(int i=start; i<l; i++)
        {
            // If substring str[start..i] is palindrome
            //if (ispalindrome(s, start, i))
            if (arr[start][i])
            {
                // Add the substring to result
                currpart.push_back(s.substr(start, i-start+1));
                
                // Recur for remaining substring
                findallpartition(allpart, currpart, s, i+1, l, arr);
                
                // Remove substring str[start..i] from current partition
                currpart.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allpart;
        
        int l= s.length();
        if (!l)
            return allpart;
            
        vector<string> currpart;
        vector<vector<int>> arr(l, vector<int>(l, 0));
        ispalindrome1(s, arr);
        
        //for(int i=0; i<l; i++)
        //{
        //    for(int j=0; j<l; j++)
        //        cout<<arr[i][j]<<" ";
        //    cout<<endl;
        //}
        
        findallpartition(allpart, currpart, s, 0, l, arr);
        return allpart;
    }
};


/*
class Solution {
public:
    // Below code has O(n* 2^n) complexity
    
    // If ispalindrome() is not used and some table saves whether
    // is the substring palindrome or not, then time complexity would
    // come down O(2^n) but space compl O(n*n), can realise this as DP.
    
    int ispalindrome(string str, int s, int e)
    {
        while(s<e)
        {
            if (str[s] != str[e])
                return 0;
            s++;
            e--;
        }
        return 1;
    }
    
    //The problem has a nice structure that backtracking naturally fits in. The
    //structure is, given a starting position idx, we search from idx till the
    //end of the string s.length() - 1. Once we reach a position i such that 
    //the sub-string from idx to i (s.substr(idx, i - idx + 1)) is a palindrome,
    //we add it to a temporary tmp. Then we recursively call the same function 
    //to process the remaining sub-string. Once we reach the end of the string,
    //we add tmp into the result res of all the possible partitioning.
    
    //Then, backtracking happens! Remember that at position i, we find 
    //s.substr(idx, i - idx + 1) to be a palindrome and we immediately add it 
    //to tmp. It is obvious that there may be some position j such that j > i
    //and s.substr(idx, j - idx + 1) is also a palindrome. So we need to recover
    //to the state before adding s.substr(idx, i - idx + 1) to tmp and continue 
    //to find the next palindrome position after i. And we simply need to pop 
    //s.substr(idx, i - idx + 1) out of tmp to make things work.
    //Putting these together, we can write down the following code, 
    //which should be self-explanatory. Here replace idx by start
    
    // Simple Backtracking algo
    // Recursive function to find all palindromic partitions of str[start..n-1]
    // allPart --> A vector of vector of strings. Every vector inside it stores
    //           a partition
    // currPart --> A vector of strings to store current partition 
    
    void findallpartition(vector<vector<string>>& allpart, vector<string>& currpart, string s, int start, int l)
    {
        if (start>=l)
        {
            allpart.push_back(currpart);
            return;
        }
        
        // Pick all possible ending points for substrings
        for(int i=start; i<l; i++)
        {
            // If substring str[start..i] is palindrome
            if (ispalindrome(s, start, i))
            {
                // Add the substring to result
                currpart.push_back(s.substr(start, i-start+1));
                
                // Recur for remaining substring
                findallpartition(allpart, currpart, s, i+1, l);
                
                // Remove substring str[start..i] from current partition
                currpart.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allpart;
        
        int l= s.length();
        if (!l)
            return allpart;
            
        vector<string> currpart;
        
        findallpartition(allpart, currpart, s, 0, l);
        return allpart;
    }
};
*/