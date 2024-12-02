#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define ll long long

int main(){

    vector<ll> list1,list2;
    map<ll,ll> frequency;

    ll n1,n2,distance=0;
    while(cin>>n1>>n2){
        list1.push_back(n1);
        list2.push_back(n2);
        frequency[n2]++;
    }

    for(int i=0;i<list1.size();i++){
        if(frequency.find(list1[i])!=frequency.end()){ //number is in list 2
            distance+=(list1[i]*frequency[list1[i]]);
        }
    }

    cout<<distance<<endl;

    return 0;
}