#include <stdio.h>
#include <string.h>

int isSubstring(char *mainStr, char *subStr) {
    int i, j;

    // Lengths of main string and substring
    int mainStrLen = strlen(mainStr);
    int subStrLen = strlen(subStr);

    // Loop through the main string
    for (i = 0; i <= mainStrLen - subStrLen; i++) {
        // Compare the substring of mainStr with subStr
        for (j = 0; j < subStrLen; j++) {
            if (mainStr[i + j] != subStr[j]) {
                break;
            }
        }

        // If entire substring matches
        if (j == subStrLen) {
            return 1; // Substring found
        }
    }
    return 0; // Substring not found
}

int main() {
    char mainStr[100], subStr[100];

    // Input the main string and substring
    printf("Enter the main string: ");
    fgets(mainStr, sizeof(mainStr), stdin);
    mainStr[strcspn(mainStr, "\n")] = '\0';  // Remove newline character if any

    printf("Enter the substring: ");
    fgets(subStr, sizeof(subStr), stdin);
    subStr[strcspn(subStr, "\n")] = '\0';  // Remove newline character if any

    // Check if substring exists in the main string
    if (isSubstring(mainStr, subStr)) {
        printf("The substring \"%s\" exists in the main string \"%s\".\n", subStr, mainStr);
    } else {
        printf("The substring \"%s\" does not exist in the main string \"%s\".\n", subStr, mainStr);
    }

    return 0;
}
