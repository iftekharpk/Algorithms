#include <bits/stdc++.h>
using namespace std;




int N,M;

vector<string>grid;

bool visited[1005][1005];

int mtx[4]={1,-1,0,0};
int mty[4]={0,0,1,-1};

bool isvalid(int x,int y)
{
    return (x>=0 && x<N && y>=0 && y<M && (grid[x][y]== '.'||grid[x][y]=='B') && !visited[x][y]);
}
bool dfs(int x,int y){
if(grid[x][y]=='B')
return true;
    visited[x][y]=true;
    for(int i =0; i<4;i++){

        int nx=x + mtx[i];
        int ny=y + mty[i];
        if(isvalid(nx,ny)){

            if (dfs(nx,ny))
            return true;
        }
    }
return false;

}



int main(){

cin>>N>>M;
grid.resize(N);


int ax,ay;

for(int i=0;i<N;i++){

cin>>grid[i];


}



for(int i=0;i<N;i++){
    cin>>grid[i];

    for(int j=0;j<M;j++){

if(grid[i][j] == 'A') {


ax= i;
ay = j;
   
}

    }
}

if(dfs(ax,ay))
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
return 0;

}