//looks from up and check if there are any obvious boxes to place
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

//looks from down and check if there are any obvious boxes to place
void fill_obvious_column_down(const int views[4][4], int mask[4][4], int i)
{
    int row;
    
    row=0;
    if(views[1][i] == 1)
        mask[4-1][i] = 4;
    if(views[1][i] == 4)
    {
        while(row<4)
        {
            mask[3 - row][i] = row+1;
            row++;
        }
    }
}

//looks from left and check if there are any obvious boxes to place
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

//looks from right and check if there are any obvious boxes to place
void fill_obvious_row_right(const int views[4][4], int mask[4][4], int i)
{
    int column;
    
    column=0;
    if(views[1][i] == 1)
    {
        mask[i][3] = 4;
    }
    if(views[1][i] == 4)
    {
        while(column<4)
        {
            mask[i][3 - column] = column+1;
            column++;
        }
    }
}

//function to fill pack[1] (mask) with obvious 100% known correct boxes
void fill_mask(const int views[4][4], int mask[4][4])
{   
    int i;

    i=0;
    while(i<4)
    {   
        //for each view from each side we check if there is any obvious box placements
        fill_obvious_column_up(views, mask, i);
        fill_obvious_column_down(views, mask, i);
        fill_obvious_row_left(views, mask, i);
        fill_obvious_row_right(views, mask, i);
        i++;
    }
}