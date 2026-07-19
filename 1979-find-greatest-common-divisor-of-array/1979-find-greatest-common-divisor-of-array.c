void sorting(int* arr, int n){
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findGCD(int* nums, int numsSize) {
    sorting(nums, numsSize);
    int a = nums[0], b = nums[numsSize-1];
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}