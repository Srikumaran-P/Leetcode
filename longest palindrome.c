int check_valid_symbol(char a){
    if(a >= 'a' && a <='z'){
        return 1;
    }
    if(a >= 'A' && a <='Z'){
        return 1;
    }
    return 0;
}

int longestPalindrome(char* s) {
    int odd_el = 0, even_num = 0;
    
    for(int i=0; s[i] != '\0'; i++)
    {
        int temp_even_cnt = 0;
        if(check_valid_symbol(s[i]))
        {
            temp_even_cnt = 1;
            for(int j=i+1; s[j] != '\0'; j++)
            {
                if(s[i] == s[j])
                {
                    temp_even_cnt++;
                    s[j] = '|';
                }
            }
        }// check valid
        s[i] = '|';

        if(temp_even_cnt >= 2)
        {
            if(temp_even_cnt%2 == 0)
            {
                even_num += temp_even_cnt;
            }
            else
            {
                if(odd_el == 0)
                {
                    odd_el = 1;
                }
                even_num += temp_even_cnt-1;
            }
        }
        else
        {
            if(odd_el == 0 && temp_even_cnt == 1)
            {
                odd_el = temp_even_cnt;
            }
        }
    }

    return odd_el + even_num;
}
