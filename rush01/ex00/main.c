void fill_mask(const int views[4][4], int mask[4][4]);
int fill_views(int views[4][4], char *str);
int validate(int a[4][4], const int views[4][4]);
void write_matrix(const int answer[4][4]);
void write_error(void);

int check_if_box_fits(int pack[3][4][4], int row, int col, int currbox)
{
    int i;

    i=0;
    if(pack[1][row][col]==currbox)
        return (1);
    else if(pack[1][row][col]!=0)
        return (0);
    while(i < row)
    {
        if(pack[0][i][col] == currbox)
            return (0);
        i++;
    }
    if(pack[0][row][col]!=0)
        return (0);
    return (1);
}

void remove_mistake(int answer[4][4], int currbox, int currrow)
{
    int i;

    i=0;
    while(i<4)
    {
        if(answer[currrow][i] == currbox)
        {
            answer[currrow][i] = 0;
        }
        i++;
    }
}

int fill_answer(int pack[3][4][4], int currbox, int currrow)
{
    int i;
    int col;

    i=0;
    if(currrow>4)
        return (1);
    if(currrow==4)
    {
        if(currbox==4)
        {
            if(!validate(pack[0], pack[2]))
                return (0);
            return (1);
        }
        if(!fill_answer(pack, currbox+1, 0))
            return (0);
    }       
    while(i<4)
    {
        col = i;
        if(check_if_box_fits(pack, currrow, col, currbox))
        {
            pack[0][currrow][i] = currbox;
            if(!fill_answer(pack, currbox, currrow+1))
                return (0);
        }
        remove_mistake(pack[0], currbox, currrow);
        i++;
    }
    return (1);
}

void fill_with_zeros(int arr[4][4])
{
    int i;
    int j;

    i = 0;
    while(i < 4)
    {
        j = 0;
        while (j < 4)
        {
            arr[i][j] = 0;
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    //int views[4][4];
    //int mask[4][4];
    //int answer[4][4];
    int pack[3][4][4];

    fill_with_zeros(pack[1]);
    fill_with_zeros(pack[0]);
    if(ac==2&&!fill_views(pack[2], av[1]))
    {
        fill_mask(pack[2], pack[1]);
        fill_answer(pack, 1, 0);
        if(!validate(pack[0], pack[2]))
            write_matrix(pack[0]);
        else
            write_error();
    }
    else
    {
        write_error();
    }
    return (0);
}