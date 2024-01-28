#include <unistd.h>

//function to write error in console
void write_error(void)
{
    char *str = "Error\n";
    while(*str!='\0')
    {
        write(1, str, 1);
        str++;
    }
}

//function to write answer to console
void write_matrix(const int answer[4][4])
{
    int i;
    int j;
    char tmp;

    i=0;
    while(i<4) // for each row we do:
    {
        j=0;
        while(j<4) // for each collumn in row we do:
        {
            tmp = answer[i][j] + '0'; //we take integer from answer and add '0' to convert it to displayable form
            write(1, &tmp, 1); // we write to console
            if(j!=3)// if it's not an end of row
                write(1, &" ", 1);  //we print space
            j++;
        }
        write(1, &"\n", 1);// on every end of row we print endline
        i++;
    }
}