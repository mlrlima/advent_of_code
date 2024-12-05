#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> m;

int check(int x, int y){
    
    if(x-1<0 || y-1<0 || x+1>=m.size() || y+1>=m[0].size()){
        return 0;
    }

    if((m[x-1][y-1]=='M' && m[x+1][y+1]=='S') || (m[x-1][y-1]=='S' && m[x+1][y+1]=='M')){
        if((m[x+1][y-1]=='M' && m[x-1][y+1]=='S') || (m[x+1][y-1]=='S' && m[x-1][y+1]=='M')){
            return 1;
        }
    }

    return 0;
}

int main(){

    string s;
    while(getline(cin,s)){
        m.push_back(s);
    }

    int cont=0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<s.size();j++){
            if(m[i][j]=='A'){
                cont+=check(i,j);
            }
        }
    }

    cout<<cont<<endl;

    return 0;
}