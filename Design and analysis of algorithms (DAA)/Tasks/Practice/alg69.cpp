#include <iostream>
#include <vector>

#define infinity 2147483647

const int N = 5;

// Helper function
void swap(int array[N][N], int firstElementRow, int firstElementColumn, int secondElementRow, int secondElementColumn)
{
    int temp = array[firstElementRow][firstElementColumn];
    array[firstElementRow][firstElementColumn] = array[secondElementRow][secondElementColumn];
    array[secondElementRow][secondElementColumn] = temp;
}

// Declaration of functions
void quasiSortForTopLeft(int array[N][N], int rowIndexOfElement, int columnIndexOfElement);
void quasiSortForBottomRight(int array[N][N], int rowIndexOfElement, int columnIndexOfElement);

// Complexity is O(1) because all the function does is instant access to the top left element of an array
int returnMinElement(const int array[N][N])
{
    return array[0][0]; // O(1)
}

// Helper function
void swapRight(int array[N][N], int rowIndexOfElement, int columnIndexOfElement)
{
    int columnIndexRightElement = columnIndexOfElement + 1;
    swap(array, rowIndexOfElement, columnIndexOfElement, rowIndexOfElement, columnIndexRightElement);
}

void swapDown(int array[N][N], int rowIndexOfElement, int columnIndexOfElement)
{
    int rowIndexDownElement = rowIndexOfElement + 1;
    swap(array, rowIndexOfElement, columnIndexOfElement, rowIndexDownElement, columnIndexOfElement);
}

void swapUp(int array[N][N], int rowIndexOfElement, int columnIndexOfElement)
{
    int rowIndexUpElement = rowIndexOfElement - 1;
    swap(array, rowIndexOfElement, columnIndexOfElement, rowIndexUpElement, columnIndexOfElement);
}

void swapLeft(int array[N][N], int rowIndexOfElement, int columnIndexOfElement)
{
    int columnIndexLeftElement = columnIndexOfElement - 1;
    swap(array, rowIndexOfElement, columnIndexOfElement, rowIndexOfElement, columnIndexLeftElement);
}

// In worst case, this takes O(2n) = O(n) complexity
// Sorts in direction top-left to right-bottom
void quasiSortForTopLeft(int array[N][N], int rowIndexOfElement, int columnIndexOfElement)
{
    while (true)
    {
        int rowIndexDownElement = rowIndexOfElement + 1;
        int columnIndexRightElement = columnIndexOfElement + 1;

        int elementInQuestion = array[rowIndexOfElement][columnIndexOfElement];
        int rightElement = array[rowIndexOfElement][columnIndexRightElement];
        int downElement = array[rowIndexDownElement][columnIndexOfElement];

        // Firsly, if both elements that are to be checked are smaller or equal to the one in question, then we can terminate as the element in question is in it's correct placement
        // Edge cases
        if (rowIndexDownElement >= N && elementInQuestion <= rightElement)
        {
            return;
        }

        if (columnIndexRightElement >= N && elementInQuestion <= downElement)
        {
            return;
        }

        if (elementInQuestion <= rightElement && elementInQuestion <= downElement)
        {
            return;
        }

        // Validate we aren't going out of the array
        // And then start swapping in the correct direction

        if (rowIndexDownElement >= N)
        {
            // We go to the right until we reach the end
            if (columnIndexOfElement >= N)
            {
                return;
            }
            // We need to swap with right element
            swapRight(array, rowIndexOfElement, columnIndexOfElement);
            columnIndexOfElement = columnIndexRightElement;
        }
        else if (columnIndexRightElement >= N)
        {
            // We go to the bottom until we reach the end
            if (rowIndexOfElement >= N)
            {
                return;
            }
            // We need to swap with down element
            swapDown(array, rowIndexOfElement, columnIndexOfElement);
            rowIndexOfElement = rowIndexDownElement;
        }
        else
        {
            // Check if we need to go right or down
            if (rightElement <= downElement)
            {
                // We need to swap with right element
                swapRight(array, rowIndexOfElement, columnIndexOfElement);
                columnIndexOfElement = columnIndexRightElement;
            }
            else
            {
                // We need to swap with down element
                swapDown(array, rowIndexOfElement, columnIndexOfElement);
                rowIndexOfElement = rowIndexDownElement;
            }
        }
    }
}

