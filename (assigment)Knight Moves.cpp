#include <bits/stdc++.h>
using namespace std;

int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};


int kingmove(int rows,int cols,int sx,int sy,int tx,int ty){

    vector<vector<int>>level(rows,vector<int>(cols,-1));
    queue<pair<int,int>>q;

    q.push({sx,sy});
    level[sx][sy]=0;

    while(!q.empty()){

        pair<int,int>cur = q.front();
        q.pop();
        int x = cur.first,y= cur.second;
        if(x== tx && y== ty)
        return level[x][y];

        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0&&nx<rows && ny>=0 && ny<cols && level[nx][ny]==-1){
                level[nx][ny] = level[x][y] + 1;
                q.push({nx,ny});
            }
        }







    }

    return -1;

}

int main (){

int t;
cin>>t;
while(t--){

    int n,m,sx,sy,ex,ey;
    cin>>n>>m>>sx>>sy>>ex>>ey;

    cout<<kingmove(n,m,sx,sy,ex,ey)<<endl;
}




return 0;

}