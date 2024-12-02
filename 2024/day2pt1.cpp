#include<iostream>
#include<string> //to get input per line
#include<cmath> //for abs()
using namespace std;

int main(){
    int safe=0;

    string report;
    while(getline(cin,report)){
        bool firstNumber=true;
        bool isSafe=true;
        
        int i=0, num, previousNum, increasing=-1; //1= increasing, 0=decreasing

        string aux="";
        while(i<=report.size()){
            if(report[i]==' ' || i==report.size()){
                num=stoi(aux);
                if(firstNumber){
                    firstNumber=false;
                }else{
                    if(increasing==-1){
                        if(num>previousNum){
                            increasing=1;
                        }else{
                            increasing=0;
                        }
                    }
                    
                    if(abs(num-previousNum)>3 || (increasing==1 && num<=previousNum) || (increasing==0 && num>=previousNum)){
                        isSafe=false;
                        break;
                    }
                }
                
                aux="";
                previousNum=num;
            }

            aux+=report[i];
            i++;
        }

        if(isSafe){
            safe++;
        }
    }

    cout<<safe<<endl;
}