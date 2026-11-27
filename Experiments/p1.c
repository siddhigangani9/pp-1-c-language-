#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NUM_SUBJECTS 3

// Structure to store student information
typedef struct {
    int rollNumber;
    char name[50];
    float marks[NUM_SUBJECTS];
    float attendance;
    float totalMarks;
    float percentage;
    char grade;
    char status[5]; // "Pass" or "Fail"
} Student;

// Function prototypes
void addStudents(Student students[], int *count);
void displayStudents(const Student students[], int count);
void searchStudent(const Student students[], int count);
void analyzePerformance(const Student students[], int count);
void sortStudentsByPercentage(Student students[], int count);
void calculateMetrics(Student *s);
char assignGrade(float percentage);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    // Menu-driven loop
    do {
        printf("\n=========================================\n");
        printf("    STUDENT PERFORMANCE ANALYSIS SYSTEM  \n");
        printf("=========================================\n");
        printf("1. Add Student Records\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Analyze & View Performance Metrics\n");
        printf("5. Sort Records by Merit (Percentage)\n");
        printf("6. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudents(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                analyzePerformance(students, studentCount);
                break;
            case 5:
                sortStudentsByPercentage(students, studentCount);
                printf("\n[Success] Records successfully sorted by merit!\n");
                break;
            case 6:
                printf("\nExiting program. Thank you!\n");
                break;
            default:
                printf("\n[Error] Invalid choice! Please select between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to calculate independent student statistics
void calculateMetrics(Student *s) {
    s->totalMarks = 0;
    int failedSubject = 0;

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        s->totalMarks += s->marks[i];
        if (s->marks[i] < 40.0) { // Sub-criterion: failing any subject drops status to Fail
            failedSubject = 1;
        }
    }

    s->percentage = s->totalMarks / NUM_SUBJECTS;
    s->grade = assignGrade(s->percentage);

    // Pass criteria: Average >= 40% AND no individual subject marks < 40
    if (s->percentage >= 40.0 && !failedSubject) {
        strcpy(s->status, "Pass");
    } else {
        strcpy(s->status, "Fail");
    }
}

// Function to dynamically assign grades based on percentage thresholds
char assignGrade(float percentage) {
    if (percentage >= 85.0) return 'A';
    if (percentage >= 70.0) return 'B';
    if (percentage >= 55.0) return 'C';
    if (percentage >= 40.0) return 'D';
    return 'F';
}

// Function to add new student profiles to the memory array
void addStudents(Student students[], int *count) {
    int num;
    printf("\nHow many students do you want to add? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        if (*count >= MAX_STUDENTS) {
            printf("\n[System Alert] Maximum database limit reached!\n");
            return;
        }

        printf("\n--- Entering Details for Student %d ---\n", *count + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[*count].rollNumber);

        getchar(); // Clear trailing newline buffer character
        printf("Enter Name: ");
        fgets(students[*count].name, sizeof(students[*count].name), stdin);
        students[*count].name[strcspn(students[*count].name, "\n")] = 0; // Strip newline

        printf("Enter Marks for %d Subjects (out of 100):\n", NUM_SUBJECTS);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%f", &students[*count].marks[j]);
        }

        printf("Enter Attendance Percentage: ");
        scanf("%f", &students[*count].attendance);

        // Auto-compute secondary metrics
        calculateMetrics(&students[*count]);
        (*count)++;
    }
    printf("\n[Success] Records added securely.\n");
}

// Function to print all students in a neat tabular matrix
void displayStudents(const Student students[], int count) {
    if (count == 0) {
        printf("\n[System Info] No records available to display.\n");
        return;
    }

    printf("\n=================================================================================\n");
    printf("%-7s %-20s %-8s %-12s %-7s %-6s %-6s\n", "Roll No", "Name", "Total", "Percentage", "Attend%%", "Grade", "Status");
    printf("=================================================================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-7d %-20s %-8.1f %-11.2f%% %-7.1f%% %-6c %-6s\n",
               students[i].rollNumber, students[i].name, students[i].totalMarks,
               students[i].percentage, students[i].attendance, students[i].grade, students[i].status);
    }
    printf("=================================================================================\n");
}

// Function to search for an individual record using linear search
void searchStudent(const Student students[], int count) {
    if (count == 0) {
        printf("\n[System Info] Database empty. Cannot perform search.\n");
        return;
    }

    int roll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            found = 1;
            printf("\n--- Record Found! ---\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("Attendance:  %.2f%%\n", students[i].attendance);
            printf("Final Grade: %c (%s)\n", students[i].grade, students[i].status);
            printf("Subject Breakdowns:\n");
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                printf("  Subject %d Score: %.1f\n", j + 1, students[i].marks[j]);
            }
            break;
        }
    }
    if (!found) {
        printf("\n[Error] Student with Roll Number %d not found.\n", roll);
    }
}

// Function to evaluate analytical performance indices
void analyzePerformance(const Student students[], int count) {
    if (count == 0) {
        printf("\n[System Info] No data available for global statistical metrics.\n");
        return;
    }

    float totalClassSum = 0, highestPerc = -1.0, lowestPerc = 101.0;
    int highestIdx = 0, lowestIdx = 0;
    int passCount = 0;

    for (int i = 0; i < count; i++) {
        totalClassSum += students[i].percentage;

        if (students[i].percentage > highestPerc) {
            highestPerc = students[i].percentage;
            highestIdx = i;
        }
        if (students[i].percentage < lowestPerc) {
            lowestPerc = students[i].percentage;
            lowestIdx = i;
        }
        if (strcmp(students[i].status, "Pass") == 0) {
            passCount++;
        }
    }

    printf("\n=========================================\n");
    printf("         ACADEMIC METRICS SUMMARY        \n");
    printf("=========================================\n");
    printf("Class Size           : %d\n", count);
    printf("Class Batch Average  : %.2f%%\n", totalClassSum / count);
    printf("Overall Pass Rate    : %.1f%%\n", ((float)passCount / count) * 100);
    printf("-----------------------------------------\n");
    printf("Highest Performer    : %s (Roll: %d) with %.2f%%\n",
           students[highestIdx].name, students[highestIdx].rollNumber, students[highestIdx].percentage);
    printf("Lowest Performer     : %s (Roll: %d) with %.2f%%\n",
           students[lowestIdx].name, students[lowestIdx].rollNumber, students[lowestIdx].percentage);
    printf("=========================================\n");
}

// Function sorting records descendingly via standard Selection Sort logic
void sortStudentsByPercentage(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j].percentage > students[maxIdx].percentage) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            Student temp = students[i];
            students[i] = students[maxIdx];
            students[maxIdx] = temp;
        }
    }
}