// Sorts in direction right-bottom to top-left
void quasiSortForBottomRight(int array[N][N], int rowIndexOfElement, int columnIndexOfElement)
{
    while (true)
    {
        int rowIndexUpElement = rowIndexOfElement - 1;
        int columnIndexLeftElement = columnIndexOfElement - 1;

        int elementInQuestion = array[rowIndexOfElement][columnIndexOfElement];
        int leftElement = array[rowIndexOfElement][columnIndexLeftElement];
        int upElement = array[rowIndexUpElement][columnIndexOfElement];

        // Firsly, if both elements that are to be checked are smaller or equal to the one in question, then we can terminate as the element in question is in it's correct placement

        if (rowIndexUpElement < 0 && elementInQuestion >= leftElement)
        {
            return;
        }

        if (columnIndexLeftElement < 0 && elementInQuestion >= upElement)
        {
            return;
        }

        if (elementInQuestion >= leftElement && elementInQuestion >= upElement)
        {
            return;
        }

        // Validate we aren't going out of the array
        // And then start swapping in the correct direction

        if (rowIndexUpElement < 0)
        {
            // We go to the right until we reach the end
            if (columnIndexOfElement < 0)
            {
                return;
            }
            // We need to swap with left element
            swapLeft(array, rowIndexOfElement, columnIndexOfElement);
            columnIndexOfElement = columnIndexLeftElement;
        }
        else if (columnIndexLeftElement < 0)
        {
            // We go to the bottom until we reach the end
            if (rowIndexOfElement < 0)
            {
                return;
            }
            // We need to swap with up element
            swapUp(array, rowIndexOfElement, columnIndexOfElement);
            rowIndexOfElement = rowIndexUpElement;
        }
        else
        {
            // Check if we need to go left or up
            if (leftElement >= upElement)
            {
                // We need to swap with left element
                swapLeft(array, rowIndexOfElement, columnIndexOfElement);
                columnIndexOfElement = columnIndexLeftElement;
            }
            else
            {
                // We need to swap with up element
                swapUp(array, rowIndexOfElement, columnIndexOfElement);
                rowIndexOfElement = rowIndexUpElement;
            }
        }
    }
}

int removeMinimumFromArray(int array[N][N])
{
    int tempToReturn = returnMinElement(array); // O(1)

    // Replace the minimum element with infinity and reallocate the infinity to it's correct place
    array[0][0] = infinity;
    quasiSortForTopLeft(array, 0, 0);
    return tempToReturn;
}

// Assumes it is a correct opeation to add a number
void addNumberToArray(int array[N][N], int number)
{
    // array[N-1][N-1] must be infinity if the operation is correct
    array[N - 1][N - 1] = number;
    quasiSortForBottomRight(array, N - 1, N - 1);
}

std::vector<int> generateMultiSet(int array[N][N])
{
    std::vector<int> toReturn;
    for (int i = 0; i < N * N; i++)
    {
        int temp = removeMinimumFromArray(array);
        if (temp == infinity)
        {
            break;
        }
        toReturn.push_back(temp);
    }
    return toReturn;
}

int main()
{
    int matrix[N][N] = {
        2, 4, 6, 8, 10,
        12, 14, 16, 18, 20,
        22, 24, infinity, infinity, infinity,
        99, infinity, infinity, infinity, infinity,
        100, infinity, infinity, infinity, infinity};
        
    addNumberToArray(matrix, 12);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] == infinity)
            {
                std::cout << "X ";
            }
            else
            {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}