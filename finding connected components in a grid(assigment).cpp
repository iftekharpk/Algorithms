#include <bits/stdc++.h>
using namespace std;




int N,M;

vector<string>grid;

bool visited[1005][1005];

int mtx[4]={1,-1,0,0};
int mty[4]={0,0,1,-1};

bool isvalid(int x,int y)
{
    return (x>=0 && x<N && y>=0 && y<M && grid[x][y]== '.'&& !visited[x][y]);
}
int dfs(int x,int y){

    visited[x][y]=true;
    int cnt = 1;
    for(int i =0; i<4;i++){

        int nx=x + mtx[i];
        int ny=y + mty[i];
        if(isvalid(nx,ny)){

            cnt += dfs(nx,ny);
        }
    }
return cnt;

}



int main(){

cin>>N>>M;
grid.resize(N);

for(int i=0;i<N;i++){

cin>>grid[i];


}

vector<int>apartments;

for(int i=0;i<N;i++){

    for(int j=0;j<M;j++){

if(grid[i][j] == '.' && !visited[i][j]){

   int rooms = dfs(i,j);
   apartments.push_back(rooms);
}

    }
}

if(apartments.empty()){

    cout<<0<<endl;
}
else{

    sort(apartments.begin(),apartments.end());
    for(size_t i=0;i<apartments.size();i++){
cout<<apartments[i]<<(i+1 ==apartments.size() ? '\n' :' ');

    }
}
return 0;

}