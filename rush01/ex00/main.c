void fill_mask(const int views[4][4], int mask[4][4]);
int fill_views(int views[4][4], char *str);
int validate(int a[4][4], const int views[4][4]);
void write_matrix(const int answer[4][4]);
void write_error(void);
//These are function declarations that are defined in different files.

int check_if_box_fits(int pack[3][4][4], int row, int col, int currbox)
{
    int i;

    i=0;
    if(pack[1][row][col]==currbox) //if box we try to put is correct with mask, we return 1
        return (1);
    else if(pack[1][row][col]!=0) //if we try to put a box that stands in opposite to mask, we return 0
        return (0);
    while(i < row)
    {
        if(pack[0][i][col] == currbox) //if the box we try to put already exist in this column, we return 0
            return (0);
        i++;
    }
    if(pack[0][row][col]!=0) //if there already is a box we return 0
        return (0);
    return (1); //if none conditions were met we return 1 
}

//this function is used to revert changes to answer if box was put by mistake
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

//this is recursive function to fill all non obvious boxes, if this function returns 0 it found valid answer
int fill_answer(int pack[3][4][4], int currbox, int currrow)
{
    int col;

    col = 0;
    if(currrow>4) // if we stepped out of bounds we return 1
        return (1);
    if(currrow==4) // if we finished filling the box row == 4 -> we are at nonexistent 5th row so we finished
    {
        if(currbox==4) // if we put all 4 boxes in row
        {
            return (validate(pack[0], pack[2])); // we return 0 if answer is valid, else 1
        }
        if(!fill_answer(pack, currbox+1, 0)) // we recursively call function to fill next box size starting from row 0
         //and if it returns 0, we return 0
            return (0);
    }       
    while(col<4)// if we didn't finish yet, we go through each column and try to fit box
    {
        if(check_if_box_fits(pack, currrow, col, currbox)) //we try to fit box in
        {
            pack[0][currrow][col] = currbox;  // if it does we put it here
            if(!fill_answer(pack, currbox, currrow+1)) // we recursively call function to go to next row
                return (0);// if we found answer return 0
        }
        remove_mistake(pack[0], currbox, currrow);// we need to clean incorrectly fitted boxes, because function returned 1
        col++;// we try to fit it in another column
    }
    return (1); // if we didn't succeed to fit box we return 1
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
    int pack[3][4][4];
    //this creates 3 dimensional array, which we should understand as 3 2D 4x4 arrays
    //where pack[0] is answer, pack[1] is mask and pack[2] is views

    fill_with_zeros(pack[1]); //we fill pack[1] with zeros
    fill_with_zeros(pack[0]); //we fill pack[2] with zeros
    if(ac==2&&!fill_views(pack[2], av[1])) //we check if we got only 1 argument and(&&) if we
    // succesfully filled pack[2] (views) with data from input string
    {
        fill_mask(pack[2], pack[1]); //we fill mask with obvious boxes: if view 1: we put box 4, if view 4: we put 1, 2, 3, 4 boxes
        fill_answer(pack, 1, 0); //we fill pack[2] (answer) with correct values
        if(!validate(pack[0], pack[2])) //once more we validate if our box placement is valid
            write_matrix(pack[0]);  //if yes we display it
        else
            write_error(); //if no we print "Error"
    }
    else
    {
        write_error(); // if we got more or less than 1 argument or argument was incorrect we print Error
    }
    return (0);
}