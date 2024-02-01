#include<iostream>
using namespace std;
class student{
    public:
    int marks;
    student() {
        marks = 0;
    }
    int avg(student s2);
};
int student::avg(student s2){
    int average=(marks+s2.marks)/2;
    return average;
}
int main(){
    student s1;
    student s2;
    cout<<"enter marks for student 1";
    cin>>s1.marks;
    cout<<"enter marks for student 2";
    cin>>s2.marks;
    int a=s1.avg(s2);
    cout<<"average of two students is"<<a;
    return 0;
}