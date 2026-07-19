void merge(int nums[], int idx[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    int *Lidx = (int *)malloc(n1 * sizeof(int));
    int *Ridx = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = nums[left + i];
        Lidx[i] = idx[left + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = nums[mid + 1 + i];
        Ridx[i] = idx[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            idx[k] = Lidx[i];
            i++;
        } else {
            nums[k] = R[j];
            idx[k] = Ridx[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = L[i];
        idx[k] = Lidx[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = R[j];
        idx[k] = Ridx[j];
        j++;
        k++;
    }

    free(L);
    free(R);
    free(Lidx);
    free(Ridx);
}

void sort(int nums[], int idx[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    sort(nums, idx, left, mid);
    sort(nums, idx, mid + 1, right);
    merge(nums, idx, left, mid, right);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    int *sortedNums = (int *)malloc(numsSize * sizeof(int));
    int *indices = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        sortedNums[i] = nums[i];
        indices[i] = i;
    }

    sort(sortedNums, indices, 0, numsSize - 1);

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
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;

    free(result);
    free(sortedNums);
    free(indices);

    return NULL;
}