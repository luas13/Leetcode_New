// Soln 1
class Solution {
public:
    int lengthLongestPath(string input) {
        int l = input.length();
        if (!l)
            return l;
        
        vector<int> table(200);
        int i=0, len=0, filemode=0;
        
        while(i<l && input[i] != '\n')
        {
            if (input[i] == '.')
                filemode = 1;
            i++;
            len++;
        }
        cout<<len<<endl;
        
        // len+1 because of '/' term added
        table[0] = len+1;
        
        int maxlen = INT_MIN;
        if (filemode)
            maxlen = len;
        
        while(i<l)
        {
            int level = 0;
            filemode = 0;
            i++;
            
            while(input[i] == '\t')
            {
                level++;
                i++;
            }
            
            len = 0;
            while(i<l && input[i] != '\n')
            {
                if (input[i] == '.')
                    filemode = 1;
                i++;
                len++;
            }
            
            if (filemode)
                maxlen = max(maxlen, table[level-1]+len);
            
            table[level] = table[level-1] + len+1;
        }
        
        // if input is "aaaaaaaaaaaa", output should be 0
        return maxlen==INT_MIN? 0: maxlen;
    }
};

//---------------------
// Without push_back operation. Max no of levels taken to be 200 ~ 0ms
class Solution {
public:
    int lengthLongestPath(string input) {
        int l=input.length();
        if (!l)
            return 0;
        
        vector<int> table(200);
        
        int i=0;
        int filemode = 0;
        int len = 0;
        int maxlength= 0;
        
        while(i<l && input[i] != '\n')
        {
            if (input[i] == '.')
                filemode = 1;
            i++;
            len++;
        }
        //table.push_back(len+1);
        table[0] = len+1;
        
        if (filemode)
            maxlength = len;
        
        while (i<l)
        {
            int level=0;
            filemode =0;
            i++;
            
            // table[1] stores initial length of 1st level
            while (input[i] == '\t')
            {
                i++;
                level++;
            }
                 
            len=0;
            while(i<l && input[i] != '\n')
            {
                if (input[i] == '.')
                    filemode =1;
                i++;
                len++;
            }
            if (filemode)
                maxlength = max(maxlength, table[level-1] + len);
                
            if (table.size() <= level)
                table[level] = table[level-1] + len+1;
            else
                table[level] = table[level-1] + len+1;
            
        }
        return maxlength;
    }
};

/*
// No max level taken. ~3ms
class Solution {
public:
    int lengthLongestPath(string input) {
        int l=input.length();
        if (!l)
            return 0;
        
        vector<int> table;
        
        int i=0;
        int filemode = 0;
        int len = 0;
        int maxlength= 0;
        
        while(i<l && input[i] != '\n')
        {
            if (input[i] == '.')
                filemode = 1;
            i++;
            len++;
        }
        table.push_back(len+1);
        if (filemode)
            maxlength = len;
        
        while (i<l)
        {
            int level=0;
            filemode =0;
            i++;
            
            // table[1] stores initial length of 1st level
            while (input[i] == '\t')
            {
                i++;
                level++;
            }
                 
            len=0;
            while(i<l && input[i] != '\n')
            {
                if (input[i] == '.')
                    filemode =1;
                i++;
                len++;
            }
            if (filemode)
                maxlength = max(maxlength, table[level-1] + len);
                
            if (table.size() <= level)
                table.push_back(table[level-1] + len+1);
            else
                table[level] = table[level-1] + len+1;
            
        }
        return maxlength;
    }
};
*/
