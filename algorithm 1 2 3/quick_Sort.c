#include <stdio.h>

//  
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���� �Լ�
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // �ǹ��� �迭�� ������ ���ҷ� ����
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

// �� ���� �Լ�
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    FILE* inputFile, * outputFile;
    int arr[100];
    int numElements = 0;

    // �Է� ���� ����
    if (fopen_s(&inputFile, "data.txt", "r") != 0) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    // ��� ���� ����
    if (fopen_s(&outputFile, "result.txt", "w") != 0) {
        printf("������ �� �� �����ϴ�.\n");
        fclose(inputFile);
        return 1;
    }

    // �Է� ���Ͽ��� �������� �о� �迭�� ����
    while (fscanf_s(inputFile, "%d", &arr[numElements]) != EOF) {
        numElements++;
    }

    // �� ���� ����
    quickSort(arr, 0, numElements - 1);

    // ���ĵ� ����� ��� ���Ͽ� ����
    for (int i = 0; i < numElements; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    // ���� �ݱ�
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
