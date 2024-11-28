#define INDEX(c)        ((c) - 97)
#define ALPHABET_SIZE   26


int firstUniqChar(char* s) {
    // store the count of each character in s.
    int char_cnt[ALPHABET_SIZE] = { 0 };

    char *c = s;
    while (*c) {
        char_cnt[INDEX(*c)]++;
        c++;
    }

    c = s;
    while (*c) {
        if (char_cnt[INDEX(*c)] == 1) {
            return c - s;
        }
        c++;
    }

    return -1;
}
