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