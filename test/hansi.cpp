#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int>v;
    int num;
    cout<<"enter the number of elements";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element";
        cin>>element;
        v.push_back(element);
    }
    map<int,int>m;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(m.find(v[i]) == m.end()) {
            for(int j=i;j < v.size();j++){
                if(v[i]==v[j]){
                    count++;
            }
        }
        m.insert(pair<int,int>(v[i],count));
    }
        count=0;
    }
    int flag=1;
    count = 0;
    map<int,int>::iterator it=m.begin();
    map<int,int>::iterator i=it;
    for(it; it != m.end(); it++){
        for(i;i!=m.end();i++){
            if(it->second==i->second){
                count++;
            }
        }
        if(count > 1) {
            flag = 0;
            break;
        }
        count = 0;
    }
    if(flag==0){
            cout<<"false";
        }
    else{
        cout<<"true";
    }

}