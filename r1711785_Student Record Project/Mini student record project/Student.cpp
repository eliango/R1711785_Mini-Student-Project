/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.cpp
 * Author: R17117855
 * 
 * Created on 24 April 2019, 13:14
 */

#include "Student.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<cstring>
#include "Student.h"

using namespace std;

    Student::Student() {
    }

    Student::Student(int ParentPhoneNum, char* StdntNam, char* StdntHomAdrs, char* StdntEmailAdrs, char* PrntEmailAdrs) {
        ParentPhoneNumber = ParentPhoneNum;
        strcpy(StudentName, StdntNam);
        strcpy(StudentHomeAdress, StdntHomAdrs);
        strcpy(StudentEmailAdress, StdntEmailAdrs);
        strcpy(ParentEmailAdress, PrntEmailAdrs);

    }
    void Student::GetStudent() {
        cout << "\n";
        cout << "Parent PHONE NUMBER...." << ParentPhoneNumber << endl;
        cout << "Student Name...." << StudentName << endl;
        cout << "Student Home Address...." << StudentHomeAdress<< endl;
        cout << "Student Email Address...." << StudentEmailAdress << endl;
         cout << "Parent Email Address...." << ParentEmailAdress << endl;
    }
void Student::GetRecordDetails() {
    char opt;
    char ch;

    int ParentPhoneNum;
    char sName[40];
    char sHomeAdres[50];
    char sEmailAdres[50];
    char pEmailAdres[30];

    do {
        cout << "Enter Parent Phone Number..";
        cin >> ParentPhoneNum;
        cin.ignore();
        cout << "Enter Student Name..";
        cin.getline(sName, 40);
        cout << "Enter Student Home Address..";
        cin.getline(sHomeAdres, 60);
        cout << "Enter Student Email Address..";
         cin.getline(sEmailAdres, 50);
          cout << "Enter Parent Email Address..";
         cin.getline(pEmailAdres, 30);
        Student student(ParentPhoneNum, sName, sHomeAdres, sEmailAdres, pEmailAdres);
        WriteToFile(student);

        cout << "Another record <y-yes n-no>" << endl;
        opt = getchar();
        cin.ignore();

    } while (opt != 'n');


}
void Student::WriteToFile(Student student) {

    ofstream outFile("students", ios::app | ios::binary);
    outFile.write((char*) &student, sizeof (Student));
    outFile.flush();

    if (outFile)
        cout << "\nRecord saved successfully" << endl;
    else
        cout << "Error saving file" << endl;

    outFile.close();

}

void Student::ReadRecordPosition() {
    streamsize position;
    cout << "Enter the record number to retrieve...";
    cin>>position;
    ReadFromFile(position);
}

void Student::ReadFromFile(streamsize position) {
    Student student;

    ifstream inFile("students", ios::in | ios::binary);

    inFile.seekg(sizeof (Student)*(position - 1), ios::beg);
    inFile.read((char *) &student, sizeof (Student));
    student.GetStudent();
}

