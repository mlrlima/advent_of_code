#include<iostream>
#include<string>
using namespace std;

int main(){

    char c;
    long long result=0;

    bool enabled=true;
    while(cin>>c){
        if(c=='m' && enabled){ cin>>c;
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
        }else if(c=='d'){ cin>>c;
        if(c=='o'){ cin>>c;
        if(c=='('){ cin>>c;
            if(c==')'){
                enabled=true;
            }
        }else if(c=='n'){ cin>>c;
            if(c==39){ cin>>c;
            if(c=='t'){ cin>>c;
            if(c=='('){ cin>>c;
            if(c==')'){
                enabled=false;
            }
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
