#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

void enqueue(Queue *q, int value) {
    q->data[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

bool isInSet(int *set, int size, int value) {
    for (int i = 0; i < size; i++)
        if (set[i] == value)
            return true;
    return false;
}

int pageFaults(int pages[], int n, int capacity) {
    int set[capacity], setSize = 0, page_faults = 0;
    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        if (setSize < capacity) {
            if (!isInSet(set, setSize, pages[i])) {
                set[setSize++] = pages[i];
                enqueue(&q, pages[i]);
                page_faults++;
            }
        } else {
            if (!isInSet(set, setSize, pages[i])) {
                int val = dequeue(&q);
                for (int j = 0; j < setSize; j++) {
                    if (set[j] == val) {
                        set[j] = pages[i];
                        break;
                    }
                }
                enqueue(&q, pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}

int main() {
    int n;
    printf("Enter number of Pages: ");
    scanf("%d",&n);
    int pages[n];
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    int capacity = 4;
    printf("Number of page faults are: %d\n", pageFaults(pages, n, capacity));
    return 0;
}
