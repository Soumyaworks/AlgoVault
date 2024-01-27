//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int u,vector<vector<int>>& adj,stack<int>&st,vector<int>&visited){
	    visited[u]=1;
	    for(auto x:adj[u]){
	        if(!visited[x])
	            dfs(x,adj,st,visited);
	    }
	   // cout<<"u="<<u<<endl;
	    st.push(u);
	}
	
	vector<vector<int>> rev(int V, vector<vector<int>>& adj){
	    vector<vector<int>> rev_adj(V);
	    int i,j;
	    for(i=0;i<V;i++){
	        for(auto x:adj[i]){
	            rev_adj[x].push_back(i);
	        }
	    }
	    return rev_adj;
	}
	
	void rev_dfs(int u,vector<vector<int>>& rev_adj,stack<int>&st,vector<int>&visited){
	    visited[u]=1;
	    for(auto x:rev_adj[u]){
	        if(!visited[x]){
	            rev_dfs(x,rev_adj,st,visited);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int>st;
        int i,j,k;
        vector<int>visited(V,0);
        for(i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,st,visited);
            }
        }
        vector<vector<int>> rev_adj=rev(V,adj);
        int count=0;
        for(i=0;i<V;i++){
            visited[i]=0;
        }
        while(!st.empty()){
            i=st.top();
            // cout<<"i="<<i<<endl;
            st.pop();
            if(!visited[i]){
                rev_dfs(i,rev_adj,st,visited);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends