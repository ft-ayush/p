#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int parent[N];
int size[N];

void make(int v){
	parent[v]=v;
	size[v]=1;

}

int find(int v){
	if(v==parent[v]){
		return v;
	}

	return parent[v]=find(parent[v]);
}


void Union(int a,int b){
	a=find(a);
	b=find(b);

	if(a!=b){
		if(size[a]<size[b]){
			swap(a,b);
		}

		parent[b]=a;
		size[a]+=size[b];

	}

}





int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>>edges;

	for(int i =0 ;i <m ; ++i){
		int x,y,w;
		cin>>x>>y>>w;
		edges.push_back({w,{x,y}});



	}

	for(int i =0 ;i <=n;++i ) make(i);

	sort(edges.begin(),edges.end());

	int total_coast=0;
	for(auto &edges:edges){
		int wt=edges.first;
		int u=edges.second.first;
		int v=edges.second.second;
		if(find(u)==find(v)) continue;
		Union(u,v);
		
		total_coast+=wt;
		cout<<u<<" "<<v<<endl;
	}

	cout<<total_coast<<endl;

}