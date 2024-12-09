#include<iostream>
#include<map>
#include<vector>
#include<string>
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
            }
        }
    }

    for(auto it:antennas){
        for(int i=0;i<it.second.size();i++){
            for(int j=i+1;j<it.second.size();j++){
                int xx=it.second[j].first - it.second[i].first;
                int yy=it.second[j].second - it.second[i].second;

                if(it.second[j].first+xx<x && it.second[j].first+xx>=0 && it.second[j].second+yy<y && it.second[j].second+yy>=0){
                    m[it.second[j].second+yy][it.second[j].first+xx]='#';
                }
            
                if(it.second[i].first-xx<x && it.second[i].first-xx>=0 && it.second[i].second-yy<y && it.second[i].second-yy>=0){
                    m[it.second[i].second-yy][it.second[i].first-xx]='#';
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
