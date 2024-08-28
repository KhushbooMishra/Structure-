#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
// Define the Student structure
struct Student {
    char name[50];
    int rollno;
    char branch[50];
};
// Function to display all students
void displayStudents(struct Student students[], int count) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < count; i++) {
     printf("Name: %s, Roll No: %d, Branch: %s\n", students[i].name, students[i].rollno, students[i].branch);
    }
}
// Function to search for a student by roll number
void searchStudent(struct Student students[], int count, int rollno) {
    int found = 0;
   
 for (int i = 0; i < count; i++) {      
  if (students[i].rollno == rollno) {
          
            printf("\nStudent Found:\n");
            printf("Name: %s, Roll No: %d, Branch: %s\n", students[i].name, students[i].rollno, students[i].branch);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent with Roll No %d not found.\n", rollno);
    }
}
int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice, rollno;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (count < MAX_STUDENTS) {
                    printf("Enter name: ");
                    scanf("%s", students[count].name);
                   
                    printf("Enter roll no: ");
                   
      scanf("%d", &students[count].rollno);
                    printf("Enter branch: ");
                    scanf("%s", students[count].branch);
                    count++;
                } else {
                    printf("Maximum number of students reached \n");
                }
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter roll no to search: ");
                scanf("%d", &rollno);
                searchStudent(students, count, rollno);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}
