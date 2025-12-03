#include<iostream>
#include<string>
using namespace std;

int main(){

    string s;
    int ans=0;
    while(cin>>s){
        int one=s[0]-'0';
        int index=0;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]-'0'>one){
                one=s[i]-'0';
                index=i;
            }
        }

        int two=s[index+1]-'0';
        for(int j=index+2;j<s.size();j++){
            if(s[j]-'0'>two) two=s[j]-'0';
        }

        ans+=(one*10);
        ans+=two;

    }

    printf("%d\n",ans);

    return 0;
}