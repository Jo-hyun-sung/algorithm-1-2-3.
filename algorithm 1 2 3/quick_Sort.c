#include <stdio.h>

//  
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 분할 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 피벗을 배열의 마지막 원소로 설정
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

// 퀵 정렬 함수
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

    // 입력 파일 열기
    if (fopen_s(&inputFile, "data.txt", "r") != 0) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 출력 파일 열기
    if (fopen_s(&outputFile, "result.txt", "w") != 0) {
        printf("파일을 열 수 없습니다.\n");
        fclose(inputFile);
        return 1;
    }

    // 입력 파일에서 정수들을 읽어 배열에 저장
    while (fscanf_s(inputFile, "%d", &arr[numElements]) != EOF) {
        numElements++;
    }

    // 퀵 정렬 수행
    quickSort(arr, 0, numElements - 1);

    // 정렬된 결과를 출력 파일에 저장
    for (int i = 0; i < numElements; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    // 파일 닫기
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
