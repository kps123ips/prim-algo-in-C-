#include<iostream>
using namespace std;
const int V =5;
int minKey(int key[],bool Set[])
{
	int min = INT_MAX,min_value;
	for(int v=0;v<V;v++)
	if(Set[v]==false && key[v]<=min)
	min=key[v],min_value=v;
	return min_value;
}
int printMST(int parent[],int graph[V][V])
{
	cout<<"Edge \tWeight\n";
	for(int i = 0; i<V; i++)                      
	{ 
		
		cout<<parent[i]<<" - "<<i<<" \t "<<graph[i][parent[i]]<<" \n";  
	}
}
int prims(int graph[V][V])
{
	int parent[V];
	bool Set[V];
	int key[V];
	for(int i=0;i<V;i++)
	key[i]= INT_MAX, Set[i]=false;
	key[0]=0;
	parent[0]=-1;
	
	for(int c=0;c<V-1;c++)
	{
		int u = minKey(key,Set);
		Set[u]=true;
		for(int v=0;v<V;v++)
		if(graph[u][v]&&Set[V]==false  && graph[u][v]<key[v])
		parent[v]=u,key[v]=graph[u][v];
	}
	printMST(parent,graph);
}
int main()
{
	int graph[V][V] = {{0,4,0,0,0},{4,0,8,0,0},{0,0,8,0,0},{4,0,0,0,4},{8,0,0,4,0} };
	
	prims(graph);
	
	
	return 0;
}

