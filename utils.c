#include <stdio.h>
#include <string.h>
#include <utils.h>

/**
* @brief Returns array period.
* That is, size of an inner array which can be repeated multiple times in order
* to get starting \e array.
*
* @param[in] array is a pointer to starting array.
* @param[in] size is the size of starting array.
* @return period of an array.
*/
int arrayPeriod(int *array, int size)
{
    char i = 1, k = 0, flag;

    for(i = 1; i < size; i <<= 1)  
    {
        flag = 1;
        for(k = i; k < size; k += i)
        {
            if(memcmp(&array[0], &array[k], i*sizeof(int)))
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            return i;
    }
    return size;
}


