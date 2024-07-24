#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int rollNo;
    vector<double> subjectMarks;
    double totalMarks;
    char grade;
    int rank;
};

class GradingSystem {
private:
    vector<Student> students;
    int numSubjects;

    void inputStudentData() {
        string name;
        int rollNo;

        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        while (true) {
            cout << "Enter student name (or 'exit' to finish): ";
            cin >> name;

            if (name == "exit") {
                break;
            }

            cout << "Enter student roll number: ";
            cin >> rollNo;

            vector<double> marks;
            cout << "Enter marks for each subject:" << endl;
            for (int i = 0; i < numSubjects; i++) {
                double mark;
                cout << "Subject " << i + 1 << ": ";
                cin >> mark;
                marks.push_back(mark);
            }

            Student student;
            student.name = name;
            student.rollNo = rollNo;
            student.subjectMarks = marks;
            students.push_back(student);
        }
    }

    void calculateTotalMarksAndGrade() {
        for (auto& student : students) {
            // Assuming total marks calculation logic
            student.totalMarks = 0;
            for (double mark : student.subjectMarks) {
                student.totalMarks += mark;
            }

            // Assigning grades based on total marks
            if (student.totalMarks >= numSubjects * 90) {
                student.grade = 'A';
            } else if (student.totalMarks >= numSubjects * 80) {
                student.grade = 'B';
            } else if (student.totalMarks >= numSubjects * 70) {
                student.grade = 'C';
            } else if (student.totalMarks >= numSubjects * 60) {
                student.grade = 'D';
            } else {
                student.grade = 'F';
            }
        }
    }

    void calculateRank() {
        // Sorting students based on total marks in descending order
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.totalMarks > b.totalMarks;
        });

        // Assigning ranks
        for (int i = 0; i < students.size(); i++) {
            students[i].rank = i + 1;
        }
    }

    void displayResults() {
        cout << "\nRank   Roll No   Name   Total Marks   Grade" << endl;

        for (const Student& student : students) {
            cout << setw(4) << student.rank << setw(8) << student.rollNo << setw(6) << student.name
                 << setw(14) << student.totalMarks << setw(6) << student.grade << endl;
        }
    }

public:
    void run() {
        inputStudentData();

        if (students.empty()) {
            cout << "No students entered. Exiting." << endl;
            return;
        }

        calculateTotalMarksAndGrade();
        calculateRank();
        displayResults();
    }
};

int main() {
    GradingSystem gradingSystem;
    gradingSystem.run();

    return 0;
}
