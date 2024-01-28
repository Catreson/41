#include <unistd.h>

void write_error(void)
{
    char *str = "Error\n";
    while(*str!='\0')
    {
        write(1, str, 1);
        str++;
    }
}

void write_matrix(const int answer[4][4])
{
    int i;
    int j;
    char tmp;

    i=0;
    while(i<4)
    {
        j=0;
        while(j<4)
        {
            tmp = answer[i][j] + '0';
            write(1, &tmp, 1);
            if(j!=3)
                write(1, &" ", 1);
            j++;
        }
        write(1, &"\n", 1);
        i++;
    }
}