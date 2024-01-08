#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct MinHeap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertKey(struct MinHeap *heap, int key) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap overflow, cannot insert key\n");
        return;
    }

    int i = heap->size++;
    heap->arr[i] = key;

    while (i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteKey(struct MinHeap *heap, int i) {
    if (i >= heap->size) {
        printf("Index out of range\n");
        return;
    }

    heap->arr[i] = heap->arr[heap->size - 1];
    heap->size--;

    minHeapify(heap, i);
}

void displayHeap(struct MinHeap *heap) {
    printf("Min Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main() {
    struct MinHeap heap = {{}, 0};
    int choice, key, index;

    do {
        printf("\nMenu:\n");
        printf("1. Insert key\n");
        printf("2. Delete key\n");
        printf("3. Display heap\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertKey(&heap, key);
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteKey(&heap, index);
                break;
            case 3:
                displayHeap(&heap);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
