#include<iostream>
#include<string>
using namespace std;
class Person{
    protected:
    string name;
    int Id;
    public:
    void setData(string n,int a){
        name=n;
        Id=a;
    }
    void displayData(){
        cout<<"Name of this person is "<<name<<" and the ID is "<<Id<<"."<<endl;
    }
};
class Student:virtual public  Person{
    string course;
    int year;
    float marks;
    public:
    void setData_student(string c,int y,float m){
       course=c;
       year=y;
       marks=m;
    }
    void displayData_student(){
        displayData();
        cout<<"This student is from  "<<year<<"year "<<endl<<" and the course is "<<course<<endl
        <<" and has achieved "<<marks<<"marks"<<"."<<endl;
    }
};
class  Employee: virtual public Person {
    string department;
    float salary;
    public:
    void setData_Employee(string d,float s){
       department=d;
       salary=s;
    }
    void displayData_Employee(){
        displayData();
        cout<<"department of this employee is "<<department<<" and the Salary is "<<salary<<"Rs."<<endl;
        
    }
};
int main(){
   Student p;
        p.setData("Shivam", 38040);
        p.setData_student("B.Sc CS(H)" ,2,89.98);
        p.displayData_student();
    Employee e;
    e.setData("John Doe", 12345);
    e.setData_Employee("CS",70000.97);
    e.displayData_Employee();


    return 0;
}
