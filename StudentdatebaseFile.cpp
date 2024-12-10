#include <iostream>
#include <fstream>
using namespace std;

class StudentInfo {
    int Rollno;
    char Name[30];
    char Div;
    char Address[30];

public:
    // Accept details of the student
    void Accept() {
        cout << "\nEnter Roll Number: ";
        cin >> Rollno;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter Division: ";
        cin >> Div;
        cout << "Enter Address: ";
        cin >> Address;
    }

    // Display details of the student
    void Display() const {
        cout << Rollno << "\t" << Name << "\t" << Div << "\t" << Address << "\n";
    }

    // Return Roll Number for searching
    int getRollno() const {
        return Rollno;
    }
};

// Add multiple student records
void addStudentData() {
    int n;
    StudentInfo student;
    ofstream outFile("students.txt", ios::binary);
    cout << "\nHow many students do you want to add? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":";
        student.Accept();
        outFile.write((char*)&student, sizeof(student));
    }
    outFile.close();
    cout << "\nStudent data added successfully!\n";
}

// Add a single student record
void addSingleRecord() {
    StudentInfo student;
    ofstream outFile("students.txt", ios::binary | ios::app);
    cout << "\nEnter details for the new student:";
    student.Accept();
    outFile.write((char*)&student, sizeof(student));
    outFile.close();
    cout << "\nRecord added successfully!\n";
}

// Display all student records
void displayRecords() {
    StudentInfo student;
    ifstream inFile("students.txt", ios::binary);

    cout << "\nStudent Records:\n";
    cout << "Roll No\tName\tDiv\tAddress\n";
    cout << "--------------------------------------\n";

    while (inFile.read((char*)&student, sizeof(student))) {
        student.Display();
    }
    inFile.close();
}

// Search for a student record by Roll Number
void searchStudent(int rollNo) {
    StudentInfo student;
    ifstream inFile("students.txt", ios::binary);
    bool found = false;

    while (inFile.read((char*)&student, sizeof(student))) {
        if (student.getRollno() == rollNo) {
            cout << "\nStudent found:\n";
            student.Display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nNo student found with Roll Number: " << rollNo << "\n";
    }
    inFile.close();
}

// Update a student record by Roll Number
void updateStudent(int rollNo) {
    StudentInfo student;
    ifstream inFile("students.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    bool found = false;

    while (inFile.read((char*)&student, sizeof(student))) {
        if (student.getRollno() == rollNo) {
            cout << "\nEnter new details for the student:\n";
            student.Accept();
            found = true;
        }
        outFile.write((char*)&student, sizeof(student));
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "\nStudent record updated successfully!\n";
    } else {
        cout << "\nNo student found with Roll Number: " << rollNo << "\n";
    }
}

// Delete a student record by Roll Number
void deleteStudent(int rollNo) {
    StudentInfo student;
    ifstream inFile("students.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    bool found = false;

    while (inFile.read((char*)&student, sizeof(student))) {
        if (student.getRollno() == rollNo) {
            cout << "\nRecord with Roll Number " << rollNo << " has been deleted.\n";
            found = true;
        } else {
            outFile.write((char*)&student, sizeof(student));
        }
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (!found) {
        cout << "\nNo student found with Roll Number: " << rollNo << "\n";
    }
}

int main() {
    int choice, rollNo;

    do {
        cout << "\n====== Student Database Menu ======";
        cout << "\n1. Add Multiple Students";
        cout << "\n2. Add Single Student";
        cout << "\n3. Display All Records";
        cout << "\n4. Search Student by Roll Number";
        cout << "\n5. Update Student Record";
        cout << "\n6. Delete Student Record";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudentData();
            break;
        case 2:
            addSingleRecord();
            break;
        case 3:
            displayRecords();
            break;
        case 4:
            cout << "\nEnter Roll Number to search: ";
            cin >> rollNo;
            searchStudent(rollNo);
            break;
        case 5:
            cout << "\nEnter Roll Number to update: ";
            cin >> rollNo;
            updateStudent(rollNo);
            break;
        case 6:
            cout << "\nEnter Roll Number to delete: ";
            cin >> rollNo;
            deleteStudent(rollNo);
            break;
        case 7:
            cout << "\nExiting the program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
