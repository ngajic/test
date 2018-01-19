#include <stdio.h>
#include <string.h>
#include <math.h>
#include <utils.h>

/**
* @brief Checks if it is a prime number.
* This function checks if associated number is a prime number. Which means it
* does not have any positive divisor besides 1 and itself.
*
* @param[in] num is a variable where number being checked is stored;
* @return 1 if number is a prime, 0 otherwise!
*/
char isPrime(long num)
{
	long i;
	if((num <= 0) || (num%2 == 0))
		return 0;
	for(i = 3; i <= (int)floor(sqrt(num)); i += 2)
		if(num%i == 0)
			return 0;
	return 1;
}

/**
* @brief Returns array period.
* This function returns size of an inner array which can be repeated multiple
* times in order to get starting \e array.
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

/**
* @brief Prints the content of memory. 
* This function prints content of memory with size \e size, starting from 
* address \e addr.
* @param[in] addr is pointer to starting position of memory segment being printed. 
* @param[in] size is the length of memory segment being printed.
* @param[out] None.
*/
void printBytes(void* addr, unsigned short size)
{
	unsigned short i;
	unsigned char *pc = (unsigned char *)addr;
	
	printf("[ ");
	for(i = 0; i < size; i++)
	{
		printf("%02X ", pc[i]);
		if(i%4 == 3 && i != size - 1)
			printf("]\n[ ");		
	}
	printf("]\n");
}