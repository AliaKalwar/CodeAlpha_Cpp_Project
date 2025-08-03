#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << " Enter the number of courses taken: ";
    cin >> numCourses;

    string courseNames[50];
    double grades[50];
    int creditHours[50];

    double totalGradePoints = 0;
    int totalCredits = 0;

    cout << "\n Enter course details:\n";

    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << " name: ";
        cin >> ws; // to ignore any leftover newline
        getline(cin, courseNames[i]);

        cout << "Grade (on 4.0 scale): ";
        cin >> grades[i];

        cout << "Credit hours: ";
        cin >> creditHours[i];

        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    double cgpa = totalGradePoints / totalCredits;

    // Output result
    cout << "\n=============================================\n";
    cout << " CGPA REPORT\n";
    cout << "---------------------------------------------\n";
    cout << left << setw(20) << "Course"
         << setw(10) << "Grade"
         << setw(10) << "Credit Hours" << endl;
    cout << "---------------------------------------------\n";

    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(20) << courseNames[i]
             << setw(10) << grades[i]
             << setw(10) << creditHours[i] << endl;
    }

    cout << "---------------------------------------------\n";
    cout << " Total Credit Hours: " << totalCredits << endl;
    cout << fixed << setprecision(2);
    cout << " CGPA: " << cgpa << endl;
    cout << "=============================================\n";

    return 0;
}

