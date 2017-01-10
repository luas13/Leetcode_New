class graph {
    int noV;
    // Pointer to an array containg adjacency list
    list<int>* adj;
    bool iscycleUtil(int v, bool* visited, bool* recstack);
public:
    graph(int noV);
    void addEdge(pair<int, int> p);
    bool iscycle();
};

graph::graph(int nov)
{
    this->noV = nov;
    adj = new list<int>[noV];
}

void graph::addEdge(pair<int, int> p)
{
    adj[p.second].push_back(p.first);
}

bool graph::iscycleUtil(int v, bool* visited, bool* recstack)
{
    // No need to do dfs for visited nodes
    if (!visited[v])
    {
        visited[v] = true;
        recstack[v] = true;
        
        for(auto it= adj[v].begin(); it != adj[v].end(); it++)
        {
            // this statement is needed for recursiveness
            if (!visited[*it] && iscycleUtil(*it, visited, recstack))
                return true;
            // to check if cycle exists or not
            else if (recstack[*it] == true)
                return true;
        }
    }
    
    // If it reaches here means there is no cycle with this node added
    // So make it false in recstack
    recstack[v] = false;
    return false;
}

bool graph::iscycle()
{
    bool* visited = new bool[noV];
    bool* recstack = new bool[noV];
    for(int i=0; i<noV; i++)
    {
        visited[i] = false;
        recstack[i] = false;
    }
    
    for(int i=0; i<noV; i++)
    {
        if (iscycleUtil(i, visited, recstack))
            return true;
    }
    
    return false;
}

// Simple dedecting a cycle in a graph using
// global visited array and recstack visited array
class Solution//: public graph
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int m = prerequisites.size();
        if (!m)
            return true;
        
        graph g(numCourses);
        for(int i=0; i<m; i++)
            g.addEdge(prerequisites[i]);
        
        if (g.iscycle())
            return false;
        else
            return true;
    }
};