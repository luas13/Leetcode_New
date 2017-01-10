class graph
{
    int noV;
    list<int>* adj;
    bool iscycleUtil(int v, bool* visited, bool* recstack);
    void topologicalutil(int v, stack<int>& s, vector<bool>& visited);
public:
    graph(int noV);
    void addEdge(pair<int, int>);
    bool iscycle();
    stack<int> topologicalsort();
};

graph::graph(int nov)
{
    this->noV= nov;
    adj = new list<int>[nov];
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

void graph::topologicalutil(int v, stack<int>& s, vector<bool>& visited)
{
    visited[v] = true;
    
    for(auto it= adj[v].begin(); it != adj[v].end(); it++)
        if (!visited[*it])
            topologicalutil(*it, s, visited);
    s.push(v);
}

stack<int> graph::topologicalsort()
{
    vector<bool> visited(noV, false);
    
    stack<int> s;
    for(int i=0; i<noV; i++)
        if (!visited[i])
            topologicalutil(i, s, visited);
    return s;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int m= prerequisites.size();
        vector<int> result;
        if (!m)
        {
            for(int i=numCourses-1; i>=0; i--)
                result.push_back(i);
            return result;
        }
        
        graph g(numCourses);
        for(int i=0; i<m; i++)
            g.addEdge(prerequisites[i]);
            
        if (g.iscycle())
            return result;
            
        stack<int> s = g.topologicalsort();
        
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }
};