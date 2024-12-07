#include<iostream>
#include<string>
#include<vector>
using namespace std;

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

int main(){

    string s;
    vector<string> lab;
    int x,y=-1;
    bool found=false;
    while(getline(cin,s)){
        lab.push_back(s);

        if(!found){
            y++;
            for(int i=0;i<s.size();i++){
                if(s[i]=='^'){
                    x=i;
                    found=true;
                    lab[y][x]='0';
                    break;
                }
            }
        }
    }

    int cont=1;
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
                    y--;

                    if(lab[y][x]!='0'){cont++;}
                    lab[y][x]='0';
                }

                break;

            case 2: //right
                if(x+1==lab[y].size()){
                    border=true;
                    break;
                }else if(lab[y][x+1]=='#'){
                    dir=changeDir(dir);
                }else{
                    x++;

                    if(lab[y][x]!='0'){cont++;}
                    lab[y][x]='0';
                }

                break;
            
            case 3: //down
                if(y+1==lab.size()){
                    border=true;
                    break;
                }else if(lab[y+1][x]=='#'){
                    dir=changeDir(dir);
                }else{
                    y++;

                    if(lab[y][x]!='0'){cont++;}
                    lab[y][x]='0';
                }

                break;

            case 4: //left
                if(x-1<0){
                    border=true;
                    break;
                }else if(lab[y][x-1]=='#'){
                    dir=changeDir(dir);
                }else{
                    x--;

                    if(lab[y][x]!='0'){cont++;}
                    lab[y][x]='0';
                }

                break;
        }
    }

    cout<<cont<<endl;

    return 0;
}