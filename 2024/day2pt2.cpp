#include<iostream>
#include<string> //to get input per line
#include<vector>
#include<cmath> //for abs()
using namespace std;

bool remove1(vector<int>&v){

    for(int remove=0;remove<v.size();remove++){
        int i, num, previousNum,increasing;
        if(remove==0){
            previousNum=v[1];
            num=v[2];
            i=2;
        }else if(remove==1){
            previousNum=v[0];
            num=v[2];
            i=2;
        }else{
            previousNum=v[0];
            num=v[1];
            i=1;
        }

        if(num>previousNum){
            increasing=1;
        }else{
            increasing=0;
        }

        for(;i<v.size();i++){

            if(i==remove){continue;}
     
            if(abs(num-previousNum)>3 || (increasing==1 && num<=previousNum) || (increasing==0 && num>=previousNum)){
                break;
            }

            if(i==v.size()-1){
                return true;
            }

            previousNum=num;
            num=v[i+1];
        }

    }

    return false;
}

int main(){
    int safe=0;

    string report;
    
    vector<int> v;
    while(getline(cin,report)){
        bool firstNumber=true;
        bool isSafe=true;
        
        int i=0, num, previousNum, increasing=-1; //1= increasing, 0=decreasing

        string aux="";
        while(i<=report.size()){
            if(report[i]==' ' || i==report.size()){
                num=stoi(aux);
                v.push_back(num);
                if(firstNumber){
                    firstNumber=false;
                }else if(isSafe){
                    if(increasing==-1){
                        if(num>previousNum){
                            increasing=1;
                        }else{
                            increasing=0;
                        }
                    }
                    
                    if(abs(num-previousNum)>3 || (increasing==1 && num<=previousNum) || (increasing==0 && num>=previousNum)){
                        isSafe=false;
                    }
                }
                
                aux="";
                previousNum=num;
            }

            aux+=report[i];
            i++;
        }

        if(isSafe || remove1(v)){
            safe++;
        }
        v.clear();
    }

    cout<<safe<<endl;
}