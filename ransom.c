// allocate int array of size 26, entry for each letter, set to 0
// read through ransomNote, for each letter, increment the value in array
// read through magazine, decrement each value, if an value becomes -1 return false
#define CHAR_NULL -97
bool canConstruct(char* ransomNote, char* magazine) {
    int map[26];

    int i = 0;
    int j;


    while ((j = magazine[i] - 97) != CHAR_NULL) {
        map[j] += 1;
        i++;
    }

    i = 0;
    while ((j = ransomNote[i] - 97) != CHAR_NULL) {
        map[j] -= 1;
        if (map[j] == -1)
            return false;
        i++;
    }

    // no failure
    return true;
}
