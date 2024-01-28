int ft_strlen(char *str)
{
    int len;

    len=0;
    while(str[len]!='\0')
    {
        len++;
    }
    return len;
}

int fill_views(int views[4][4], char *str)
{
    int i;
    int j;

    i=0;
    j=0;
    if(ft_strlen(str)!=31)
        return 1;
    while(str[i]!='\0')
    {
        if(str[i]>='1'&&str[i]<='4')
        {
            views[j/4][j%4]=str[i]-'0';
            j++;
        }
        else if(str[i]!=' ')
            return 1;
        i++;
    }
    if(j!=16)
        return 1;
    return 0;
}