#include <iostream>

void initialize(int* grid, int size) {
    for (int i{ 0 }; i < size; i++) grid[i] = 0;
}

bool is_safe(int* grid, int row, int col, int total_rows, int total_cols)
{
    // check rows
    for (int i = 0; i < total_cols; i++)
    {
        if (grid[row*total_cols+i] == 1)
            return false;
    }
    // check cols
    for (int j = 0; j < total_rows; j++)
    {
        if (grid[j*total_cols+col] == 1)
            return false;
    }

    // check left-down diag
    int i = row, j = col;
    while (true)
    {
        if (grid[i*total_cols+j] == 1)
        {
            return false;
        }
        i++;
        j--;
        if (i >= total_rows || j < 0)
            break;
    }

    // check right-down diag
    i = row; j = col;
    while (true)
    {
        if (grid[i*total_cols+j] == 1)
        {
            return false;
        }
        i++;
        j++;
        if (i >= total_rows || j >= total_rows)
            break;
    }

    // check left-up diag
    i = row; j = col;
    while (true)
    {
        if (grid[i*total_cols+j] == 1)
        {
            return false;
            break;
        }
        i--;
        j--;
        if (i < 0 || j < 0)
            break;
    }

    // check right-up diag
    i = row; j = col;
    while (true)
    {
        if (grid[i*total_cols+j] == 1)
        {
            return false;
            break;
        }
        i--;
        j++;
        if (i < 0 || j >= total_rows)
            break;
    }
    return true;
}

bool solfound(int* grid, int total_rows, int total_cols)
{
    int a = 0;
    for (int i = 0; i < total_rows; i++)
    {
        for (int j = 0; j < total_cols; j++)
        {
            if (grid[i*total_cols + j] == 1)
                a++;
        }
    }
    if (a == total_rows)
        return true;
    else
        return false;
}
bool sol(int* grid, int total_rows, int total_cols)
{
    if (solfound(grid, total_rows, total_cols))
        return true;
    for (int i = 0; i < total_rows; i++)
    {
        for (int j = 0; j <total_cols; j++)
        {
            if (is_safe(grid, i, j, total_rows, total_cols))
            {
                grid[i*total_cols+j] = 1;
                if (sol(grid, total_rows, total_cols))
                    return true;
                grid[i*total_cols+j] = 0;
            }
        }
    }
    return false;
}

void draw(int* grid, int total_rows, int total_cols)
{
    for (int i = 0; i < total_rows; i++)
    {
        for (int j = 0; j < total_cols; j++)
        {
            std::cout << grid[i*total_cols+j] << " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    std::cout << "enter number of row and col:\n";
    int i, j;
    std::cin >> i >> j;
    int* grid = new int[i * j];
    initialize(grid, i*j);
    sol(grid, i, j);
    draw(grid, i, j);
    delete[] grid;
    return 0;

}
