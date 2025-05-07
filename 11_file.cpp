/*-----------------------------------------------------------
Pr. No : 11
Title : Department maintains a student information. 
        The file contains roll number, name, division and address. 
        Allow user to add, delete information of student. 
        Display information of particular employee. 
        If record of student does not exist an appropriate message is displayed. 
        If it is, then the system displays the student details. 
        Use sequential file to main the data.
------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct StudentRecord {
    int roll;
    char name[20];
    char div;
    char address[50];
} record;

class Student {
public:
    void create();
    void display();
    int search();
    void deleteRecord();
};

void Student::create() {
    ofstream fout("student.dat", ios::binary);
    char choice;
    do {
        cout << "\nEnter Roll No: ";
        cin >> record.roll;
        cout << "Enter Name: ";
        cin >> record.name;
        cout << "Enter Division: ";
        cin >> record.div;
        cout << "Enter Address: ";
        cin >> record.address;

        fout.write((char*)&record, sizeof(record));
        cout << "Add another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    fout.close();
}

void Student::display() {
    ifstream fin("student.dat", ios::binary);
    cout << "\nRoll\tName\tDiv\tAddress\n";
    while (fin.read((char*)&record, sizeof(record))) {
        if (record.roll != -1)
            cout << record.roll << "\t" << record.name << "\t" << record.div << "\t" << record.address << endl;
    }
    fin.close();
}

int Student::search() {
    ifstream fin("student.dat", ios::binary);
    int rollNo, pos = 0;
    cout << "\nEnter Roll No to search: ";
    cin >> rollNo;

    while (fin.read((char*)&record, sizeof(record))) {
        if (record.roll == rollNo) {
            cout << "\nRecord Found:\n";
            cout << "Roll: " << record.roll << "\nName: " << record.name << "\nDivision: " << record.div << "\nAddress: " << record.address << endl;
            fin.close();
            return pos;
        }
        pos++;
    }
    cout << "Record not found.\n";
    fin.close();
    return -1;
}

void Student::deleteRecord() {
    int pos = search();
    if (pos == -1) return;

    fstream file("student.dat", ios::in | ios::out | ios::binary);
    file.seekp(pos * sizeof(record));
    record.roll = -1;
    strcpy(record.name, "NULL");
    record.div = 'N';
    strcpy(record.address, "NULL");
    file.write((char*)&record, sizeof(record));
    file.close();
    cout << "Record deleted successfully.\n";
}

int main() {
    Student s;
    int choice;
    char again;

    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Create\n2. Display\n3. Delete\n4. Search\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            s.create(); 
            break;
        case 2: 
            s.display(); 
            break;
        case 3: s.deleteRecord(); break;
        case 4: s.search(); break;
        case 5: return 0;
        default: cout << "Invalid choice.\n";
        }

        cout << "Continue? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
 
