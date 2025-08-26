#include <bits/stdc++.h>
using namespace std;


int main(){

int N,E;
cin>>N>>E;
vector<vector<int>>adj(N);

for(int i =0;i<E;i++){

    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

for(int i=0;i<N;i++){
    sort(adj[i].rbegin(),adj[i].rend());

}

int Q;
cin>>Q;
while(Q--){

    int X;
    cin>>X;
    if(adj[X].empty()){

        cout<<-1<<endl;
    }
    else{

        for(int node: adj[X]){

            cout<<node<<" ";
        }
        cout<<endl;
    }
}
return 0;

}