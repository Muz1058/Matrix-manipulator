#include <iostream>
#include <fstream>
using namespace std;
void storeOutputInFile1(float**& arr, int& rows, int& cols);
void storeOutputInFile2(int result, int& rows, int& cols, char opr[]);
int countCol(ifstream& read);
int countRow(ifstream& read);
void inputByUser(float**& arr, int& rows, int& cols);
void inputByFile1(float**& arr, int& rows, int& cols);
void inputByFile2(float**& arr, int& rows, int& cols);
void display(float** arr, int rows, int cols);
void add(float** arr, int rows, int cols, int result_choice);
void multiply(float** arr, int rows, int cols, int result_choice);
void rowWiseAverage(float** arr, int rows, int cols, int result_choice);
void columnWiseAverage(float** arr, int rows, int cols, int result_choice);
void overallAverage(float** arr, int rows, int cols, int result_choice);
void rowWiseSorting(float** arr, int rows, int cols, int result_choice);
void columnWiseSorting(float** arr, int rows, int cols, int result_choice);
void addScalar(float** arr, int rows, int cols, float scalar, int result_choice);
void addMatrices(float** arr1, float** arr2, int rows, int cols, int result_choice);
void subtractScalar(float** arr, int rows, int cols, float scalar, int result_choice);
void subtractMatrices(float** arr1, float** arr2, int rows, int cols, int result_choice);
void multiplyScalar(float** arr, int rows, int cols, float scalar, int result_choice);
void multiplyMatrices(float** arr1, float** arr2, int rows, int cols, int result_choice);
void scalarDivision(float** arr, int rows, int cols, float scalar, int result_choice);
void transpose(float** arr, int rows, int cols, int result_choice);
float determinant(float** arr, int rows, int cols);
void inverse(float** arr, int rows, int cols, int result_choice);
// Function to store matrix output in a file
void storeOutputInFile1(float**& arr, int& rows, int& cols)
{
    char filename[50];
    cout << "\n\t\t\t\t\tEnter File Name with extension e.g(File.txt) : ";
    cin.ignore();
    cin.getline(filename, 50);
    ofstream write(filename);
    if (!write)
    {
        cout << "\n\t\t\t\t\tError opening file for writing!!" << endl;
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            write << arr[i][j] << " ";
        }
        write << endl;
    }
    if (write)
    {
       
        cout << "\n\t\t\t\t\tData Successefully stored in " << filename << endl;
    }
    write.close();
}
// Function to store scalar operation output in a file
void storeOutputInFile2(int result, int& rows, int& cols, char opr[])
{
    char filename[50];
    cout << "\n\t\t\t\t\tEnter File Name with extension e.g(File.txt) : ";
    cin.ignore();
    cin.getline(filename, 50);
    ofstream write(filename);
    if (!write)
    {
        cout << "\n\t\t\t\t\tError opening file for writing!!" << endl;
        return;
    }
    write << opr << " = " << result;
    if (write)
    {
        cout << "\n\t\t\t\t\tData Successefully stored in " << filename << endl;
    }
    write.close();
}
// Function to count columns in a file
int countCol(ifstream& read)
{
    char ch[100];
    int col = 0;
    while (read.getline(ch, 100, '\n'))
    {
        int i = 0;
        while (ch[i] != '\0')
        {
            if (ch[i] != ' ')
            {
                col++;
            }
            if (ch[i] == '.')
            {
                col -= 2;
            }
            i++;
        }o
        break;
       
    }
    return col;
}
// Function to count rows in a file
int countRow(ifstream& read) {
    char ch[100];
    int row = 0;
    while (read.getline(ch, 100, '\n'))
    {
        int i = 0;
        if (ch[i] == '.')
        {
            row -= 2;
        }
        row++, i++;
    }
    return row;
}
// Function to input matrix from user
void inputByUser(float**& arr, int& rows, int& cols)
{

    do
    {
        cout << "\t\t\t\t\tEnter number of rows: ";
        cin >> rows;
    } while (rows <= 0);

    do
    {
        cout << "\t\t\t\t\tEnter number of columns: ";
        cin >> cols;
    } while (cols <= 0);

    arr = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "\n\t\t\t\t\tEnter value for arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "\n\t\t\t\t\tEnter value for arr[" << i << "][" << j << "] = " << arr[i][j];
        }
    }
}
// Function to input matrix from file 1
void inputByFile1(float**& arr, int& rows, int& cols)
{
    ifstream read("file1.txt");
    if (!read.is_open())
    {
        cout << "\t\t\t\t\tFailed to open file." << endl;
        return;
    }
    cols = countCol(read);
   
    read.clear();
    read.seekg(0, ios::beg);
    rows = countRow(read);
    read.clear();
    read.seekg(0, ios::beg);

    arr = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            read >> arr[i][j];
        }
    }
    read.close();
}
// Function to input matrix from file 2
void inputByFile2(float**& arr, int& rows, int& cols)
{
    ifstream read("file2.txt");
    if (!read.is_open()) {
        cout << "\t\t\t\t\tFailed to open file." << endl;
        return;
    }
    cols = countCol(read);
    read.clear();
    read.seekg(0, ios::beg);
    rows = countRow(read);
    read.clear();
    read.seekg(0, ios::beg);

    arr = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            read >> arr[i][j];
        }
    }
    read.close();
}
// Function to display matrix
void display(float** arr, int rows, int cols)
{
    if (cols == 0)
    {
        cout << "\t\t\t\t\t No Data Fount !!";
    }
    cout << "\t\t\t\t\t";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl << "\t\t\t\t\t";
    }
}
// Function to add matrices
void add(float** arr, int rows, int cols, int result_choice)
{
    float sum = 0;
    char opr[5] = "SUM";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << "\n\t\t\t\t\t----------->Addition of Matrix<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile2(sum, rows, cols, opr);
    }
    else if (result_choice == 2)
    {
        cout << "\n\t\t\t\t\tSum = " << sum << endl;
    }
    else if (result_choice == 3)
    {
        storeOutputInFile2(sum, rows, cols, opr);
        cout << "\n\t\t\t\t\tSum = " << sum << endl;
    }

}
// Function to multiply matrices
void multiply(float** arr, int rows, int cols, int result_choice)
{
    double product = 1;
    char opr[8] = "Product";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            product *= arr[i][j];
        }
    }
    cout << "\n\t\t\t\t\t----------->Multiplication of Matrix<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile2(product, rows, cols, opr);
    }
    else if (result_choice == 2)
    {
        cout << "\n\t\t\t\t\tMultiplication = " << product << endl;
    }
    else if (result_choice == 3)
    {
        storeOutputInFile2(product, rows, cols, opr);
        cout << "\n\t\t\t\t\tMultiplication = " << product << endl;
    }

}
// Function to calculate row-wise average
void rowWiseAverage(float** arr, int rows, int cols, int result_choice)
{
    char opr[8] = "Product";
    for (int i = 0; i < rows; i++)
    {
        double sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
        double average = sum / cols;
        cout << "\n\t\t\t\t\t----------->Row Wise Average<-------------\n";
        if (result_choice == 1)
        {
            storeOutputInFile2(average, rows, cols, opr);
        }
        else if (result_choice == 2)
        {
            cout << "\t\t\t\t\tAverage of row " << i << ": " << average << endl;
        }
        else if (result_choice == 3)
        {
            storeOutputInFile2(average, rows, cols, opr);
            cout << "\t\t\t\t\tAverage of row " << i << ": " << average << endl;
        }

    }
}
// Function to calculate column-wise average
void columnWiseAverage(float** arr, int rows, int cols, int result_choice)
{
    char opr[8] = "Average";
    for (int j = 0; j < cols; j++)
    {
        double sum = 0;
        for (int i = 0; i < rows; i++)
        {
            sum += arr[i][j];
        }
        double average = sum / rows;
        cout << "\n\t\t\t\t\t----------->Column Wise Average<-------------\n";

        if (result_choice == 1)
        {
            storeOutputInFile2(average, rows, cols, opr);
        }
        else if (result_choice == 2)
        {
            cout << "\t\t\t\t\tAverage of column " << j << ": " << average << endl;
        }
        else if (result_choice == 3)
        {
            storeOutputInFile2(average, rows, cols, opr);
            cout << "\t\t\t\t\tAverage of column " << j << ": " << average << endl;
        }

    }
}
// Function to calculate overall average
void overallAverage(float** arr, int rows, int cols, int result_choice)
{
    char opr[8] = "Average";
    double sum = 0;
    int denominator = rows * cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }

    double average = sum / denominator;
    cout << "\n\t\t\t\t\t----------->OverAll Average<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile2(average, rows, cols, opr);
    }
    else if (result_choice == 2)
    {
        cout << "\t\t\t\t\tOverall average = " << average << endl;
    }
    else if (result_choice == 3)
    {
        storeOutputInFile2(average, rows, cols, opr);
        cout << "\t\t\t\t\tOverall average = " << average << endl;
    }

}
// Function to sort rows of a matrix
void rowWiseSorting(float** arr, int rows, int cols, int result_choice)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = j + 1; k < cols; k++)
            {
                if (arr[i][j] > arr[i][k])
                {
                    float temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
            }
        }
    }
    cout << "\n\t\t\t\t\t----------->Row wise Sorting<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile1(arr, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr, rows, cols);
        display(arr, rows, cols);
    }
}
// Function to sort columns of a matrix
void columnWiseSorting(float** arr, int rows, int cols, int result_choice)
{
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int k = i + 1; k < rows; k++)
            {
                if (arr[i][j] > arr[k][j])
                {
                    float temp = arr[i][j];
                    arr[i][j] = arr[k][j];
                    arr[k][j] = temp;
                }
            }
        }
    }
    cout << "\n\t\t\t\t\t----------->Column wise Sorting<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile1(arr, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr, rows, cols);
        display(arr, rows, cols);
    }
}
// Function to add scalar to matrix
void addScalar(float** arr, int rows, int cols, float scalar, int result_choice)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] += scalar;
        }
    }
    cout << "\n\t\t\t\t\t----------->Scalar Addition<-------------\n";
    cout << "\t\t\t\t\tScalar = " << scalar << endl << endl;
    if (result_choice == 1)
    {
        storeOutputInFile1(arr, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr, rows, cols);
        display(arr, rows, cols);
    }
}
// Function to add two matrices
void addMatrices(float** arr1, float** arr2, int rows, int cols, int result_choice)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr1[i][j] += arr2[i][j];
        }
    }
    cout << "\n\t\t\t\t\t----------->Addition OF Matrices<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile1(arr1, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr1, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr1, rows, cols);
        display(arr1, rows, cols);
    }
}
// Function to subtract scalar from matrix
void subtractScalar(float** arr, int rows, int cols, float scalar, int result_choice)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] -= scalar;
        }
    }
    cout << "\n\t\t\t\t\t----------->Scalar Subtraction<-------------\n";
    cout << "\t\t\t\t\tScalar = " << scalar << endl << endl;
    if (result_choice == 1)
    {
        storeOutputInFile1(arr, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr, rows, cols);
        display(arr, rows, cols);
    }
}
// Function to subtract one matrix from another
void subtractMatrices(float** arr1, float** arr2, int rows, int cols, int result_choice)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr1[i][j] -= arr2[i][j];
        }
    }
    cout << "\n\t\t\t\t\t----------->Subtracrion Of Matrices<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile1(arr1, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr1, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr1, rows, cols);
        display(arr1, rows, cols);
    }
}
// Function to multiply scalar with matrix
void multiplyScalar(float** arr, int rows, int cols, float scalar, int result_choice)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] *= scalar;
        }
    }
    cout << "\n\t\t\t\t\t----------->Scalar Multiplication<-------------\n";
    cout << "\t\t\t\t\tScalar = " << scalar << endl << endl;
    if (result_choice == 1)
    {
        storeOutputInFile1(arr, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr, rows, cols);
        display(arr, rows, cols);
    }
}
// Function to multiply two matrices
void multiplyMatrices(float** arr1, float** arr2, int rows, int cols, int result_choice)
{
    float** result = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new float[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout << "\n\t\t\t\t\t----------->Multiplication Of Matrices<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile1(arr1, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr1, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr1, rows, cols);
        display(arr1, rows, cols);
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] result[i];
    }
    delete[] result;
}
// Function to divide matrix by scalar
void scalarDivision(float** arr, int rows, int cols, float scalar, int result_choice)
{
    if (scalar == 0)
    {
        cout << "\t\t\t\t\tError: Cannot divide by zero!!" << endl;
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] /= scalar;
        }
    }
    cout << "\n\t\t\t\t\t----------->Scalar Division<-------------\n";
    cout << "\t\t\t\t\tScalar = " << scalar << endl << endl;
    if (result_choice == 1)
    {
        storeOutputInFile1(arr, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr, rows, cols);
        display(arr, rows, cols);
    }
}
// Function to transpose matrix
void transpose(float** arr, int rows, int cols, int result_choice)
{
    float** result = new float* [cols];
    for (int i = 0; i < cols; i++)
    {
        result[i] = new float[rows];
    }

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            result[j][i] = arr[i][j];
        }
    }
    cout << "\n\t\t\t\t\t----------->Transpose<-------------\n";
    if (result_choice == 1)
    {
        storeOutputInFile1(arr, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(arr, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(arr, rows, cols);
        display(arr, rows, cols);
    }
    for (int i = 0; i < cols; i++)
    {
        delete[] result[i];
    }
    delete[] result;
}
// Function to calculate determinant of a matrix
float determinant(float** arr, int rows, int cols)
{
    char opr[12] = "Determinant";
    int det = 0;
    if (rows == 1)
    {
        det = arr[0][0];
    }
    else if (rows == 2)
    {
        det = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    }
    else
    {
        for (int i = 0; i < cols; i++)
        {
            float** minor = new float* [rows - 1];
            for (int j = 1; j < rows; j++)
            {
                minor[j - 1] = new float[cols - 1];
                int k = 0;
                for (int l = 0; l < cols; l++)
                {
                    if (l != i)
                    {
                        minor[j - 1][k] = arr[j][l];
                        k++;
                    }
                }
            }
            det += (i % 2 == 0 ? 1 : -1) * arr[0][i] * determinant(minor, rows - 1, cols - 1);
            for (int j = 0; j < rows - 1; j++)
            {
                delete[] minor[j];
            }
            delete[] minor;
        }
    }

    return det;
}
// Function to calculate inverse of a matrix
void inverse(float** arr, int rows, int cols, int result_choice)
{
    int det = determinant(arr, rows, cols);
    if (det == 0)
    {
        cout << "\n\t\t\t\t\tMatrix inverse is not possible!" << endl;
        return;
    }
    cout << "\n\t\t\t\t\t----------->Inverse<-------------\n";
    float** inverse = new float* [rows];
    for (int i = 0; i < rows; ++i)
    {
        inverse[i] = new float[cols];
    }
    float** minor = new float* [rows - 1];
    for (int i = 0; i < rows - 1; ++i)
    {
        minor[i] = new float[cols - 1];
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int minorRow = 0, minorCol = 0;
            for (int k = 0; k < rows; ++k)
            {
                if (k == i)
                    continue;
                minorCol = 0;
                for (int l = 0; l < cols; ++l)
                {
                    if (l == j)
                        continue;
                    minor[minorRow][minorCol] = arr[k][l];
                    ++minorCol;
                }
                ++minorRow;
            }
            int minorDet = determinant(minor, rows - 1, cols - 1);
            if ((i + j) % 2 == 0)
                inverse[j][i] = float(minorDet) / float(det);
            else
                inverse[j][i] = -float(minorDet) / float(det);
        }
    }
    if (result_choice == 1)
    {
        storeOutputInFile1(inverse, rows, cols);
    }
    else if (result_choice == 2)
    {
        display(inverse, rows, cols);
    }
    else if (result_choice == 3)
    {
        storeOutputInFile1(inverse, rows, cols);
        display(inverse, rows, cols);
    }
    for (int i = 0; i < rows - 1; ++i)
    {
        delete[] minor[i];
    }
    delete[] minor;

    for (int i = 0; i < rows; ++i)
    {
        delete[] inverse[i];
    }
    delete[] inverse;
}

