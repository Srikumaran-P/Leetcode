#include <stdio.h>

void concatenateStrings(char *str1, char *str2) {
    // Find the end of the first string
    while (*str1 != '\0') {
        str1++;
    }

    // Append characters of the second string to the first string
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }

    // Null-terminate the concatenated string
    *str1 = '\0';
}

int main() {
    char str1[100], str2[50];

    // Input two strings from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character if any

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character if any

    // Concatenate the strings
    concatenateStrings(str1, str2);

    // Output the concatenated result
    printf("Concatenated string: %s\n", str1);

    return 0;
}
