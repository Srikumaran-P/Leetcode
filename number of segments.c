int countSegments(char* s) {
	uint8_t segments = 0;
    uint16_t j = 0;
    uint16_t i = 0;
    while(s[i] != '\0')
    {
        if ((s[i] != ' '))
        {
            j = i;
            while(s[j] != ' ' && s[j] != '\0')
            {
                j++;
            }
            segments++;
            i = j - 1;
        }
        ++i;
    }
	return segments;
}
