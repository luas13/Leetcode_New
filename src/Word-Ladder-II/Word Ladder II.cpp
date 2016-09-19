/*
Note:

The problem is about to find all possible paths between two nodes in a graph. To get the paths, it is normal to use DFS
(Depth First Search). The drawback to apply DFS is, unlike tree, there exist many circles in a graph. Most depth first
routes will not reach the target and will be extremely time-consuming.

Meanwhile, BFS (Breadth First Search) will help to reach the target quickly (i.e. find the shortest path from start to
end), like what we have seen in Word Ladder question. However, BFS visits nodes layer by layer and does not maintain 
the paths of nodes from start to end.

It is interesting to consider the data structure to use for the algorithm. For the BFS, queue is not a fit in this case because
all connections between layer i and layer i+1 need to be collected. Queue-based BFS like in Word Ladder question actually will 
lose those information. It is recommended to use map<string, unordered_set> in this case.



// Solution
//
//      1) Using BFS algorithm build a tree like below
//      2) Using DFS to parse the tree to the transformation path.
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

For dict = {"hot","dot","dog","lot","log"}

parents<string, unordered_set>  :

string              unordered_set
hit                 -> hot
  hot                 -> dot,lot

    dot                 -> dog
    lot                 -> log
  
      dog                 -> cog
      log                 -> cog
      
*/


class Solution {
public:
    
    map< string, unordered_set<string> >& buildTree(string& start, string& end1, unordered_set<string> &dict) 
    {

        static map< string, unordered_set<string> > parents;
        parents.clear();                                 // to avoid runtime error in OJ


        unordered_set<string> prevlevel ;
        unordered_set<string> currlevel ;
        unordered_set<string> newlevel ;
    
        currlevel.insert(start);

        bool flag=false;
    
        while( !flag )
        {
            newlevel.clear();

            for(unordered_set<string>::iterator it=currlevel.begin(); it != currlevel.end(); it++)
            {
                for(int i=0; i<(*it).size(); i++)
                {
                    string word= (*it);
                    for(char c='a'; c<='z'; c++)
                    {
                        word[i]=c;
                        
                        if(word == end1)
                        {
                            //vvi to make flag true otherwise if Input: "a", "c", ["a","b","c"] then 
                            //output is [["a","c"],["a","b","c"]] while Expected: [["a","c"]] 
                            
                            flag=true;                
                            parents[*it].insert(word);
                            continue;
                        }
                        
                        //in BFS, when testing if a node can be added to the new level we only need to test 
                        //if it has been visited in the previous two levels (dry run n see)
                        //If a new node is adjacent to any node in a level older than these two, it would 
                        //have been added already.
                        
                        if(dict.count(word) == 0 || prevlevel.count(word) > 0 || currlevel.count(word) > 0)
                            continue;
    
                        newlevel.insert(word);
                        parents[*it].insert(word);
                    }
                }
            }
    
            if(newlevel.empty())
                flag=true;
    
            prevlevel = currlevel;
            currlevel = newlevel;

        }
        
        if ( !flag ) {
            parents.clear();
        } 
        
        return parents;
    
    }
    
    void generatePath(map< string, unordered_set< string > >& parents,string start,string end1,
                                         vector< vector<string> >& paths, vector<string>& path)
    {
        if(parents.find(start) == parents.end() )
        {
            if (start == end1)
                paths.push_back(path);
            return;
        }

        for(unordered_set< string >::iterator it= parents[start].begin(); it != parents[start].end(); it++)
        {
            //Simple Backtracking mechanism
            
            path.push_back(*it);
            generatePath(parents,*it,end1,paths,path);
            path.pop_back();
        }
    }

    
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
    {
    
        vector< vector<string> > ladders;
        vector<string> ladder;
        ladder.push_back(start);
    
        if (start == end){
            ladder.push_back(end);
            ladders.push_back(ladder);
            return ladders;
        }

        map< string, unordered_set<string> >& parents = buildTree(start, end, dict);

        if  (parents.size()<=0) {
            return ladders;
        }

        generatePath(parents,start,end,ladders,ladder);

        return ladders;
        
    }
};

