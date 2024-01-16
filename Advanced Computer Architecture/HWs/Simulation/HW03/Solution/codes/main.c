#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct 
{
    float num1;
    float num2;
} RandomNumbers;

// FSUBR function
float subtract(float in1, float in2)
{
    float ret = 0.0;
    asm ("fsubr %2, %0" : "=&t" (ret) : "%0" (in1), "u" (in2));
    return ret;
}

// Generate two random number
void random_gen(const char* filename) 
{
    srand(time(NULL));

    // Generate two random floating-point numbers between -20 and 20
    float num1 = ((float)rand() / (float)RAND_MAX) * 40 - 20;
    float num2 = ((float)rand() / (float)RAND_MAX) * 40 - 20;

    FILE *file = fopen(filename, "w");

    if (file == NULL) 
    {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(file, "%.2f\n%.2f", num1, num2);

    fclose(file);

    printf("Generated %.2f and %.2f\n", num1, num2);
    printf("saved to %s.\n", filename);
}


// Read Number From File
RandomNumbers read_random_num(const char* filename) 
{
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) 
    {
        printf("Error opening the file.\n");
        RandomNumbers emptyNumbers = {0.0, 0.0};
        return emptyNumbers;
    }
    
    RandomNumbers numbers;
    
    fscanf(file, "%f\n%f", &(numbers.num1), &(numbers.num2));
    
    fclose(file);
    
    return numbers;
}


int main()
{
    random_gen("random_numbers.txt");
    printf("\n");
    RandomNumbers result = read_random_num("random_numbers.txt");

    printf("Number 1: %.2f\n", result.num1);
    printf("Number 2: %.2f\n", result.num2);

    printf("\n");


    float fsubr_result = subtract(result.num1, result.num2);
    
    printf("Result: (%.2f) - (%.2f) = %.2f\n\n", result.num2, result.num1, fsubr_result);

    
    return 0;
}