#include<iostream>
#include<string>
using namespace std;

string s;
int lastIndex;

int search(int j){

    int n=s[lastIndex+1]-'0';
    lastIndex+=1;
    for(int i=lastIndex+1; i<=s.size()-j; i++){

        //cout<<i<<endl;
        if(s[i]-'0'>n){
            n=s[i]-'0';
            lastIndex=i;
        }
    }

    //cout<<n;
    return n;
}

int main(){

    long long ans=0;
    while(cin>>s){
        lastIndex=-1;
        long long ten=100000000000;
        long long num=0;
        for(int i=12;i>0;i--){
            num+=search(i)*ten;
            ten/=10;
        }

        //cout<<num<<endl;
        ans+=num;
    }

    cout<<ans<<endl;

    return 0;
}