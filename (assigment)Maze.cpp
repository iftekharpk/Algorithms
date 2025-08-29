#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<string>maze;


int dx[4] = {0,0,-1,1};
int dy[4]= {1,-1,0,0};





int main (){


cin>>N>>M;
maze.resize(N);

int startx = -1,starty=-1,endx=-1,endy=-1;

for(int i=0;i<N;i++){

    cin>>maze[i];
    for(int j =0;j<M;j++){

        if(maze[i][j]=='R'){
            startx=i;
            starty=j;
        }

if(maze[i][j]=='D'){

    endx =i;
    endy =j;
}

    }
}

vector<vector<pair<int,int>>>parent(N,vector<pair<int,int>>(M,{-1,-1}));
vector<vector<bool>>visited(N,vector<bool>(M,false));
queue<pair<int,int>>q;

q.push({startx,starty});
visited[startx][starty]=true;
bool found = false;

while(!q.empty()&& !found){
auto cur = q.front();
q.pop();
int x = cur.first;
int y=cur.second;

for(int i=0;i<4;i++){
int nx= x+dx[i];
int ny= y+dy[i];


if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && (maze[nx][ny]=='.'|| maze[nx][ny]=='D')){

visited[nx][ny]=true;
parent[nx][ny]={x,y};
q.push({nx,ny});
if(maze[nx][ny]=='D'){
found = true;
break;

}

}




}
}


if(found){

int x= endx;
int y= endy;
while(!(x==startx && y == starty)){

int px = parent[x][y].first;
int py = parent [x][y].second;
if(!(px== startx && py == starty))
maze[px][py]='X';
x= px;
y=py;




}



}

for(int i = 0; i<N;i++){
cout<< maze[i]<<endl;

}


return 0;

}