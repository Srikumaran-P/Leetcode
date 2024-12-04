bool is_vowel(char data)
{
    if(data == 'a' || data == 'A')
        return true;
    else if(data == 'e' || data == 'E')
        return true;
    else if(data == 'i' || data == 'I')
        return true;
    else if(data == 'o' || data == 'O')
        return true;
    else if(data == 'u' || data == 'U')
        return true;
    else
        return false;
}

void swap(char s[],int start, int end)
{
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
}

char* reverseVowels(char* s) 
{
    if(s == NULL)
        return s;
    if(s[0] == '\0' || s[1] == '\0')
        return s;

    int i = 0;
    int j = strlen(s)-1; //start from back for finding a vowel

    //Assumes if input string is immutable meaning if string literal is received, we need new buffer/array
    char* buffer = malloc(sizeof(char)*(j+2));
    strcpy(buffer, s);
    
    //start working on buffer now
    while(i<j)
    {
        if(is_vowel(buffer[i])) //main condition from beginning of array/string to check first vowel
        {
            //if i position vowel is found, then look for j pos vowel
            while( !is_vowel(buffer[j]) && (i < j) ) //i and j bound check
            {
                j--; //decrement until a vowel is found
            }
            if(i >= j) //j index went behind i which means vowel is not found, so break the loop
                break;
            swap(buffer,i,j); // vowel for index j is found, so swap values at index i and j
            j--; // decrement J to find next vowel 
        }
        i++; // keep moving i to iterate the loop
    }
    return buffer; //assumes caller() calls free(buffer)
}
