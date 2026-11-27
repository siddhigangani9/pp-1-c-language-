#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LEN 50

struct Student {
    int id;
    char name[NAME_LEN];
    int classes_attended;
    int total_classes;
    float percentage;
};

// Function to calculate attendance percentage
void calculatePercentage(struct Student *s) {
    if (s->total_classes > 0) {
        s->percentage = ((float)s->classes_attended / s->total_classes) * 100.0;
    } else {
        s->percentage = 0.0;
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n, i;
    float threshold, class_total_attended = 0, class_total_classes = 0, class_percentage = 0;

    printf("=== Student Attendance Management System ===\n");
    printf("Enter total number of students (max %d): ", MAX_STUDENTS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    printf("Enter minimum attendance threshold percentage (e.g., 75.0): ");
    scanf("%f", &threshold);

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Classes Attended: ");
        scanf("%d", &students[i].classes_attended);
        printf("Total Classes Conducted: ");
        scanf("%d", &students[i].total_classes);

        calculatePercentage(&students[i]);

        class_total_attended += students[i].classes_attended;
        class_total_classes += students[i].total_classes;
    }

    // Calculate overall class percentage
    if (class_total_classes > 0) {
        class_percentage = (class_total_attended / class_total_classes) * 100.0;
    }

    // Find max, min attendance, and students requiring improvement
    int max_idx = 0, min_idx = 0;
    for (i = 1; i < n; i++) {
        if (students[i].percentage > students[max_idx].percentage) {
            max_idx = i;
        }
        if (students[i].percentage < students[min_idx].percentage) {
            min_idx = i;
        }
    }

    // Display Summary Report
    printf("\n\n=== ATTENDANCE SUMMARY REPORT ===\n");
    printf("Overall Class Attendance Percentage: %.2f%%\n", class_percentage);

    printf("\nStudent with Maximum Attendance:\n");
    printf("ID: %d, Name: %s (%.2f%%)\n", students[max_idx].id, students[max_idx].name, students[max_idx].percentage);

    printf("\nStudent with Minimum Attendance:\n");
    printf("ID: %d, Name: %s (%.2f%%)\n", students[min_idx].id, students[min_idx].name, students[min_idx].percentage);

    printf("\nStudents Below Threshold (Eligible for improvement/Defaulters):\n");
    int below_count = 0;
    for (i = 0; i < n; i++) {
        if (students[i].percentage < threshold) {
            printf("- ID: %d, Name: %s | Attendance: %.2f%% (Status: Deficit)\n",
                   students[i].id, students[i].name, students[i].percentage);
            below_count++;
        }
    }
    if (below_count == 0) {
        printf("None! All students satisfy the attendance criteria.\n");
    }

    return 0;
}
