// Implement your own strcat()
void myStrcat(char *str1, const char *str2){
    // Find the null terminator \0 of str1
    // Iterate over str2 and copy each character to the memory
    // locations at the end of str1
    // Add a null terminator at the end of the concatenated string

    // finding null terminator index of str1
    int nullTermIndex = 0;
    while(str1[nullTermIndex] != '\0'){
        nullTermIndex++;
    }


    // copying str2 values to str1
    int i = 0;
    while(str2[i] != '\0'){
        str1[nullTermIndex] = str2[i];
        i++;
        nullTermIndex++;

    }

    // adding null terminator to the end of str1
    str1[nullTermIndex] = '\0';
}