#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<cmath> //for abs()
using namespace std;

int main(){

    int x,y=0;
    string s;
    map<char, vector<pair<int, int> > > antennas;
    vector<string> m;

    while(getline(cin,s)){
        m.push_back(s);
        y++;
        x=s.size();
        for(int i=0;i<x;i++){
            if(s[i]!='.'){
                pair<int, int> coor=make_pair(i,y-1);
                antennas[s[i]].push_back(coor);
                m[y-1][i]='#';
            }
        }
    }

    for(auto it:antennas){
        for(int i=0;i<it.second.size();i++){
            for(int j=i+1;j<it.second.size();j++){
                int xx=it.second[j].first - it.second[i].first;
                int yy=it.second[j].second - it.second[i].second;

                int jfirst=it.second[j].first, jsecond=it.second[j].second;
                while(jfirst+xx<x && jfirst+xx>=0 && jsecond+yy<y && jsecond+yy>=0){
                    m[jsecond+yy][jfirst+xx]='#';
                    jsecond+=yy;
                    jfirst+=xx;
                }
            
                int ifirst=it.second[i].first, isecond=it.second[i].second;
                while(ifirst-xx<x && ifirst-xx>=0 && isecond-yy<y && isecond-yy>=0){
                    m[isecond-yy][ifirst-xx]='#';
                    isecond-=yy;
                    ifirst-=xx;
                }
            }
        }
    }

    int count=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(m[i][j]=='#'){
                count++;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}