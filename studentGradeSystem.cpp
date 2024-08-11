#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Student {
    string name;
    double grade;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, newStudent.name);
    cout << "Enter student grade: ";
    cin >> newStudent.grade;
    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

void displayStudents(const vector<Student>& students) {
    cout << "\nStudent List:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Grade: " << student.grade << endl;
    }
}

double calculateAverage(const vector<Student>& students) {
    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.grade;
    }
    return sum / students.size();
}

Student findHighestGrade(const vector<Student>& students) {
    Student highest = students[0];
    for (const auto& student : students) {
        if (student.grade > highest.grade) {
            highest = student;
        }
    }
    return highest;
}

Student findLowestGrade(const vector<Student>& students) {
    Student lowest = students[0];
    for (const auto& student : students) {
        if (student.grade < lowest.grade) {
            lowest = student;
        }
    }
    return lowest;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Grades Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Find Highest Grade\n";
        cout << "5. Find Lowest Grade\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                cout << "Average Grade: " << calculateAverage(students) << endl;
                break;
            case 4:
                {
                    Student highest = findHighestGrade(students);
                    cout << "Highest Grade: " << highest.name << " with " << highest.grade << endl;
                }
                break;
            case 5:
                {
                    Student lowest = findLowestGrade(students);
                    cout << "Lowest Grade: " << lowest.name << " with " << lowest.grade << endl;
                }
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}