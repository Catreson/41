void fill_obvious_column_down(const int views[4][4], int mask[4][4], int i)
{
    int row;
    
    row=3;
    if(views[1][i] == 1)
        mask[4-1][i] = 4;
    if(views[1][i] == 4)
    {
        while(row>=0)
        {
            mask[row][i] = row+1;
            row--;
        }
    }
}

void fill_obvious_column_up(const int views[4][4], int mask[4][4], int i)
{
    int row;
    
    row=0;
    if(views[0][i] == 1)
        mask[0][i] = 4;
    if(views[0][i] == 4)
    {
        while(row<4)
        {
            mask[row][i] = row+1;
            row++;
        }
    }
}

void fill_obvious_row_left(const int views[4][4], int mask[4][4], int i)
{
    int column;

    column=0;
    if(views[2][i] == 1)
        mask[i][0] = 4;
    if(views[2][i] == 4)
    {
        while(column<4)
        {
            mask[i][column] = column+1;
            column++;
        }
    }
}

void fill_obvious_row_right(const int views[4][4], int mask[4][4], int i)
{
    int column;
    
    column=3;
    if(views[1][i] == 1)
    {
        mask[i][4-1] = 4;
    }
    if(views[1][i] == 4)
    {
        while(column>=0)
        {
            mask[i][column] = column+1;
            column--;
        }
    }
}

void fill_mask(const int views[4][4], int mask[4][4])
{   
    int i;

    i=0;
    while(i<4)
    {
        fill_obvious_column_up(views, mask, i);
        fill_obvious_column_down(views, mask, i);
        fill_obvious_row_left(views, mask, i);
        fill_obvious_row_right(views, mask, i);
        i++;
    }
}