#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//this code took 4mins 33 seconds to run the bigger input lmao but it works

vector<string> lab;
int x,y;

int changeDir(int dir){
    switch(dir){
        case 1:
            return 2;

        case 2:
            return 3;

        case 3:
            return 4;

        case 4:
            return 1;
    }

    return 0;
}

void printar(vector<string>&lab){
    for(int i=0;i<lab.size();i++){
        cout<<lab[i]<<endl;
    }
}

bool move(){
        //    y    x     dir
    map<pair<int, int> , vector<int> > memo; 

    int dir=1; //1=up, 2=right, 3=down, 4=left
    bool border=false;
    while(!border){

        switch(dir){
            case 1: //up
                if(y-1<0){
                    border=true;
                    break;
                }else if(lab[y-1][x]=='#'){
                    dir=changeDir(dir);
                }else{
                    pair<int, int> coor=make_pair(y,x);
                    if(memo.find(coor)!=memo.end()){
                        for(int i=0;i<memo[coor].size();i++){
                            if(memo[coor][i]==dir){
                                return true;
                            }
                        }
                    }

                    memo[coor].push_back(dir);
                    y--;
                }

                break;

            case 2: //right
                if(x+1==lab[y].size()){
                    border=true;
                    break;
                }else if(lab[y][x+1]=='#'){
                    dir=changeDir(dir);
                }else{
                    pair<int, int> coor=make_pair(y,x);
                    if(memo.find(coor)!=memo.end()){
                        for(int i=0;i<memo[coor].size();i++){
                            if(memo[coor][i]==dir){
                                return true;
                            }
                        }
                    }

                    memo[coor].push_back(dir);

                    x++;
                }

                break;
            
            case 3: //down
                if(y+1==lab.size()){
                    border=true;
                    break;
                }else if(lab[y+1][x]=='#'){
                    dir=changeDir(dir);
                }else{
                    pair<int, int> coor=make_pair(y,x);
                    if(memo.find(coor)!=memo.end()){
                        for(int i=0;i<memo[coor].size();i++){
                            if(memo[coor][i]==dir){
                                return true;
                            }
                        }
                    }

                    memo[coor].push_back(dir);

                    y++;
                }

                break;

            case 4: //left
                if(x-1<0){
                    border=true;
                    break;
                }else if(lab[y][x-1]=='#'){
                    dir=changeDir(dir);
                }else{
                    pair<int, int> coor=make_pair(y,x);
                    if(memo.find(coor)!=memo.end()){
                        for(int i=0;i<memo[coor].size();i++){
                            if(memo[coor][i]==dir){
                                return true;
                            }
                        }
                    }

                    memo[coor].push_back(dir);

                    x--;
                }

                break;
        }
    }

    return false;

}

int main(){

    string s;
    y=-1;
    bool found=false;
    while(getline(cin,s)){
        lab.push_back(s);

        if(!found){
            y++;
            for(int i=0;i<s.size();i++){
                if(s[i]=='^'){
                    x=i;
                    found=true;
                    break;
                }
            }
        }
    }

    int xx=x,yy=y;

    int cont=0;
    for(int i=0;i<lab.size();i++){
        for(int j=0;j<lab[i].size();j++){
            if(lab[i][j]=='.'){
                lab[i][j]='#';
                if(move()){
                    cont++;
                }
                lab[i][j]='.';
                x=xx;y=yy;
            }
        }
    }

    cout<<cont<<endl;

    return 0;
}