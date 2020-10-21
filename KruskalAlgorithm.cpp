#include<bits/stdc++.h>
using namespace std;

class Edge {
	public:
		int source, dest, weight;
};

bool compare(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
} 

int findParent(int v, int *parent) {
	if(parent[v] == v) {
		return v;
	}
	findParent(parent[v], parent);
}

void Kruskals(Edge *input, int n, int E) {
	sort(input, input+E, compare);
	Edge *output = new Edge[n-1];
	int *parent = new int[n];
	for(int i=0;i<n;i++) {
		parent[i] = i;
	}
	int i = 0, count = 0;
	while(count != n-1) {
		Edge currentEdge = input[i];
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);
		if(sourceParent != destParent) {
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destParent;
		}
		i++;
	}
	for(int i=0;i<n-1;i++) {
		if(output[i].source < output[i].dest) {
			cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		} else {
			cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}
	}
}

int main() {
	int n, E;
	cout<<"Enter number of vertices and number of edges:";
	cin>>n>>E;
	Edge *input = new Edge[E];
	for(int i=0;i<E;i++) {
		int s, d, w;
		cin>>s>>d>>w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	cout<<endl;
	cout<<"MST of the given graph is: "<<endl;
	Kruskals(input, n, E);
}
