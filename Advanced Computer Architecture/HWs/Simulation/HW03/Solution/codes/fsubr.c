#include <stdio.h>

float subtract(float in1, float in2)
{
    float ret = 0.0;
    asm ("fsubr %2, %0" : "=&t" (ret) : "%0" (in1), "u" (in2));
    return ret;
}

int main()
{
    float num1 = 10.5;
    float num2 = 5.3;
    float result = subtract(num1, num2);
    
    printf("The subtraction result is: %f\n", result);
    
    return 0;
}