#include <bits/stdc++.h>

using namespace std;

vector<int> findCommonElements(int arr1[], int arr2[], int arr3[], int size1, int size2, int size3) {
    int maxElement = max(max(*max_element(arr1, arr1 + size1), *max_element(arr2, arr2 + size2)), *max_element(arr3, arr3 + size3));

    vector<int> commonElements;
    vector<int> count1(maxElement + 1, 0);
    vector<int> count2(maxElement + 1, 0);
    vector<int> count3(maxElement + 1, 0);

    // Count occurrences of elements in arr1
    for (int i = 0; i < size1; i++) {
        count1[arr1[i]]++;
    }

    // Count occurrences of elements in arr2
    for (int i = 0; i < size2; i++) {
        count2[arr2[i]]++;
    }

    // Count occurrences of elements in arr3
    for (int i = 0; i < size3; i++) {
        count3[arr3[i]]++;
    }

    // Find common elements with least count
    for (int i = 0; i <= maxElement; i++) {
        if (count1[i] > 0 && count2[i] > 0 && count3[i] > 0) {
            commonElements.push_back(i);
        }
    }

    return commonElements;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1,2, 3, 4, 5, 6};
    int arr3[] = {1,3, 4, 5, 6, 7};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    vector<int> common = findCommonElements(arr1, arr2, arr3, size1, size2, size3);

    cout << "Common Elements: ";
    for (int i = 0; i < common.size(); i++) {
        cout << common[i] << " ";
    }
    cout << endl;

    return 0;
}
