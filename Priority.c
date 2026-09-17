#include <stdio.h>
#include <string.h>

#define MAX 20

struct Patient {
    char name[20];
    int priority;
};

struct Patient queue[MAX];
int count = 0;

// Function to add a patient
void addPatient(char name[], int priority) {
    strcpy(queue[count].name, name);
    queue[count].priority = priority;
    count++;

    printf("%s added with priority %d\n", name, priority);
}

// Function to treat the next patient
void treatNext() {
    int i, pos;

    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }

    // Find the patient with the highest priority
    // Smaller number = higher priority
    pos = 0;

    for (i = 1; i < count; i++) {
        if (queue[i].priority < queue[pos].priority) {
            pos = i;
        }
    }

    printf("Treating: %s (Priority %d)\n",
           queue[pos].name, queue[pos].priority);

    // Remove the patient
    for (i = pos; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;
}

int main() {

    printf("===== PATIENT PRIORITY QUEUE =====\n\n");

    // First test
    printf("Adding patients:\n");

    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\nTreatment Order:\n");

    while (count > 0) {
        treatNext();
    }

    // Second test
    printf("\n===== SECOND TEST =====\n\n");

    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\nTreating first 3 patients:\n");

    treatNext();
    treatNext();
    treatNext();

    printf("\nAdding new Emergency patient:\n");
    addPatient("P7", 1);

    printf("\nRemaining Treatment Order:\n");

    while (count > 0) {
        treatNext();
    }

    return 0;
}
