#include<iostream>
#include<string> //for getline()
#include<vector>
using namespace std;

typedef long long ll;

vector<ll> equation;
ll result;
bool found;

void calculate(int i, ll r){

    if((r==result && i==equation.size()) || found){
        found=true;
        return;
    }
    if(r>result || i==equation.size()){
        return;
    }

    calculate(i+1, r+equation[i]);
    calculate(i+1, r*equation[i]);

    string aux=to_string(r);
    aux+=to_string(equation[i]);
    calculate(i+1, stoll(aux));

}

int main(){

    ll answer=0;
    string s;
    while(getline(cin,s)){
        int i=0;
        string aux="";
        while(s[i]!=':'){
            aux+=s[i];
            i++;
        }
        result=stoll(aux);

        i+=2;
        aux="";
        while(i<=s.size()){
            if(s[i]==' ' || i==s.size()){
                equation.push_back(stoll(aux));
                aux="";
                i++;
                continue;
            }

            aux+=s[i];
            i++;
        }

        found=false;
        calculate(1,equation[0]);

        if(found){
            answer+=result;
        }

        equation.clear();
    }

    cout<<answer<<endl;

    return 0;
}