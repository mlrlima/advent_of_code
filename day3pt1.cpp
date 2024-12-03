#include<iostream>
#include<string>
using namespace std;

int main(){

    char c;
    long long result=0;
    while(cin>>c){
        if(c=='m'){ cin>>c;
        if(c=='u'){ cin>>c;
        if(c=='l'){ cin>>c;
        if(c=='('){
            string num1="",num2="";
            while(cin>>c){
                if(c>='0' && c<='9'){
                    num1+=c;
                }else{
                    break;
                }
            }

            if(c==','){
                while(cin>>c){
                    if(c>='0' && c<='9'){
                        num2+=c;
                    }else{
                        break;
                    }
                }

                if(c==')'){
                    result+=(stoi(num1)*stoi(num2));
                }
            }
        }
        }
        }
        }
    }

    cout<<result<<endl;

    return 0;
}