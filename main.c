#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Define the Student Structure
struct Student {
    char name[50];
    int age;
    float gpa;
};

// 2. Global Database (Array of Structs)
// We are making an apartment building with 100 rooms, where every room holds a 'Student'
struct Student database[100]; 
int student_count = 0; // Keeps track of exactly how many students are currently in the database

// --- FUNCTION PROTOTYPES ---
void add_student();
void view_students();

// --- MAIN MENU ---
int main() {
    int choice;

    while(1) { // Infinite loop until they choose option 3 to Exit
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add a New Student\n");
        printf("2. View All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0; // Ends the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// --- TODO 1: Implement the Add Student Function ---
void add_student() {
    printf("\n--- ADD NEW STUDENT ---\n");
    if(student_count == 100){
        printf("Error! Database is full.\n");
        return;
    }else{
        printf("Enter your name: ");
        scanf("%s", database[student_count].name);
        printf("\n");
        printf("Enter your age: ");
        scanf("%d", &database[student_count].age);
        printf("\n");
        printf("Enter GPA scored: ");
        scanf("%f", &database[student_count].gpa);
        printf("\n");
        student_count = student_count+1;

    }
    
    // STEP 1: Check if the database is full (student_count == 100). 
    // If it is, print an error and 'return;' immediately.
    
    // STEP 2: Ask the user to input the student's name, age, and GPA.
    // (Hint for name: scanf("%s", database[student_count].name); )
    // (Hint for age: scanf("%d", &database[student_count].age); )
    
    // STEP 3: Increase student_count by 1 so the next student goes into the next slot!
}

// --- TODO 2: Implement the View Students Function ---
void view_students() {
    printf("\n--- STUDENT LIST ---\n");
    if(student_count == 0){
        printf("No students in the database.\n");
    }
    else{

        printf("-----Student Records-----\n");
        for(int i = 0; i< student_count; i++){

            printf("Student %d:\n", i+1);
            printf("Name of student: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("GPA scored: %.2f\n", database[i].gpa);
            printf("----------------------------------\n");
        }
    }
    // STEP 1: If student_count is 0, print "No students in the database."
    
    // STEP 2: Otherwise, use a 'for' loop to go from i = 0 up to student_count.
    // Print out the details of database[i].
    
}
