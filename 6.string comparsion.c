#include <stdio.h>

int compareStrings(const char *str1, const char *str2) {
    // Iterate through both strings
    while (*str1 != '\0' && *str2 != '\0') {
        // If characters are different, return the difference
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    
    // If we reach here, one or both strings ended. Compare their lengths
    return *str1 - *str2;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    
    // Remove the trailing newline character from fgets input
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    int result = compareStrings(str1, str2);

    if (result < 0) {
        printf("String 1 is lexicographically less than String 2.\n");
    } else if (result > 0) {
        printf("String 1 is lexicographically greater than String 2.\n");
    } else {
        printf("Both strings are lexicographically equal.\n");
    }

    return 0;
}
