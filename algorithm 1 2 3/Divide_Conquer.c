#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �迭�� �� ���Ҹ� ��ȯ�ϴ� �Լ�
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���� �Լ�
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

// ���� ���� �˰��� (�������� �˰���)
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
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    int arr[100];
    int numElements = 0;

    while (fscanf(inputFile, "%d", &arr[numElements]) != EOF) {
        numElements++;
    }

    int k; // ������ ���� ��跮
    printf("������ ������ ���� ��跮�� �Է��ϼ���: ");
    scanf_s("%d", &k);

    if (k < 1 || k > numElements) {
        printf("��ȿ���� ���� ���� ��跮�Դϴ�.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    int selectedValue = select(arr, 0, numElements - 1, k - 1);

    printf("������ ���� ��跮 %d�� ��: %d\n", k, selectedValue);

    fprintf(outputFile, "������ ���� ��跮 %d�� ��: %d\n", k, selectedValue);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
