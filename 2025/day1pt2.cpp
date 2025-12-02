#include<iostream>
#include<string>
using namespace std;

int main(){

    char lr;
    int n;
    int pointer=50;
    int zero=0;
    while(cin>>lr>>n){
        //cout<<lr<<" "<<n<<endl;
        zero+=(n/100);
        n%=100;
        if(lr=='L'){
            if(pointer-n==0){
                zero++;
                pointer=0;
            }else if(pointer-n<0){
                if(pointer!=0) zero++;
                n-=(pointer+1);
                pointer=99;
                pointer-=n;
            }else pointer-=n;
        }else{
            if(pointer+n==100){
                zero++;
                pointer=0;
            }else if(pointer+n>99){
                if(pointer!=0) zero++;
                n-=(100-pointer);
                pointer=n;
            }else pointer+=n;
        }

        //cout<<pointer<<endl;
    }

    printf("%d\n",zero);

    return 0;
}