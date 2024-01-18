#include <iostream>
using namespace std;
// Forward declarations
class User;
class Teacher;
// Base class representing a user
class User
{
public:
    string name;
    int id;

    User(const string& name, int ID) : name(name), id(ID) {}

    virtual void displayDetails()
    {
        cout << "User ID: " << id << ", Name: " << name << endl;
    }
};
// Derived class representing a teacher
class Teacher : public User
{
public:
    string subject;

    Teacher(const string& name, int ID, const string& sub) : User(name, ID), subject(sub) {}

    void displayDetails() override
    {
        User::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

// Class representing a school class

class SchoolClass

{
public:
   
    string className;
    
    User* students[50]; // Assuming a maximum of 50 students per class
    
    Teacher* teacher;

    SchoolClass(const string & class_name, Teacher* teach) : className(class_name), teacher(teach)
    {
        for (int i = 0; i < 50; ++i)
        {
            students[i] = nullptr;
        }
    }

    void addStudent(User* student)
    {
        for (int i = 0; i < 50; ++i)
        {
            if (students[i] == nullptr)
            {
                students[i] = student;
                break;
            }
        }
    }

    void displayClassDetails()
    {
        cout << "Class: " << className << endl;
        teacher->displayDetails();
        cout << "Students in Class:" << endl;
        for (int i = 0; i < 50 && students[i] != nullptr; ++i)
        {
            students[i]->displayDetails();
        }
    }
};

// Derived class representing a student

class Student : public User
{
public:
    int grade;

    Student(const string& name, int ID, int Grade) : User(name, ID), grade(Grade) {}

    void displayDetails() override
    {
        User::displayDetails();

        cout << "Grade: " << grade << endl;
    }
};

// Class representing a school
class School
{
public:
    string schoolName;
    SchoolClass* classes[10]; // Assuming a maximum of 10 classes in a school

    School(const string& school_name) : schoolName(school_name)
    {
        for (int i = 0; i < 10; ++i)
        {
            classes[i] = nullptr;
        }
    }

    void addClass(SchoolClass* schoolClass)
    {
        for (int i = 0; i < 10; ++i)
        {
            if (classes[i] == nullptr)
            {
                classes[i] = schoolClass;
                break;
            }
        }
    }

    void displaySchoolDetails()
    {
        cout << "School: " << schoolName << endl;
        cout << "Classes in School:" << endl;
        for (int i = 0; i < 10 && classes[i] != nullptr; ++i)
        {
            classes[i]->displayClassDetails();
        }
    }
};

int main()
{
    // Creating users
    Student student1("Student1", 1, 10);
    Student student2("Student2", 2, 9);

    Teacher teacher1("Teacher1", 101, "Math");

    // Creating classes
    SchoolClass classA("ClassA", &teacher1);
    classA.addStudent(&student1);
    classA.addStudent(&student2);

    // Creating school
    School mySchool("MySchool");
    mySchool.addClass(&classA);

    // Displaying school details
    mySchool.displaySchoolDetails();

    return 0;
}

