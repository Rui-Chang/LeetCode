
char* reverseVowels(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    char tmp;
    
    while(i < j){
        while(i < j && !strchr("aeiouAEIOU", s[i]))
            i++;
        while(i < j && !strchr("aeiouAEIOU", s[j]))
            j--;
        tmp = s[i];
        s[i++] = s[j];
        s[j--] = tmp;
    }
    
    return s;
}