int main()
{
    int rows = 0, cols = 0, input_choice, operation_choice, file_choice, result_choice;
    float** arr = nullptr;
    float scalar = 0;
    int count = 0;
    
    cout << "\t\t\t\t|----------------------------------------------------------------------------|\n";
    cout << "\t\t\t\t|                                                                            |\n";
    cout << "\t\t\t\t|                              MATRIX MANIPULATOR                            |\n";
    cout << "\t\t\t\t|                                                                            |\n";
    cout << "\t\t\t\t|----------------------------------------------------------------------------|\n";
    cout << "\t\t\t\t|                                                                            |\n";
    cout << "\t\t\t\t|                                  WELCOME                                   |\n";
    cout << "\t\t\t\t|                                                                            |\n";
  
    do
    {
        cout << "\t\t\t\t|----------------------------------------------------------------------------|\n";
        cout << "\t\t\t\t|              <-----------------Operations------------------>               |\n";
        cout << "\t\t\t\t|                                                                            |\n";
        cout << "\t\t\t\t| 1. Sum of Matrix                                                           |\n";
        cout << "\t\t\t\t| 2. Product of Matrix                                                       |\n";
        cout << "\t\t\t\t| 3. Row-wise Average                                                        |\n";
        cout << "\t\t\t\t| 4. Column-wise Average                                                     |\n";
        cout << "\t\t\t\t| 5. Overall Average                                                         |\n";
        cout << "\t\t\t\t| 6. Row-wise sorting                                                        |\n";
        cout << "\t\t\t\t| 7. Column-wise sorting                                                     |\n";
        cout << "\t\t\t\t| 8. Add Scalar                                                              |\n";
        cout << "\t\t\t\t| 9. Add Matrices (Dimensions must match)                                    |\n";
        cout << "\t\t\t\t|10. Subtract Scalar                                                         |\n";
        cout << "\t\t\t\t|11. Subtract Matrices (Dimensions must match)                               |\n";
        cout << "\t\t\t\t|12. Multiply by Scalar                                                      |\n";
        cout << "\t\t\t\t|13. Multiply Matrices                                                       |\n";
        cout << "\t\t\t\t|14. Divide by Scalar                                                        |\n";
        cout << "\t\t\t\t|15. Transpose Matrix                                                        |\n";
        cout << "\t\t\t\t|16. Determinant                                                             |\n";
        cout << "\t\t\t\t|17. Inverse                                                                 |\n";
        cout << "\t\t\t\t| 0. Exit                                                                    |\n";
        cout << "\t\t\t\t|                                                                            |\n";
        cout << "\t\t\t\t|         <-----------------Select operation(0-17)------------------>        |\n";
        cout << "\t\t\t\t|                                                                            |\n";
        cout << "\t\t\t\t|----------------------------------------------------------------------------|\n";
        cout << "\t\t\t\t\tEnter Operation Number (0-17) :: ";       
        cin >> operation_choice;
        if (operation_choice == 0)
        {
            cout << "\n\t\t\t\t\t--------------------------EXIT----------------------------\n";
            cout << "\t\t\t\t\t|        Thanks for using our Matrix Mainpulator!        |\n";
            cout << "\t\t\t\t\t|                        Good Bye!                       |\n";
            cout << "\t\t\t\t\t----------------------------------------------------------\n";
            return 0;
        }
        while (operation_choice < 0 || operation_choice>17)
        {
            cout << "\n\t\t\t\t\tInvalid Operation Choice!\n\t\t\t\t\tTry again!\n";
            cout << "\t\t\t\t\tEnter Operation Number (0-17) :: ";
            cin >> operation_choice;
        }
        //input scalar
        if (operation_choice == 8 || operation_choice == 10 || operation_choice == 12 || operation_choice == 14) {
            cout << "\t\t\t\t\tEnter Scalar: ";
            cin >> scalar;
        }
        //input choice
        do
        {
            cout << "\n\n\t\t\t\t\t------------------------>Input Options<---------------------\n";
            cout << "\t\t\t\t\t| Enter 1 to input matrix from file.                       |\n";
            cout << "\t\t\t\t\t| Enter 2 to input matrix from user.                       |\n";
            cout << "\t\t\t\t\t------------------------------------------------------------\n";
            cout << "\t\t\t\t\tEnter input option (1/2): ";
            cin >> input_choice;
            if (input_choice < 1 && input_choice > 2)
            {
                cout << "\t\t\t\t\tInvalid Input Choice!!\n\t\t\t\t\tTry Again\n";
            }
        } while ((input_choice < 1 || input_choice>2));
        //result choice
        do
        {
            cout << "\n\n\t\t\t\t\t--------------------->Select Output Options<----------------\n";
            cout << "\t\t\t\t\t| Enter 1 to store result in File.                         |\n";
            cout << "\t\t\t\t\t| Enter 2 to show result on console.                       |\n";
            cout << "\t\t\t\t\t| Enter 3 for Both.                                        |\n";
            cout << "\t\t\t\t\t----------------------------------------------------------\n";
            cout << "\t\t\t\t\tEnter option (1/2/3): ";
            cin >> result_choice;
            if (result_choice < 1 || result_choice>3)
            {
                cout << "\t\t\t\t\tInvalid Choice!! Try Again \n";
            }

        } while (result_choice < 1 || result_choice>3);
        //input
        if (input_choice == 1)
        {
            //input file options
            do
            {
                cout << "\n\n\t\t\t\t\t------------------------>File Options<--------------------\n";
                cout << "\t\t\t\t\t| Enter 1 to input from file1.txt.                       |\n";
                cout << "\t\t\t\t\t| Enter 2 to input from file2.txt.                       |\n";
                cout << "\t\t\t\t\t----------------------------------------------------------\n";
                cout << "\t\t\t\t\tEnter file option (1/2): ";
                cin >> file_choice;
                if (file_choice == 1)
                {
                    inputByFile1(arr, rows, cols);
                }
                else if (file_choice == 2)
                {
                    inputByFile2(arr, rows, cols);
                }
                else
                {
                    cout << "\t\t\t\t\tInvalid file choice!! Try Again" << endl;

                }
            } while (file_choice < 1 || file_choice>2);
        }
        else if (input_choice == 2)
        {
            inputByUser(arr, rows, cols);
        }

        cout << "\n\t\t\t\t\t----------->Display Matrix<-------------\n" << endl;
        display(arr, rows, cols);
        if (operation_choice == 9 || operation_choice == 11 || operation_choice == 13)
        {
            int row_check = rows, col_check = cols; // Save original rows and cols
            bool match = true; // Flag to check if matrices match
            float** arr2 = nullptr;
            if (input_choice == 2)
            {
                cout << "\n\t\t\t\t\tEnter second matrix:\n";
                inputByUser(arr2, rows, cols); // Assuming inputByUser allocates memory for arr2
                cout << "\n\t\t\t\t\t----------->Display Second Matrix<-------------\n" << endl;
                display(arr2, rows, cols);
            }
            else if (input_choice == 1)
            {
                do
                {
                    cout << "\n\n\t\t\t\t\t--------------------->Second File Options<----------------\n";
                    cout << "\t\t\t\t\t| Enter 1 to input from file1.txt.                       |\n";
                    cout << "\t\t\t\t\t| Enter 2 to input from file2.txt.                       |\n";
                    cout << "\t\t\t\t\t----------------------------------------------------------\n";
                    cout << "\t\t\t\t\tEnter file option (1/2): ";
                    cin >> file_choice;
                    if (file_choice == 1)
                    {
                        inputByFile1(arr2, rows, cols); // Assuming inputByFile1 allocates memory for arr2
                    }
                    else if (file_choice == 2)
                    {
                        inputByFile2(arr2, rows, cols); // Assuming inputByFile2 allocates memory for arr2
                    }
                    else
                    {
                        cout << "\n\t\t\t\tInvalid Choice!! Try Again \n";
                    }
                } while (file_choice < 1 || file_choice > 2);

                cout << "\n\t\t\t\t\t----------->Display Second Matrix<-------------\n" << endl;
                display(arr2, rows, cols);
            }
            if ((operation_choice == 9 || operation_choice == 11 || operation_choice == 13) && (row_check != rows || col_check != cols))
            {
                cout << "\n\t\t\t\t\tMatrix dimensions do not match for addition or subtraction!" << endl;
                match = false;
            }
            if (match)
            {
                if (operation_choice == 9)
                {
                    addMatrices(arr, arr2, row_check, col_check, result_choice);
                }
                else if (operation_choice == 11)
                {
                    subtractMatrices(arr, arr2, row_check, col_check, result_choice);
                }
                else if (operation_choice == 13)
                {
                    multiplyMatrices(arr, arr2, row_check, col_check, result_choice);
                }
            }
            for (int i = 0; i < rows; i++)
            {
                delete[] arr2[i];
            }
            delete[] arr2;
        }
        else
        {
            switch (operation_choice)
            {
            case 1:
                add(arr, rows, cols, result_choice);
                break;
            case 2:
                multiply(arr, rows, cols, result_choice);
                break;
            case 3:
                rowWiseAverage(arr, rows, cols, result_choice);
                break;
            case 4:
                columnWiseAverage(arr, rows, cols, result_choice);
                break;
            case 5:
                overallAverage(arr, rows, cols, result_choice);
                break;
            case 6:
                rowWiseSorting(arr, rows, cols, result_choice);
                break;
            case 7:
                columnWiseSorting(arr, rows, cols, result_choice);
                break;
            case 8:
                addScalar(arr, rows, cols, scalar, result_choice);
                break;
            case 10:
                subtractScalar(arr, rows, cols, scalar, result_choice);
                break;
            case 12:
                multiplyScalar(arr, rows, cols, scalar, result_choice);
                break;
            case 14:
                scalarDivision(arr, rows, cols, scalar, result_choice);
                break;
            case 15:
                transpose(arr, rows, cols, result_choice);
                break;
            case 16:
            {
                int Determinant = determinant(arr, rows, cols);
                char opr[12] = "Determinant";
                cout << "\n\t\t\t\t\t----------->Determinant<-------------\n";
                if (result_choice == 1)
                {
                    storeOutputInFile2(Determinant, rows, cols, opr);
                }
                else if (result_choice == 2)
                {
                    cout << "\n\t\t\t\t\tDeterminant = " << Determinant;
                }
                else if (result_choice == 3)
                {
                    storeOutputInFile2(Determinant, rows, cols, opr);
                    cout << "\n\n\t\t\t\t\tDeterminant = " << Determinant;
                }
            }
            break;
            case 17:
                inverse(arr, rows, cols, result_choice);
                break;

            default:
                cout << "\t\t\t\t\tInvalid operation choice. Please enter a number between 0 and 17." << endl;
                continue;
            }
        }
        cout << "\n\t\t\t\t\tDo you want to perform another operation? (y/n): ";
        char again;
        cin >> again;
        if (again == 'y' || again == 'Y')
        {
            system("CLS");
            continue;
        }
        else
        {
            cout << "\n\t\t\t\t\t----------------------------------------------------------\n";
            cout << "\t\t\t\t\t|        Thanks for using our Matrix Mainpulator!        |\n";
            cout << "\t\t\t\t\t|                        Good Bye!                       |\n";
            cout << "\t\t\t\t\t----------------------------------------------------------\n";
            break;
        }
    } while (true);
   
    return 0;
}
