#include<iostream>
using namespace std;
class Person{
    protected:
    int id;

    public:
    void setId(int a ){
        id=a;

    }
    void getId(){
        cout<<"Id of this person is "<<id<<endl;

    }

};
class Student:public Person
{
    protected:
    float marks;
    int years;
    public:
    void setData(float m,int y){
        marks=m;
        years=y;

    }
    void getData(){
        getId();
        cout<<"Total marks of this student is "<<marks<<endl<<" And this student is from "<<years<<" year"<<endl;
    }

};
class Employee:public Person
{
    float salary;
    public:
    void setdata1(float s){
    salary=s;
    }
    void getdata1(){
        getId();
    cout<<"Salary of this employee is "<<salary<<"Rs.";
    }

};
int main(){
    Student s;
    s.setId(7456);
    s.setData(98.78,2);
    s.getData();
    Employee e;
    e.setId(9586);
    e.setdata1(70000.6);
    e.getdata1();

    return 0;


}
