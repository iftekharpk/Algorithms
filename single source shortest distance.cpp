#include <bits/stdc++.h>
using namespace std;


vector<int>adj_list[1005];
bool vis[1005];
int lavel[1005];
void bfs(int src){

queue<int>q;
q.push(src);
vis[src]= true;
lavel[src]=0;

while(!q.empty()){


    int par = q.front();
    q.pop();

for(int child : adj_list[par]){


if(!vis[child]){

    q.push(child);
    vis[child]= true;
    lavel[child]=lavel[par]+1;
}
}

}

}







int main (){

int n ,e;
cin>>n>>e;

while(e--){

int a,b;
cin>>a>>b;
adj_list[a].push_back(b);
adj_list[b].push_back(a);  // undirected

}
memset(vis,false,sizeof(vis));
int src,dst;
cin>>src>>dst;
bfs(src);   

for(int i=0;i<n;i++){

    cout<<i<< " -> "<<lavel[i]<<endl;
}


return 0;

}