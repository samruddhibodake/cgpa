
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Course {
    string name;
    double grade;
    double credits;
    double gradePoints;
};

int main() {
    int n;
    double totalCredits = 0;
    double totalGradePoints = 0;
    double previousCredits, previousGradePoints;
    
    cout << "===== CGPA CALCULATOR =====\n";

    // Input number of courses
    cout << "Enter the number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses!\n";
        return 0;
    }

    vector<Course> courses(n);

    // Input course details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Course " << i + 1 << ":\n";

        cout << "Enter course name: ";
        cin >> ws;
        getline(cin, courses[i].name);

        cout << "Enter grade point (0-10): ";
        cin >> courses[i].grade;

        cout << "Enter credit hours: ";
        cin >> courses[i].credits;

        // Calculate grade points
        courses[i].gradePoints =
            courses[i].grade * courses[i].credits;

        totalCredits += courses[i].credits;
        totalGradePoints += courses[i].gradePoints;
    }

    // Calculate semester GPA
    double sgpa = totalGradePoints / totalCredits;

    // Input previous semester details
    cout << "\nEnter previous semester total credits (0 if first semester): ";
    cin >> previousCredits;

    cout << "Enter previous semester total grade points (0 if first semester): ";
    cin >> previousGradePoints;

    // Calculate overall CGPA
    double overallCredits = totalCredits + previousCredits;
    double overallGradePoints =
        totalGradePoints + previousGradePoints;

    double cgpa = overallGradePoints / overallCredits;

    // Display course details
    cout << "\n========== COURSE DETAILS ==========\n";
    cout << left << setw(20) << "Course"
         << setw(12) << "Grade"
         << setw(12) << "Credits"
         << "Grade Points\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << courses[i].name
             << setw(12) << courses[i].grade
             << setw(12) << courses[i].credits
             << courses[i].gradePoints << "\n";
    }

    // Display final results
    cout << "\n========== FINAL RESULTS ==========\n";
    cout << "Total Semester Credits: " << totalCredits << "\n";
    cout << "Total Semester Grade Points: "
         << totalGradePoints << "\n";
    cout << "Semester GPA (SGPA): " << sgpa << "\n";
    cout << "Overall CGPA: " << cgpa << "\n"; 

    return 0;
}
