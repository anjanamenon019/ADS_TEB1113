#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string course;
};

int main()
{
    const int SIZE = 5;
    Student students[SIZE];

    // Input records
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "ID: ";
        cin >> students[i].id;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Age: ";
        cin >> students[i].age;

        cout << "Course: ";
        cin >> students[i].course;
    }

    // Display records
    cout << "\n--- STUDENT RECORDS ---\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nAge: " << students[i].age;
        cout << "\nCourse: " << students[i].course << endl;
    }

    // Search by ID
    int searchID;
    bool found = false;

    cout << "\nEnter ID to search: ";
    cin >> searchID;

    for (int i = 0; i < SIZE; i++)
    {
        if (students[i].id == searchID)
        {
            cout << "\nStudent Found!";
            cout << "\nName: " << students[i].name;
            cout << "\nAge: " << students[i].age;
            cout << "\nCourse: " << students[i].course << endl;

            found = true;
        }
    }

    if (!found)
        cout << "Student not found.\n";

    // Update record
    int updateID;

    cout << "\nEnter ID to update: ";
    cin >> updateID;

    for (int i = 0; i < SIZE; i++)
    {
        if (students[i].id == updateID)
        {
            cout << "New Name: ";
            cin >> students[i].name;

            cout << "New Age: ";
            cin >> students[i].age;

            cout << "New Course: ";
            cin >> students[i].course;

            cout << "Record Updated!\n";
        }
    }

    return 0;
}