//this function returns lenght of string
int ft_strlen(char *str)
{
    int len;

    len=0;
    while(str[len]!='\0') //until it's not end of string we do:
    {
        len++; // increse length
    }
    return len; // return length
}

//this function fills the 4x4 views array from 31 long string (char array)
int fill_views(int views[4][4], char *str)
{
    int i;
    int j;

    i=0;
    j=0;
    if(ft_strlen(str)!=31) // if lenght of string is different  than 31 we return 1 to print error in main
        return 1;
    while(str[i]!='\0') //until it's not end of string we do:
    {
        if(str[i]>='1'&&str[i]<='4')    // if character is between '1' and '4', we convert it to int and put it in correct place in 4x4 array views
        {
            views[j/4][j%4]=str[i]-'0';
            j++;
        }
        else if(str[i]!=' ')// if we spotted any character that is not between '1' and '4' and is not space, we return 1 to write error in main
            return 1;
        i++;
    }
    if(j!=16) // if we didn't fill the whole 4x4 array (there were not enough  numbers in string) - we return 1 to print error in main
        return 1;
    return 0; // we return 0 to not print error in main
}