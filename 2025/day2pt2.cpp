#include<iostream>
#include<string>
using namespace std;

bool check(int part, string n){
    string first=n.substr(0,part);
    //cout<<n<<" "<<first<<endl;
    for(int i=part;i<n.size();i+=part){
        if(first!=n.substr(i,part)) return false;
    }

    return true;
}

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
            int part=1;
            int strsize=to_string(i).size();
            while(part<strsize){
                if(strsize%part!=0){
                    part++;
                    continue;
                }
                else if(check(part, to_string(i))){
                    //cout<<i<<endl;
                    ans+=i;
                    break;
                }
                part++;
            }
        }


    }

    cout<<ans<<endl;
    

    return 0;
}