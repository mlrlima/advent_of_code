#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm> //for sort()
using namespace std;

map<string, vector<string> > rules;

bool search(string p, vector<string>&rule){
    for(int i=0;i<rule.size();i++){
        if(rule[i]==p){
            return false;
        }
    }
    return true;
}

bool comp(string a, string b){
    for(int i=0;i<rules[b].size();i++){
        if(a==rules[b][i]){
            return false;
        }
    }

    return true;
}

int main(){

    string s;

    while(getline(cin,s)){
        if(s==""){
            break;
        }

        string page1="";page1+=s[0];page1+=s[1];
        string page2="";page2+=s[3];page2+=s[4];

        rules[page1].push_back(page2);
    }

    int ans=0;
    while(getline(cin,s)){
        int i=0;
        string aux="";
        vector<string> order;
        while(i<s.size()){
            aux+=s[i];
            i++;
            if(s[i]==',' || i==s.size()){
                order.push_back(aux);
                aux="";
                i++;
                continue;
            }
        }


        bool validOrder=true;
        for(i=order.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(!search(order[j], rules[order[i]])){
                    sort(order.begin(), order.end(), comp);
                    validOrder=false;
                    break;
                }
            }
            if(!validOrder){
                break;
            }
        }

        if(!validOrder){
            int mid=order.size()/2;
            ans+=stoi(order[mid]);
        }
    }

    cout<<ans<<endl;

    return 0;
}