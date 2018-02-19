/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/*
This problem is an application of graph traversal, which has two systematic methods: 
Bread-First Search (BFS) and Depth-First Search (DFS). In the following, I am going 
to assume that you are familiar with them and just focus on what I think is the most 
tricky part of this problem, that is, what else is needed beyond graph traversal to clone a graph?

In order to clone a graph, you need to have a copy of each node in the original graph. 
Well, you may not have too many ideas about it. Let’s do an example.

Suppose we are given a graph {0, 1 # 1, 0}. We know that the graph has two nodes 
0 and 1 and they are connected to each other.

We now start from 0. We make a copy of 0. Then we check 0's neighbors and we see 1. 
We make a copy of 1 and we add the copy to the neighbors of the copy of 0. 
Now the cloned graph is {0 (copy), 1 (copy)}. Then we visit 1. We make a copy of 1… 
well, wait, why do we make another copy of it? We already have one! Note that if you 
make a new copy of the node, these copies are not the same and the graph structure 
will be wrong! This is just what I mean by “the most tricky part of this problem”. 
In fact, we need to maintain a mapping from each node to its copy. If the node has 
an existed copy, we simply use it. So in the above example, the remaining process 
is that we visit the copy of 1 and add the copy of 0 to its neighbors and the cloned graph
is eventually {0 (copy), 1 (copy) # 1 (copy), 0 (copy)}.
*/

// BFS solution

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        mymap[node] = copy;
        queue<UndirectedGraphNode*> tovisit;
        tovisit.push(node);
        while(!tovisit.empty())
        {
            UndirectedGraphNode* curr = tovisit.front();
            tovisit.pop();
            // for (auto it= curr->neighbors.begin(); it!= curr->neighbors.end(); it++)
            for (auto neigh: curr->neighbors)
            {
                if (mymap.find(neigh) == mymap.end())
                {
                    UndirectedGraphNode* tmp = new UndirectedGraphNode(neigh->label);
                    mymap[neigh] = tmp;
                    tovisit.push(neigh);
                }
                mymap[curr]->neighbors.push_back(mymap[neigh]);
            }
        }
        return copy;
    }
    
private:
    map<UndirectedGraphNode*, UndirectedGraphNode*> mymap;
};


------------------------------------------------------------------------------------------------------
// DFS Solution
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* dfs(UndirectedGraphNode* v, map<int, UndirectedGraphNode*> &visited){
        UndirectedGraphNode* res= new UndirectedGraphNode(v->label);
        visited[v->label]= res;
        
        for(int i=0; i< v->neighbors.size(); i++){
            if( !visited[v->neighbors[i]->label] )
                res->neighbors.push_back( dfs(v->neighbors[i], visited));
            else
                res->neighbors.push_back( visited[v->neighbors[i]->label] );
        }
        
        return res;
    }
    
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        else{
            map<int, UndirectedGraphNode*> visited;
            UndirectedGraphNode* res= dfs(node,visited);
            return res;
        }
        
    }
};
