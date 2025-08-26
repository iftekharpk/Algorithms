#include <bits/stdc++.h>
using namespace std;
int main()


{

int N,E;
cin>>N>>E;

vector<vector<int>>adj(N);
for(int i =0;i<E;i++){

int a,b;
cin>>a>>b;
adj[a].push_back(b);

}


int Q;
cin>>Q;
while(Q--){

int A,B;
cin>>A>>B;

if(A==B){

    cout<<"YES\n";
    continue;


}

if(find(adj[A].begin(),adj[A].end(),B) !=adj[A].end())

cout<<"YES\n";

else
cout<<"NO\n";
}

return 0;

}