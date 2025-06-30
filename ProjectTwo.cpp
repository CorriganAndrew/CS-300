#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Define the Course structure
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Function to load courses from a CSV file
map<string, Course> LoadCourses(const string& filename) {
    map<string, Course> courses;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return courses;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 2) {
            Course course;
            string courseNumber = tokens[0];
            course.courseNumber = courseNumber;
            course.courseTitle = tokens[1];

            for (size_t i = 2; i < tokens.size(); ++i) {
                course.prerequisites.push_back(tokens[i]);
            }

            courses[courseNumber] = course;
        }
    }

    file.close();
    return courses;
}

// Main program entry
int main() {
    map<string, Course> courses;
    string filename;
    bool dataLoaded = false;

    int choice = 0;
    while (choice != 9) {
        cout << "\n1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit\n" << endl;
        cout << "What would you like to do? ";

        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice) {
        case 1:
            cout << "Enter the filename of the course data: ";
            getline(cin, filename);
            courses = LoadCourses(filename);
            if (!courses.empty()) {
                cout << "Courses loaded successfully." << endl;
                dataLoaded = true;
            }
            else {
                cout << "Failed to load courses." << endl;
            }
            break;

        case 2:
            if (!dataLoaded) {
                cout << "Please load the data first (option 1)." << endl;
                break;
            }
            cout << "\nHere is a sample schedule:\n" << endl;
            for (const auto& pair : courses) {
                cout << pair.second.courseNumber << ", " << pair.second.courseTitle << endl;
            }
            break;

        case 3:
            if (!dataLoaded) {
                cout << "Please load the data first (option 1)." << endl;
                break;
            }
            {
                string courseNum;
                cout << "What course do you want to know about? ";
                cin >> courseNum;
                transform(courseNum.begin(), courseNum.end(), courseNum.begin(), ::toupper);

                if (courses.find(courseNum) != courses.end()) {
                    Course c = courses[courseNum];
                    cout << c.courseNumber << ", " << c.courseTitle << endl;
                    if (!c.prerequisites.empty()) {
                        cout << "Prerequisites: ";
                        for (size_t i = 0; i < c.prerequisites.size(); ++i) {
                            string prereqCode = c.prerequisites[i];
                            if (courses.find(prereqCode) != courses.end()) {
                                cout << prereqCode << " - " << courses[prereqCode].courseTitle;
                            }
                            else {
                                cout << prereqCode;
                            }
                            if (i < c.prerequisites.size() - 1) cout << ", ";
                        }
                        cout << endl;
                    }
                    else {
                        cout << "Prerequisites: None" << endl;
                    }
                }
                else {
                    cout << "Course not found." << endl;
                }
            }
            break;

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
        }
    }

    return 0;
}
