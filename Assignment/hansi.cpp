#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    int num=0;
    int a[50] = {};
    int flag = 0;
    cout<<"enter the size of array";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){   //Input
        cin>>arr[i];
    }
    for(i=0;i<n;i++){   //Swap
        for(j=0;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=2;i<=arr[0];i++){  //2 to 11
        for(j=2;j<i;j++) {   //Prime
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag == 0) {
            a[num] = i;
            num++;
        }
        flag = 0;
    }
    int found = 0;
    for(int i = 0; i < 50; i++) {   //Search
        for(int j = 0; j < n; j++) {
            if(a[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            cout << a[i] << endl;
            return 0;
        }
        found = 0;
    }
    cout << "No prime numbers missings" << endl;
    return 0;
}