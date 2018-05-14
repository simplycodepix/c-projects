#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMOUNT_OF_COURSES 2

struct course
{
    int course_id;
};

struct group
{
    // int group_id;
    char group_name[10];
};

typedef struct
{
    // int student_id;
    struct course course_data;
    struct group group_data;
    char student_name[10];
    float student_weight;
    float student_height;
} students;

void addCourseInfo(students* student, int* student_id, int numberOfCourses);
void addGroupInfo(students* student, int* student_id, int numberOfGroups, int numberOfCourses, int course_id);
void addStudent(students* student, int* student_id, int numberOfStudents, int numberOfGroups, int numberOfCourses, char group_name[], int course_id);
void printStudentInfo(students* student);

int main(void)
{
    int amountOfStudents = 0;
    students* student = (students*)malloc(sizeof(students) * 16);

    addCourseInfo(student, &amountOfStudents, AMOUNT_OF_COURSES);

    printf("\n\nStudents \n\n");
    for(int i = 0; i < amountOfStudents; i++)
    {
        printf("Student [%i] info: \n", i + 1);
        printStudentInfo(&student[i]);
        printf("\n");
    }

    free(student);

    return 0;
}

void addCourseInfo(students* student, int* student_id, int numberOfCourses)
{
    int numberOfGroups, course_id;
    for(int i = 0; i < numberOfCourses; i++)
    {
        printf("Please Enter number of groups on %d course: ", i + 1);
        fflush(stdin);
        scanf("%d", &numberOfGroups);
        printf("\n");

        course_id = i + 1;
        addGroupInfo(student, student_id, numberOfGroups, numberOfCourses, course_id);
    }
}

void addGroupInfo(students* student, int* student_id, int numberOfGroups, int numberOfCourses, int course_id)
{
    int numberOfStudents;
    char group_name[10];
    for(int i = 0; i < numberOfGroups; i++)
    {
        printf("Enter %i Group Name: ", i + 1);
        fflush(stdin);
        scanf("%s", group_name);

        printf("Please Enter number of students in group: ");
        fflush(stdin);
        scanf("%d", &numberOfStudents);

        addStudent(student, student_id, numberOfStudents, numberOfGroups, numberOfCourses, group_name, course_id);
        printf("\n");
    }
}

void addStudent(students* student, int* student_id, int numberOfStudents, int numberOfGroups, int numberOfCourses, char group_name[], int course_id)
{
    for(int i = 0; i < numberOfStudents; i++)
    {
        printf("Enter Student Name: ");
        scanf("%s", &student[*student_id].student_name);
        printf("Enter Student Weight: ");
        scanf("%f", &student[*student_id].student_weight);
        printf("Enter Student Height: ");
        scanf("%f", &student[*student_id].student_height);

        strcpy(student[*student_id].group_data.group_name, group_name);
        student[*student_id].course_data.course_id = course_id;

        *student_id += 1;
        printf("\n");
    }
}

void printStudentInfo(students* student)
{
    printf("Course is: %d\n", student -> course_data.course_id);
    printf("Group is: %s\n", student -> group_data.group_name);
    printf("Name is: %s\n", student -> student_name);
    printf("Weight is: %.2f\n", student -> student_weight);
    printf("Height is: %.2f\n", student -> student_height);
}