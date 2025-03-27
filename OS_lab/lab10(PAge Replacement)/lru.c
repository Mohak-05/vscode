#include <stdio.h>
#include <stdlib.h>

int checkPresence(int cqueue[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (cqueue[i] == target) return 1;
    }
    return 0;
}

int findLRU(int timestamps[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (timestamps[i] < timestamps[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void LRU(int refStrs[], int size, int numFrames) {
    printf("\nLRU Page Replacement Algorithm :");
    printf("\n--------------------------------");

    int cqueue[numFrames], timestamps[numFrames], queuesize = 0, totalFaults = 0, time = 0;

    for (int i = 0; i < size; i++) {
        if (!queuesize) {
            printf("\nPage Request for %d -> Page Fault", refStrs[i]);
            cqueue[queuesize] = refStrs[i];
            timestamps[queuesize] = time++;
            queuesize++;
            totalFaults++;
        } else {
            if (!checkPresence(cqueue, queuesize, refStrs[i])) {
                printf("\nPage Request for %d -> Page Fault", refStrs[i]);
                if (queuesize < numFrames) {
                    cqueue[queuesize] = refStrs[i];
                    timestamps[queuesize] = time++;
                    queuesize++;
                } else {
                    int replaceIndex = findLRU(timestamps, numFrames);
                    cqueue[replaceIndex] = refStrs[i];
                    timestamps[replaceIndex] = time++;
                }
                totalFaults++;
            } else {
                printf("\nPage Request for %d -> Page Hit", refStrs[i]);
                for (int j = 0; j < queuesize; j++) {
                    if (cqueue[j] == refStrs[i]) {
                        timestamps[j] = time++; 
                        break;
                    }
                }
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
    LRU(refStrs, numStrings, numFrames);
    return 0;
}
