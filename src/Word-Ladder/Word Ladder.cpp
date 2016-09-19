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
    int ladderLength(string start, string end1, unordered_set<string> &dict) {
    
    queue<string> q;
    map<string,int> change;
    q.push(start);
    change[start]= 1;
  
    while( !q.empty() )
	{
		string s=q.front();
		string temp=s;
		q.pop();

		if(s == end1)
			break;

		for(int i=0; i<s.length(); i++)
		{
			s=temp;
			for(char c='a'; c<='z'; c++)
			{
				if(s[i] != c)
				{
					s[i]=c;

					if(s == end1)
                                        {
                    	                    change[end1]=change[temp] + 1;
                    	                    return change[end1];
                                        }
                    
                                        else{
			                if(dict.find(s) != dict.end() && change.find(s) == change.end() )
			                {
			                    q.push(s);
                                            change[s]= change[temp] + 1;
			                }
                                        }
		                }
	                }
	        }

	}
	return change[end1];
        
    }
};


	
