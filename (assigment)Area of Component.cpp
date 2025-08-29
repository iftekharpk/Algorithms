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

int bfs(int startx,int starty){

int area = 0;
queue<pair<int,int>>q;
q.push({startx,starty});
visited[startx][starty]=true;

while(!q.empty()){
auto[x,y]=q.front();
q.pop();
area++;

for(int k =0;k<4;k++){

    
   
    int nx = x+ dx[k];
    int ny = y+dy[k];
    if(isvalid(nx,ny)){
    visited[nx][ny]= true;
    q.push({nx,ny});
}
}

}

return area;

}



int main (){


cin>>N>>M;
grid.resize(N);
for(int i=0;i<N;i++)
cin>>grid[i];



memset(visited,false,sizeof(visited));
int minarea=INT_MAX;
bool found=false;



for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){

        if(grid[i][j]=='.'&& !visited[i][j]){

            int area = bfs(i,j);
            minarea= min(minarea,area);
            found= true;
        }
    }
}

if(found)
cout<< minarea<<endl;
else
cout<<-1<<endl;



return 0;

}