#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isInSet(int *set, int size, int value) {
    for (int i = 0; i < size; i++)
        if (set[i] == value)
            return true;
    return false;
}

int findLRU(int timestamps[], int size) {
    int min = timestamps[0], pos = 0;
    for (int i = 1; i < size; i++) {
        if (timestamps[i] < min) {
            min = timestamps[i];
            pos = i;
        }
    }
    return pos;
}

int pageFaults(int pages[], int n, int capacity) {
    int set[capacity], timestamps[capacity], setSize = 0, page_faults = 0, time = 0;

    for (int i = 0; i < n; i++) {
        if (setSize < capacity) {
            if (!isInSet(set, setSize, pages[i])) {
                set[setSize] = pages[i];
                timestamps[setSize] = time++;
                setSize++;
                page_faults++;
            } else {
                for (int j = 0; j < setSize; j++) {
                    if (set[j] == pages[i]) {
                        timestamps[j] = time++;
                        break;
                    }
                }
            }
        } else {
            if (!isInSet(set, setSize, pages[i])) {
                int pos = findLRU(timestamps, setSize);
                set[pos] = pages[i];
                timestamps[pos] = time++;
                page_faults++;
            } else {
                for (int j = 0; j < setSize; j++) {
                    if (set[j] == pages[i]) {
                        timestamps[j] = time++;
                        break;
                    }
                }
            }
        }
    }
    return page_faults;
}

int main() {
    int n;
    printf("Enter number of Pages: ");
    scanf("%d", &n);
    int pages[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    int capacity = 4;
    printf("Number of page faults using LRU: %d\n", pageFaults(pages, n, capacity));
    return 0;
}
