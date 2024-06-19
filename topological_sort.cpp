#include<bits/stdc++.h>
using namespace std;


// topological sorting is only valid for directed acyclic graph 
// in toplogical sorting if a node is coming before a node in the graph ,then that node will come after that particular node in  the ordering  

void call_dfs(int node,vector<int>adj[],int vis[],stack<int>&st)
{
    vis[node]=1;
      

    for(auto it:adj[node]){
        if(!vis[it]){
           call_dfs(it,adj,vis,st);
        }
    }

    // we have a stack now
     st.push(node);
    

}


vector<int>topoSort(int V,vector<int>adj[])
{
//   calling component wise nodes int he graph
   int vis[V]={0};
   vector<int>vec;
   stack<int>st;

   for(int i=0;i<V;i++){
    if(!vis[i]){
        call_dfs(i,adj,vis,st);
    }
   }
   while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }

   return vec;

}



signed main()
{

}