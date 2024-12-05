#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> m;

int check(int x, int y){
    int cont=0;

    string xmas="XMAS";

    int xx=x-1, p=1;
    for(int i=0;i<3;i++){ //upwards
        if(xx<0){
            break;
        }
        if(m[xx][y]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        xx--;p++;
    }

    xx=x+1;p=1;
    for(int i=0;i<3;i++){ //downwards
        if(xx>=m.size()){
            break;
        }
        if(m[xx][y]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        xx++;p++;
    }

    int yy=y-1;p=1;
    for(int i=0;i<3;i++){ //left
        if(yy<0){
            break;
        }
        if(m[x][yy]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        yy--;p++;
    }

    yy=y+1;p=1;
    for(int i=0;i<3;i++){ //right
        if(yy>=m[0].size()){
            break;
        }
        if(m[x][yy]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        yy++;p++;
    }

    xx=x-1;yy=y-1;p=1;
    for(int i=0;i<3;i++){ //diagonal left up
        if(yy<0 || xx<0){
            break;
        }
        if(m[xx][yy]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        xx--;yy--;p++;
    }

    xx=x-1;yy=y+1;p=1;
    for(int i=0;i<3;i++){ //diagonal right up
        if(yy>=m[0].size() || xx<0){
            break;
        }
        if(m[xx][yy]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        xx--;yy++;p++;
    }

    xx=x+1;yy=y-1;p=1;
    for(int i=0;i<3;i++){ //diagonal left down
        if(yy<0 || xx>=m.size()){
            break;
        }
        if(m[xx][yy]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        xx++;yy--;p++;
    }

    xx=x+1;yy=y+1;p=1;
    for(int i=0;i<3;i++){ //diagonal right down
        if(yy>=m[0].size() || xx>=m.size()){
            break;
        }
        if(m[xx][yy]!=xmas[p]){
            break;
        }

        if(i==2){
            cont++;
        }

        xx++;yy++;p++;
    }

    return cont;
}

int main(){

    string s;
    while(getline(cin,s)){
        m.push_back(s);
    }

    int cont=0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<s.size();j++){
            if(m[i][j]=='X'){
                cont+=check(i,j);
            }
        }
    }

    cout<<cont<<endl;

    return 0;
}