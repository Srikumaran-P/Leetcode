#include <stdio.h>
#include <ctype.h>  // For tolower() function

int main() {
    char str[100];
    int vowels = 0, consonants = 0, i;

    // Input the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Iterate through the string
    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]); // Convert to lowercase to handle both cases
        if (ch >= 'a' && ch <= 'z') {  // Check if it's an alphabetic character
            // Check if the character is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    // Output the results
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
