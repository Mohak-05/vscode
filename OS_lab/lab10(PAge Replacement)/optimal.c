#include <stdio.h>
#include <stdlib.h>

int checkPresence(int cqueue[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (cqueue[i] == target) return 1;
    }
    return 0;
}

int findOptimalReplacement(int cqueue[], int size, int refStrs[], int currentIndex, int totalPages) {
    int farthest = -1, index = -1;
    for (int i = 0; i < size; i++) {
        int j;
        for (j = currentIndex + 1; j < totalPages; j++) {
            if (cqueue[i] == refStrs[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == totalPages) return i;
    }
    return (index == -1) ? 0 : index;
}

void Optimal(int refStrs[], int size, int numFrames) {
    printf("\nOptimal Page Replacement Algorithm :");
    printf("\n-----------------------------------");
    
    int cqueue[numFrames], queuesize = 0, totalFaults = 0;

    for (int i = 0; i < size; i++) {
        if (!queuesize) {
            printf("\nPage Request for %d -> Page Fault", refStrs[i]);
            cqueue[queuesize++] = refStrs[i];
            totalFaults++;
        } else {
            if (!checkPresence(cqueue, queuesize, refStrs[i])) {
                printf("\nPage Request for %d -> Page Fault", refStrs[i]);
                if (queuesize < numFrames) {
                    cqueue[queuesize++] = refStrs[i];
                } else {
                    int replaceIndex = findOptimalReplacement(cqueue, numFrames, refStrs, i, size);
                    cqueue[replaceIndex] = refStrs[i];
                }
                totalFaults++;
            } else {
                printf("\nPage Request for %d -> Page Hit", refStrs[i]);
            }
        }
    }
    printf("\n\nTotal Page Faults Detected: %d\n\n", totalFaults);
}

int main() {
    int numFrames, numStrings;
    printf("\nEnter the number of frames and length of reference string : ");
    scanf(" %d %d", &numFrames, &numStrings);
    int refStrs[numStrings];
    printf("\nEnter the value of the reference strings (Space Separated): ");
    for (int i = 0; i < numStrings; i++) {
        scanf(" %d", &refStrs[i]);
    }
    Optimal(refStrs, numStrings, numFrames);
    return 0;
}
