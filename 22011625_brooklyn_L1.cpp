/*
**********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 1
*/
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    string email;
    string phone;
};

int main() {
    Student student[5];
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter ID for Student " << i + 1 << " : ";
        cin >> student[i].id;
        cout<< "Enter name for Student " << i + 1 << " : ";
        cin >> student[i].name;
        cout << "Enter email for Student " << i + 1 << " : ";
        cin >> student[i].email;
        cout << "Enter phone for Student " << i + 1 << " : ";
        cin >> student[i].phone;
        cout<<"=============================="<<endl;
    }
    
    for (int i = 0; i < 5; i++) {
        cout<<"=========Student Info========="<<endl;
        cout<<"id: "<< student[i].id<<endl;
        cout<<"name: "<< student[i].name<<endl;
        cout<<"contact: "<< student[i].name<<endl;
        cout<<"email: "<< student[i].name<<endl;
        cout<<"=============================="<<endl;

    }

    return 0;
}
