#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constants
const int MIN_GRADE = 0;
const int MAX_GRADE = 100;

// store student data
struct Student {
    string name;
    int grade;
};

// Function to add a student
    void  add_student(vector<Student>& students) {
    Student new_student;
    cout << "Enter student name: ";
    cin >> new_student.name;
    
    cout << "Enter grade (0 - 100): ";
    cin >> new_student.grade;
    
    // Validate grade
    if (new_student.grade < MIN_GRADE || new_student.grade > MAX_GRADE) {
        cout << "Invalid grade. Please enter a grade between 0 and 100.\n";
    } else {
        students.push_back(new_student);
        cout << "Student added successfully!\n";
    }
}

// Function to display all students and their grades
void display_grades(const vector<Student>& students) {
    cout << "\n--- Student Grades ---\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Grade: " << student.grade << endl;
    }
}

// Function to calculate the average grade
void calculate_average(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in the list to calculate average.\n";
        return;
    }
    
    int total = 0;
    for (const auto& student : students) {
        total += student.grade;
    }
    double average = static_cast<double>(total) / students.size();
    cout << "Class average grade: " << average << endl;
}

// Main function to display the menu and handle user choices
int main() {
    vector<Student> students;
    int choice;
    
    do {
        cout << "\nStudent Grade Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Grades\n";
        cout << "3. Calculate Class Average\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                add_student(students);
                break;
            case 2:
                display_grades(students);
                break;
            case 3:
                calculate_average(students);
                break;
            case 4:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
