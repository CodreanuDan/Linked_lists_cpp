
/* Student Management System - Small project to sharpen my linked lists skills
 *
 * Header File for the class and function definition
 *
 */

#ifndef STUDENTMANAGEMENTSYSTEM_HPP
#define STUDENTMANAGEMENTSYSTEM_HPP

#include <iostream>
#include <string>
using namespace std;

class StudentManagement
{
public:
    /* Struct containing the Node for Student Grades*/
    struct GradeNode
    {
        /* Data field */
        int grade;
        /* Pointer to the next node */
        GradeNode *next;

        /* Constructor to initialize a new node with data */
        GradeNode(int newGrade)
        {
            grade = newGrade;
            next = nullptr;
        }
        GradeNode()
        {
            grade = 0;
            next = nullptr;
        }
    };

    /* Struct containing the Node for Student Infos*/
    struct StudentNode
    {
        /* Data field*/
        int id;
        string name;
        /* Linked list of grades */
        GradeNode *grades;
        /* Pointer to the next node */
        StudentNode *next;

        /* Constructor to initialize a new node with data */
        StudentNode(int new_id, string new_name)
        {
            id = new_id;
            name = new_name;
            grades = nullptr;
            next = nullptr;
        }
        StudentNode()
        {
            id = 0;
            name = "\0";
            next = nullptr;
            grades = nullptr;
        }
    };

    /* Add a new student to the linked list */
    void addNewStudent(StudentNode *&head, int id, string name);
    /* Display All Students */
    void displayStudents(StudentNode *head);
    /* Add Grades to a Student */
    void addGrades(StudentNode *student, int grade);
    /* Calculate Average Grade */
    double calculateAverage(StudentNode *student);
    /*  Search for a Student by ID */
    StudentNode *searchStudentByID(StudentNode *head, int id);
    /* Remove a Student by ID */
    void removeStudent(StudentNode *&head, int id);
};

#endif