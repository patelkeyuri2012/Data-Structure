// 18. Write a program that adds and delete records randomly in a student file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	int stdno;
    char stdname[50];
    char course[50];
    char category[50];
};

void addRecord( struct Student student)
{
	 FILE *file = fopen("student_information.txt", "a+");

    if (file == NULL)
    {
        perror("Error in opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%d %s %s %s\n", student.stdno, student.stdname, student.course, student.category);
    
     fclose(file);
}

void deleteRecord( int targetId)
{
     FILE *file = fopen("student_information.txt", "r");

    if (file == NULL)
    {
        perror("Error in opening file");
        exit(EXIT_FAILURE);
    }

    rewind(file);
	FILE *tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL)
    {
        perror("Error in opening temporary file");
        exit(EXIT_FAILURE);
    }

    struct Student currentStudent;
    int recordDeleted = 0;

    while (fscanf(file, "%d %s %s %s", &currentStudent.stdno, currentStudent.stdname, currentStudent.course, currentStudent.category) == 4)
    {
        if (currentStudent.stdno != targetId)
        {
            fprintf(tempFile, "%d %s %s %s\n", currentStudent.stdno, currentStudent.stdname, currentStudent.course, currentStudent.category);
        } else
        {
            recordDeleted = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("student_information.txt");
    rename("temp.txt", "student_information.txt");

    if (recordDeleted)
    {
        printf("\nStudent records are deleted!\n");
    } else
    {
        printf("\nRecords are not found..!\n");
    }
}

void displayRecords()
{
    FILE *file = fopen("student_information.txt", "r");

    if (file == NULL)
    {
        perror("Error in opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
        printf("\nRecords are not found..!\n");
        fclose(file);
        return;
    }

    rewind(file);

    struct Student currentStudent;
    printf("\n%-10s %-20s %-20s %-10s\n", "Roll No", "Name", "Course", "Category");

    while (fscanf(file, "%d %s %s %s", &currentStudent.stdno, currentStudent.stdname, currentStudent.course, currentStudent.category) == 4)
    {
        printf("%-10d %-20s %-20s %-10s\n", currentStudent.stdno, currentStudent.stdname, currentStudent.course, currentStudent.category);
    }

    fclose(file);
}


int main()
{
   
    int choice, targetId;
    struct Student newStudent;

    do
    {
    	printf("\nSelect option for student information\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Insert student information\n2. Delete student information\n3. Display student information\n4. Exit\n");
        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
    				printf("\nEnter student roll no : ");
    				scanf("%d", &newStudent.stdno);
    				printf("Enter student name : ");
    				scanf("%s", newStudent.stdname);
    				printf("Enter student course name : ");
    				scanf("%19s", newStudent.course); 
    				printf("Enter student category : ");
    				scanf("%9s", newStudent.category);
                	addRecord(newStudent);
                	break;

            case 2:
                printf("\nEnter student roll no to delete student record : ");
                scanf("%d", &targetId);
                deleteRecord( targetId);
                break;

            case 3:
                displayRecords();
                break;

            case 4:
            	exit(0);
                break;

            default:
                printf("Invalid choice..!\n");
        }
    } while (choice != 0);

   

    return 0;
}

