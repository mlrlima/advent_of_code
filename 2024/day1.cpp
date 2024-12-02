#include<iostream>
#include<vector>
#include<algorithm> //for sort()
#include<cmath> //for abs()
using namespace std;

#define ll long long

int main(){

    vector<ll> list1,list2;

    ll n1,n2,distance=0;
    while(cin>>n1>>n2){
        list1.push_back(n1);
        list2.push_back(n2);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    for(int i=0;i<list1.size();i++){
        distance+=(abs(list1[i]-list2[i]));
    }

    cout<<distance<<endl;

    return 0;
}
