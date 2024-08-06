#include<iostream>
using namespace std;
int main(){
    int arr[6]={7,1,3,5,6,1};
    int mini=arr[0];
    int max=0;
    for(int i=1;i<6;i++){
        mini = min(arr[i], mini);
        if(arr[i]-mini>max){
            max=arr[i]-mini;
            cout << max << endl;

        }
    }
    cout<<"max: "<<max << endl;
}