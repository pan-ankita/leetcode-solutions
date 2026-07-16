void sortWithIndices(int nums[], int idx[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                // Swap values
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;

                // Swap corresponding indices
                temp = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = temp;
            }
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    int *sortedNums = (int *)malloc(numsSize * sizeof(int));
    int *indices = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        sortedNums[i] = nums[i];
        indices[i] = i;   // Store original index
    }
    sortWithIndices(sortedNums, indices, numsSize);
    
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = sortedNums[left] + sortedNums[right];
        if (sum == target) {
            result[0] = indices[left];
            result[1] = indices[right];
            *returnSize = 2;

            free(sortedNums);
            free(indices);
            return result;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    *returnSize = 0;
    free(result);
    free(sortedNums);
    free(indices);
    return NULL;
}