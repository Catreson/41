//column view up verification
//verifies if anwer fulfills  the column view up condition. 
int cvu(int answer[4][4],const int views[4][4], int i)
{
    int row;
    int highest;
    int visible;

    highest=0;
    row=0;
    visible=0;
    while(row<4)
    {
        if(answer[row][i] > highest)
        {
            visible++;
            highest = answer[row][i];
        }
        row++;
    }
    return (visible == views[0][i]);
}

//column view down verification
//verifies if answer fulfills  the column view down condition.
int cvd(int answer[4][4],const int views[4][4], int i)
{
    int row;
    int highest;
    int visible;

    highest=0;
    row=3;
    visible=0;
    while(row>=0)
    {
        if(answer[row][i] > highest)
        {
            visible++;
            highest = answer[row][i];
        }
        row--;
    }
    return (visible == views[1][i]);
}

//row view left verification
//verifies if answer fulfills  the row view left condition.
int rvl(int answer[4][4],const int views[4][4], int i)
{
    int column;
    int highest;
    int visible;

    highest=0;
    column=0;
    visible=0;
    while(column<4)
    {
        if(answer[i][column] > highest)
        {
            visible++;
            highest = answer[i][column];
        }
        column++;
    }
    return (visible == views[2][i]);
}

//row view right verification
//verifies if answer  fulfills the row view right condition.
int rvr(int answer[4][4],const int views[4][4], int i)
{
    int column;
    int highest;
    int visible;

    highest=0;
    column=3;
    visible=0;
    while(column>=0)
    {
        if(answer[i][column] > highest)
        {
            visible++;
            highest = answer[i][column];
        }
        column--;
    }
    return (visible == views[3][i]);
}

int validate(int a[4][4], const int views[4][4])
{
    int i;
    i=0;
    while(i<4) //we check for every view from each side
    {
        if(0 == (cvu(a, views, i)*cvd(a, views, i)*rvl(a, views, i)*rvr(a, views, i))) //this is equivalent to check if every condition was fulfilled
            return (1);
        i++;
    }
    return (0);
}