#define NLETTERS    26
#define ASCIIOFFSET 0x41
#define NWORDS      4
#define MAXWORDLEN  100
#define MAXWORDS    20


const uint8_t rowmap[NLETTERS] = {
    2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3
};


static inline uint8_t torow(char ch) {
    char upper = toupper(ch);
    return rowmap[(uint8_t)((int)upper - ASCIIOFFSET)];
}


void create_output(char** words, size_t* hits, size_t hitsize, char** output) {
    for (size_t i = 0; i < hitsize; i++) {
        char* word = words[hits[i]];
        size_t bufsize = (strnlen(word, MAXWORDLEN) * sizeof(char)) + 1;
        output[i] = malloc(bufsize);
        
        for (size_t letter = 0; letter < bufsize; letter++) {
            output[i][letter] = word[letter];
        }

        output[i][bufsize - 1] = '\0';
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    size_t* hit_words = malloc(wordsSize * sizeof(size_t));
    char** output_words;
    output_words = malloc(sizeof(char*) * MAXWORDS);

    for (size_t i = 0; i < wordsSize; i++) {
        char* word = words[i];
        bool hit = true;
        uint8_t row = torow(word[0]);
        size_t letter = 0;

        while (*word != '\0') {
            if (torow(word[letter]) != row) {
                hit = false;
                break;
            }

            word++;
        }

        if (hit) {
            hit_words[*returnSize] = i;
            *returnSize = *returnSize + 1;
        }
    }

    create_output(words, hit_words, *returnSize, output_words);

    return output_words;
}
