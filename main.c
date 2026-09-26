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
struct Student database[100]; 
int student_count = 0; 

// --- FUNCTION PROTOTYPES ---
void add_student();
void view_students();
void delete_student();

// --- MAIN MENU ---
int main() {
    int choice;

    while(1) { 
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add a New Student\n");
        printf("2. View All Students\n");
        printf("3. Delete a Student\n");
        printf("4. Exit\n");
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
                delete_student();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// --- Add Student Function ---
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
        printf("Student added successfully!\n");
    }
}

// --- View Students Function ---
void view_students() {
    printf("\n--- STUDENT LIST ---\n");
    if(student_count == 0){
        printf("No students in the database.\n");
    }
    else{
        printf("-----Student Records-----\n");
        for(int i = 0; i < student_count; i++){
            printf("Student %d:\n", i+1);
            printf("Name of student: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("GPA scored: %.2f\n", database[i].gpa);
            printf("----------------------------------\n");
        }
    }
}

// --- TODO 3: Implement Delete Student ---
void delete_student() {
    printf("\n--- DELETE STUDENT ---\n");
    if(student_count == 0){
        printf("No students in the database.\n");
        return;
    }
    printf("Enter tthe Student number you want to delete.\n");
    int target_num;
    scanf("%d", &target_num);
    if(target_num< 1 || target_num > student_count){
        printf("Invalid student number!");
        return;
    }
    int target_index = target_num-1;
    for(int i = target_index; i< student_count-1; i++){
        database[i] = database[i+1];
    }
    student_count--;
}
    // STEP 1: Check if database is empty (student_count == 0). If so, print an error and return.
    
    // STEP 2: Ask the user to enter the Student Number they want to delete (1, 2, 3, etc.)
    // (Hint: Store it in an int variable called `target_num`).
    
    // STEP 3: Validate the number. If `target_num` < 1 or `target_num` > student_count, 
    // print an error "Invalid student number!" and return.
    
    // STEP 4: Convert the Student Number to an Array Index.
    // (Hint: The user thinks of Student 1, but in arrays, that's index 0. So index = target_num - 1).
    
    // STEP 5: The Shifting Loop!
    // Write a for loop starting from the deleted index, up to (student_count - 1).
    // Inside the loop: database[i] = database[i + 1];
    // This physically moves everyone up one slot, destroying the deleted student!
    
    // STEP 6: Decrease student_count by 1.
    
