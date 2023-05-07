#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 배열의 두 원소를 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 분할 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// 선택 문제 알고리즘 (분할정복 알고리즘)
int select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {
        return arr[k];
    }
    else if (k < pivotIndex) {
        return select(arr, low, pivotIndex - 1, k);
    }
    else {
        return select(arr, pivotIndex + 1, high, k);
    }
}

int main() {
    FILE* inputFile, * outputFile;
    fopen_s(&inputFile, "data.txt", "r");
    fopen_s(&outputFile, "result.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int arr[100];
    int numElements = 0;

    while (fscanf(inputFile, "%d", &arr[numElements]) != EOF) {
        numElements++;
    }

    int k; // 선택할 순서 통계량
    printf("정수를 선택할 순서 통계량을 입력하세요: ");
    scanf_s("%d", &k);

    if (k < 1 || k > numElements) {
        printf("유효하지 않은 순서 통계량입니다.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    int selectedValue = select(arr, 0, numElements - 1, k - 1);

    printf("선택한 순서 통계량 %d의 값: %d\n", k, selectedValue);

    fprintf(outputFile, "선택한 순서 통계량 %d의 값: %d\n", k, selectedValue);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
