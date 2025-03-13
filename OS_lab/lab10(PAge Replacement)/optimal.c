#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isInSet(int *set, int size, int value) {
    for (int i = 0; i < size; i++)
        if (set[i] == value)
            return true;
    return false;
}

int predict(int pages[], int n, int set[], int setSize, int index) {
    int farthest = -1, pos = -1;
    for (int i = 0; i < setSize; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (set[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (pos == -1) ? 0 : pos;
}

int pageFaults(int pages[], int n, int capacity) {
    int set[capacity], setSize = 0, page_faults = 0;

    for (int i = 0; i < n; i++) {
        if (setSize < capacity) {
            if (!isInSet(set, setSize, pages[i])) {
                set[setSize++] = pages[i];
                page_faults++;
            }
        } else {
            if (!isInSet(set, setSize, pages[i])) {
                int pos = predict(pages, n, set, setSize, i + 1);
                set[pos] = pages[i];
                page_faults++;
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
    printf("Number of page faults using Optimal Page Replacement: %d\n", pageFaults(pages, n, capacity));
    return 0;
}
