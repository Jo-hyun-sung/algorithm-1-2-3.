#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int leftSize, int right[], int rightSize);
void mergeSort(int arr[], int size);

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;

    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    merge(arr, left, mid, right, size - mid);

    free(left);
    free(right);
}

int main() {
    FILE* inputFile, * outputFile;
    int arr[100];
    int numElements = 0;

    if (fopen_s(&inputFile, "data.txt", "r") != 0 || fopen_s(&outputFile, "result.txt", "w") != 0) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fscanf_s(inputFile, "%d", &arr[numElements]) != EOF) {
        numElements++;
    }

    mergeSort(arr, numElements);

    for (int i = 0; i < numElements; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
