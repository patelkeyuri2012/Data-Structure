#include <stdio.h>
#include <stdlib.h>

struct Student {
    int stdno;
    char stdname[50];
    char course[50];
    char category[50];
    struct Student* next;
    struct Student* prev;
};

struct Student* head = NULL;

struct Student* createNode(int stdno) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newStudent->stdno = stdno;
    newStudent->next = newStudent;
    newStudent->prev = newStudent;
    return newStudent;
}

void insertStudent() {
    int stdno;
    struct Student* newStudent;

    printf("\nEnter Student Enrollment Number: ");
    scanf("%d", &stdno);

    newStudent = createNode(stdno);

    printf("Enter Student Name: ");
    scanf("%s", newStudent->stdname);

    printf("Enter Student Course: ");
    scanf("%s", newStudent->course);

    printf("Enter Student Category: ");
    scanf("%s", newStudent->category);

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head->prev;
        temp->next = newStudent;
        newStudent->prev = temp;
        newStudent->next = head;
        head->prev = newStudent;
    }

    printf("\nStudent with Enrollment Number %d added\n", newStudent->stdno);
}

void deleteStudent(int stdno) {
    if (head == NULL) {
        printf("\nStudent Information List is empty\n");
        return;
    }

    struct Student* current = head;
    struct Student* prev = NULL;

    do {
        if (current->stdno == stdno) {
            if (current == head) {
                if (head->next == head) {
                    head = NULL;
                } else {
                    head = head->next;
                    current->prev->next = head;
                    head->prev = current->prev;
                }
            } else {
                prev->next = current->next;
                current->next->prev = prev;
            }
            free(current);
            printf("\nStudent with Enrollment Number %d deleted\n", stdno);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("\nStudent with Enrollment Number %d not found\n", stdno);
}

void displayStudents() {
    if (head == NULL) {
        printf("\nStudent List is empty.\n");
        return;
    }

    struct Student* current = head;
    printf("\nStudent Information List:\n");

    do {
        printf("\nEnrollment Number: %d \nStudent Name: %s \nCourse: %s \nCategory: %s\n\n", current->stdno, current->stdname, current->course, current->category);
        current = current->next;
    } while (current != head);
}

int main() {
    int choice, stdno;
    while (1) {
        printf("\nDouble Circular Linked List of Student Information :\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Insert Student Data\n2. Delete Student Data\n3. Display Student Information List\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                if (head != NULL) {
                    printf("\nEnter Enrollment Number to delete: ");
                    scanf("%d", &stdno);
                    deleteStudent(stdno);
                } else {
                    printf("\nStudent Information List is empty\n");
                }
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
