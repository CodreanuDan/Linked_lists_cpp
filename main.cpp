/* Student Management System - Small project to sharpen my linked lists skills
 *
 * Main file
 *
 */

#include "StudentManagementSystem.hpp"
#include "StudentManagementSystem.cpp"

int main()
{
    StudentManagement studMng;
    StudentManagement::StudentNode* studentList = nullptr;

    studMng.addNewStudent(studentList, 1, "Dan");
    studMng.addNewStudent(studentList, 2, "Calin");
    studMng.addNewStudent(studentList, 3, "Bober");

    studMng.displayStudents(studentList);

    StudentManagement::StudentNode* student = studMng.searchStudentByID(studentList, 1);
    if (student != nullptr)
    {
        cout << "Found student: " << student->name << ", ID: " << student->id << endl;
    }
    else
    {
        cout << "Student not found" << endl;
    }

    if(student != nullptr)
    {
        studMng.addGrades(student, 89);
        studMng.addGrades(student, 45);
        cout << "Avg. Grade: " << studMng.calculateAverage(student) << endl;
    }
    

    return 0;
}