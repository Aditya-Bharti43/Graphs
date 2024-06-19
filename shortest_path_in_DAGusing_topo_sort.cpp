#include<bits/stdc++.h>
using namespace std;


void toposort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st)
{
  vis[node]=1;
   
   for(auto it:adj[node])
   {
    int v=it.first;

    if(!vis[v])
    {
        toposort(v,adj,vis,st);
    }

   }


  st.push(node);
}

// here we intend to find the shotest path from a given node in a directed acyclic graph using the
// topololgical sorting technique


vector<int>shortestPath(int N,int M,vector<int>edges[])
{

// we create the adjacency list 
// the adjacney list stores pairs i.e {node,weight}

vector<pair<int,int>>adj[N];

for(int i=0;i<M;i++)
{
    int u=edges[i][0];
    int v=edges[i][1];
    int wt=edges[i][2];

    adj[u].push_back({v,wt});
}
// n is number of nodes and m is the number of edges in the graph

// we have to consider the source as the node 0.

// we perform topological sorting 



int vis[N]={0};
stack<int>st;

for(int i=0;i<N;i++)
{
    if(!vis[i])
    {
        toposort(i,adj,vis,st);
    }
}
  vector<int>dust(N);
  for(int i=0;i<N;i++) dist[i]=1e9;

  dist[0]=0;

  while(!st.empty())
  {
    int node=st.top();
    st.pop();

    for(auto it:adj[node])
    {
        int v=it.first;
        int wt=it.second;

        if(dist[node]+wt <dist[v])
        {
            dist[v]=dist[node]+wt;
        }
    }
  }


return dist;
}

signed main()
{

}