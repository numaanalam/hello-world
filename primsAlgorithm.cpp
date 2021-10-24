
/*
Prims Algorithm is used to find the minimum spanning tree(MST) in the graph
*/
#include <iostream>
#include <set>
#include <vector>

const int N = 1e5+3;
#define INF 1e9
using namespace std;

vector<bool> vis(N);
vector<int> parent(N), dist(N); //Initialized to 0
vector<vector<int>> g[N]; // node1 -> {node2, weight}
int cost=0;
int n,m;

void primsMST(int src){
	for(int i=0; i<n; i++){
		dist[i]=INF;
	}
	set<vector<int>> s;
	dist[src]=0;
	s.insert({0, src});
	while(!s.empty()){
		auto x = *(s.begin());
		s.erase(x);
		int u = x[1];
		int v = parent[u];
		int w = x[0];
		cost += w;
		vis[u]=1;
		cout<<u<<" "<<v<<" "<<w<<endl;

		for(auto i: g[u]){
			if(vis[i[0]])
				continue;
			if(dist[i[0]]>i[1]){
				s.erase({dist[i[0]], i[0]});
				dist[i[0]]=i[1];
				s.insert({dist[i[0]], i[0]});
				parent[i[0]] = u;
			}
		}
	}
}
int main(){

	cin>>n>>m;
	for(int i=0; i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	primsMST(0);
	cout<<"\nMinimum Cost: "<<cost;

	return 0;
}

