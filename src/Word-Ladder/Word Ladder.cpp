// --------------------------- 
//  BFS non-recursive method
// ---------------------------
//
//    Using BFS instead of DFS is becasue the solution need the shortest transformation path.
//  
//    So, we can change every char in the word one by one, until find all possible transformation.
//
//    Keep this iteration, we will find the shorest path.
//
// For example:
//   
//     start = "hit"
//     end = "cog"
//     dict = ["hot","dot","dog","lot","log","dit","hig", "dig"]
//
//                      +-----+                  
//        +-------------+ hit +--------------+   
//        |             +--+--+              |   
//        |                |                 |   
//     +--v--+          +--v--+           +--v--+
//     | dit |    +-----+ hot +---+       | hig |
//     +--+--+    |     +-----+   |       +--+--+
//        |       |               |          |   
//        |    +--v--+         +--v--+    +--v--+
//        +----> dot |         | lot |    | dig |
//             +--+--+         +--+--+    +--+--+
//                |               |          |   
//             +--v--+         +--v--+       |   
//        +----> dog |         | log |       |   
//        |    +--+--+         +--+--+       |   
//        |       |               |          |   
//        |       |    +--v--+    |          |   
//        |       +--->| cog |<-- +          |   
//        |            +-----+               |   
//        |                                  |   
//        |                                  |   
//        +----------------------------------+   
//     
//     1) queue <==  "hit"
//     2) queue <==  "dit", "hot", "hig"
//     3) queue <==  "dot", "lot", "dig"
//     4) queue <==  "dog", "log" 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> myqueue;
        map<string, int> mymap;
        unordered_set<string> myset(wordList.begin(), wordList.end());
        
	// in case endWord is not present in wordList
        if (myset.find(endWord) == myset.end())
            return 0;
        
        myqueue.push(beginWord);
        mymap[beginWord] = 1;
        
        while(!myqueue.empty())
        {
            string s= myqueue.front();
            myqueue.pop();
            
            if (beginWord == endWord)
                break;
            
            string tmp = s;
            
            for(int i=0; i<s.length(); i++)
            {
                s = tmp;
                for(char c='a'; c<='z'; c++)
                {
                    if (s[i] != c)
                    {
                        s[i] = c;
                        if (s == endWord)
                        {
                            mymap[s] = mymap[tmp] + 1;
                            return mymap[s];
                        }
                        else
                        {
                            if (myset.find(s) != myset.end() && mymap.find(s) == mymap.end())
                            {
                                cout<<s<<endl;
                                myqueue.push(s);
                                mymap[s] = mymap[tmp] + 1;
                            }
                        }
                    }
                }
            }
        }

        return mymap[endWord];
    }
};


	
