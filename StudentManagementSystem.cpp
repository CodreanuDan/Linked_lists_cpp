/* Student Management System - Small project to sharpen my linked lists skills
 *
 * Class functions file
 *
 */

#include "StudentManagementSystem.hpp"

/* Add a new student to the linked list */
void StudentManagement::addNewStudent(StudentNode *&head, int id, string name)
{
    /* Create new node */
    StudentNode *newStudent = new StudentNode(id, name);

    /* Add a new student if the list is empty and create a head for the list */
    if (head == nullptr)
    {
        head = newStudent;
    }
    /* Add new student if we already have a head for the list and link it to the end of the list*/
    else
    {
        /* Create a pointer to the head of the list to traverse the list*/
        StudentNode *temp = head;

        /* Traverse the list and find the last node add new student*/
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        /* Add new node in the list by linking it to the end of the list*/
        temp->next = newStudent;
    }
}

/* Display All Students */
void StudentManagement::displayStudents(StudentNode *head)
{
    /* Create a pointer to the head of the list to traverse the list*/
    StudentNode *temp = head;

    /* Traverse the list */
    while (temp != nullptr)
    {
        cout << "Student: " << temp->name << ", ID: " << temp->id << endl;
        temp = temp->next;
    }
}

/* Add Grades to a Student */
void StudentManagement::addGrades(StudentNode *student, int grade)
{
    /* If we don`t have student*/
    if (student == nullptr) return ;

    /* Create new grade node for student*/
    GradeNode *newGrade = new GradeNode(grade);

    /* If student node doesn`t contain any grade node add a new grode node */
    if (student->grades == nullptr)
    {
        student->grades = newGrade;
    }
    /* If we have a grade node linked to student node */
    else
    {
        /* Create pointer to the grades node*/
        StudentNode *temp = new StudentNode();
        temp->grades = student->grades;
        

        /* Traverse the grades list*/
        while (temp->grades->next != nullptr)
        {
            temp->grades = temp->grades->next;
        }

        /* Add the new node at the end of the grades list*/
        temp->grades->next = newGrade;
    }
}

/* Calculate Average Grade */
double StudentManagement::calculateAverage(StudentNode *student)
{
    /* If student node doesn`t contain any grades return 0 */
    if (student->grades == nullptr)
        return 0.0;

    int totalSum = 0;
    int gradeCount = 0;

    /* Create a pointer to the grades node by refering to the specific student node */
    GradeNode *temp = student->grades;

    /* Traverse the grades list */
    while (temp != nullptr)
    {
        gradeCount += 1;
        totalSum += temp->grade;
        temp = temp->next;
    }

    /* Check if the gardeCount = 0 to prevent divison by 0 error */
    return gradeCount == 0 ? 0.0 : static_cast<double>(totalSum) / gradeCount;
}

/*  Search for a Student by ID */
StudentManagement::StudentNode *StudentManagement::searchStudentByID(StudentNode *head, int id)
{
    /* Create a pointer to the head of the student list */
    StudentNode *temp = head;

    /* Traverse the student list*/
    while (temp != nullptr)
    {
        /* Check if the id exists in the student list, if yes return the stdent by id */
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    /* Return nullptr if the id doesn`t exist*/
    return nullptr;
}

/* Remove a Student by ID */
void StudentManagement::removeStudent(StudentNode *&head, int id)
{
    /* In case the list is empty*/
    if (head == nullptr)
        return;

    /* In case the student is the head we move the head to next node */
    if (head->id == id)
    {
        /* Create a pointer to the ID node */
        StudentNode *temp = head;
        /* Jump over the ID node and delete it*/
        head = head->next;
        delete temp;
        return;
    }

    /* Create pointer to the head of the list to traverse it */
    StudentNode *temp = head;

    /* Traverse the list until we find the id of interest while knowing the previous node*/
    while (temp->next != nullptr && temp->next->id == id)
    {
        temp = temp->next;
    }

    /* If the id is found */
    if (temp->next != nullptr)
    {
        /* Create a pointer to the ID node */
        StudentNode *toDelete = temp->next;
        /* Jump over the ID node and delete it*/
        temp->next = toDelete->next;
        delete toDelete;
    }
}