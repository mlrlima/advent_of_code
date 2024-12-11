#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;

int main(){

    string s;
    cin>>s;

    int space=1, files=s.size()-1;
    if(files%2!=0){files--;}

    while(space<files){
        for(int i=space; i<files;i+=2){
            if(s[space]<=s[files]){
                
            }
        }
    }

    vector<string> compact;
    int fileblock=0;

    for(int i=0;i<s.size();i++){
        if(i%2==0){
            int j=(s[i]-'0');
            while(j--){
                compact.push_back(to_string(fileblock));
            }
            fileblock++;
        }else{
            int j=(s[i]-'0');
            while(j--){
                compact.push_back(".");
            }
        }
    }

    int i=0,j=compact.size()-1;
    while(i<j){
        if(compact[i]!="."){
            i++;
        }
        if(compact[j]=="."){
            j--;
        }

        if(compact[i]=="." && compact[j]!="."){
            compact[i]=compact[j];
            compact[j]=".";
        }
    }

    ll checksum=0;
    for(i=0;i<compact.size();i++){
        if(compact[i]=="."){
            break;
        }

        checksum+=i* stoi(compact[i]);
    }

    cout<<checksum<<endl;


    return 0;
}