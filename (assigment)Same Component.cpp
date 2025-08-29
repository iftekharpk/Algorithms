#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<string>grid;
bool visited[1005][1005];

int dx[4] = {1,-1,0,0};
int dy[4]= {0,0,1,-1};


bool isvalid(int x, int y){

    return(x>=0&&x<N&&y>=0&&y<M&& !visited[x][y]&&grid[x][y]=='.');
}

void dfs(int x,int y){

    visited[x][y]= true;
    for(int k =0;k<4;k++){
    int nx = x+ dx[k],ny = y+dy[k];
    if(isvalid(nx,ny))
    dfs(nx,ny);
}
}

int main (){


cin>>N>>M;
grid.resize(N);
for(int i=0;i<N;i++)
cin>>grid[i];
int si,sj,di,dj;
cin>>si>>sj>>di>>dj;

if(grid[si][sj]=='-'||grid[di][dj]=='-'){

    cout<<"NO\n";
    return 0;
}

dfs(si,sj);
if(visited[di][dj]){

    cout<<"YES\n";
}
else{

    cout<<"NO\n";
}




return 0;

}