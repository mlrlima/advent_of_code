#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;

int main(){

    string s;
    cin>>s;

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

    int j=compact.size()-1;
    int counti, countj;
    while(j>=0){
        while(compact[j]=="."){
            j--;
        }

        if(j<=0){break;}

        countj=1;
        while(compact[j-1]==compact[j]){
            countj++;
            j--;
        }

        counti=0;
        for(int i=0;i<j;i++){
            if(compact[i]=="."){
                counti++;
            }else{
                counti=0;
            }

            int auxj=j;
            if(counti==countj){
                while(counti--){
                    compact[i]=compact[auxj];
                    compact[auxj]=".";
                    i--;
                    auxj++;
                }

                break;
            }

        }
        j--;

    }

    ll checksum=0;
    for(int i=0;i<compact.size();i++){
        if(compact[i]!="."){
            checksum+=i* stoi(compact[i]);
        }
    }

    cout<<checksum<<endl;


    return 0;
}