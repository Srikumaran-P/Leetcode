#include <stdlib.h> // For qsort

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // Sort the greed factors and cookie sizes
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int i = 0, j = 0, count = 0;

    // Use two pointers to match cookies to children
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) { // Cookie can satisfy the child
            count++;
            i++; // Move to the next child
        }
        j++; 
    }

    return count;
}
