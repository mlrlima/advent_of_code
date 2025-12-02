#include<iostream>
#include<string>
using namespace std;

int main(){

    string s1,s2;
    char aux;
    long long ans=0;
    while(cin>>aux){
        s1="";
        s2="";

        s1+=aux;
        while(cin>>aux && aux!='-')s1+=aux;
        while(cin>>aux && aux!=',')s2+=aux;

        //cout<<s1<<" "<<s2<<endl;

        for(long long i=stoll(s1); i<=stoll(s2);i++){
            int strsize=to_string(i).size();
            if(strsize%2==1) continue;
            int part=strsize/2;

            if(to_string(i).substr(0,part)==to_string(i).substr(part,strsize-1)){
                //cout<<i<<endl;
                ans+=i;
            }
        }


    }

    cout<<ans<<endl;
    

    return 0;
}