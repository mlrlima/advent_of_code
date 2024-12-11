#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> m;
int ans;

void calculate(int i, int j){
    if(m[i][j]=='9'){
        ans++;
        return;
    }

    //up
    if(i-1>=0 && m[i-1][j]==m[i][j]+1){
        calculate(i-1,j);
    }

    //down
    if(i+1<m.size() && m[i+1][j]==m[i][j]+1){
        calculate(i+1,j);
    }

    //left
    if(j-1>=0 && m[i][j-1]==m[i][j]+1){
        calculate(i,j-1);
    }

    //right
    if(j+1<m[i].size() && m[i][j+1]==m[i][j]+1){
        calculate(i,j+1);
    }

}

int main(){

    ans=0;

    string s;
    while(cin>>s){
        m.push_back(s);
    }

    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            if(m[i][j]=='0'){
                calculate(i,j);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}