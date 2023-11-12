#include <iostream>
#include <cstring>

using namespace std;

class Course {
private:
    string courseName;
    string* students;
    int numStudents;
    int maxStudents;

public:
    // Constructor
    Course(const string& name, int maxStudents)
        : courseName(name), numStudents(0), maxStudents(maxStudents) {
        students = new string[maxStudents];
    }

    // Deep Copy Constructor
    Course(const Course& other)
        : courseName(other.courseName), numStudents(other.numStudents), maxStudents(other.maxStudents) {
        students = new string[maxStudents];
        for (int i = 0; i < numStudents; ++i) {
            students[i] = other.students[i];
        }
    }

    // Destructor
    ~Course() {
        delete[] students;
    }

        string getCourseName() const {
        return courseName;
    }

    
    void addStudent(const string& student) {
        if (numStudents < maxStudents) {
            students[numStudents] = student;
            ++numStudents;
        }
        else {
            cout << "Course is full. Cannot add more students." << endl;
        }
    }

    
    void dropStudent(const string& student) {
        for (int i = 0; i < numStudents; ++i) {
            if (students[i] == student) {
    
                for (int j = i; j < numStudents - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --numStudents;
                return; // Student dropped, exit the function
            }
        }
        cout << "Student not found in the course." << endl;
    }

    
    const string* getStudents() const {
        return students;
    }

    
    int getNumStudents() const {
        return numStudents;
    }
};

int main() {
    
    Course mathCourse("Math", 3);

    
    mathCourse.addStudent("Alice");
    mathCourse.addStudent("Bob");
    mathCourse.addStudent("Charlie");

    
    cout << "Students in " << mathCourse.getCourseName() << ": ";
    const string* mathStudents = mathCourse.getStudents();
    for (int i = 0; i < mathCourse.getNumStudents(); ++i) {
        cout << mathStudents[i] << " ";
    }
    cout << endl;

        Course copyCourse = mathCourse; // Deep copy constructor called

    
    mathCourse.dropStudent("Bob");

    
    cout << "Students in " << mathCourse.getCourseName() << " after dropping Bob: ";
    mathStudents = mathCourse.getStudents();
    for (int i = 0; i < mathCourse.getNumStudents(); ++i) {
        cout << mathStudents[i] << " ";
    }
    cout << endl;

    
    cout << "Students in " << copyCourse.getCourseName() << ": ";
    const string* copyStudents = copyCourse.getStudents();
    for (int i = 0; i < copyCourse.getNumStudents(); ++i) {
        cout << copyStudents[i] << " ";
    }
    cout << endl;

    return 0;
}
