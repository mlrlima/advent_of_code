#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> grid;

bool check(int i, int j){
    int count=0;
    if(i-1>=0 && j-1>=0 && grid[i-1][j-1]=='@') count++;
    if(i-1>=0 && grid[i-1][j]=='@') count++;
    if(j-1>=0 && grid[i][j-1]=='@') count++;

    if(i+1<grid.size() && j+1<grid[i].size() && grid[i+1][j+1]=='@') count++;
    if(i+1<grid.size() && grid[i+1][j]=='@') count++;
    if(j+1<grid[i].size() && grid[i][j+1]=='@') count++;

    if(i+1<grid.size() && j-1>=0 && grid[i+1][j-1]=='@') count++;
    if(i-1>=0 && j+1<grid[i].size() && grid[i-1][j+1]=='@') count++;

    if(count>3) return false;

    //cout<<i<<" "<<j<<endl;
    return true;
}

int main(){
    string l;
    while(cin>>l) grid.push_back(l);

    int ans=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='@' && check(i,j)) ans++;
        }
    }

    printf("%d\n",ans);

}