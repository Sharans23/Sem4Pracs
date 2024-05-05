#include <stdio.h>
#include <stdbool.h>

void subset_sum(int arr[], int n, int sum, int subset[], int k, int idx, bool *found)
{
    // k:The current size of the subset being considered
    // idx : The index in the input array arr from which we start considering elements
    // found : A pointer to a boolean variable indicating whether a subset with the target sum has been found ornot
    if (sum == 0)
    {
        // print the subset that adds up to the given sum
        printf("{");
        for (int i = 0; i < k; i++)
        {
            printf("%d", subset[i]);
            if (i < k - 1)
                printf(", ");
        }
        printf("}\n");
        *found = true;
        return;
    }
    if (sum < 0 || idx >= n)
    {
        return;
    }
    // include the current element in the subset
    subset[k] = arr[idx];
    subset_sum(arr, n, sum - arr[idx], subset, k + 1, idx + 1, found);
    // exclude the current element from the subset
    subset_sum(arr, n, sum, subset, k, idx + 1, found);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    int subset[n];
    bool found = false;
    printf("All subsets that add up to %d:\n", sum);
    subset_sum(arr, n, sum, subset, 0, 0, &found);
    if (!found)
    {
        printf("No subset found that adds up to %d\n", sum);
    }
    return 0;
}