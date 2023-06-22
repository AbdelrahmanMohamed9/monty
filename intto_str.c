#include <stdlib.h>

int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
	char *buff, int buff_size);
char *get_int(int num);
unsigned int _abs(int);


/**
 * get_int - Receives a character pointer to a newly created
 *	string that represents an integer.
 * @num: The number that will be converted to a string.
 *
 * Return: A pointer to a newly allocated string,
 *	or NULL if the memory allocation fails.
 */
char *get_int(int num)
{
	unsigned int tp;
	int lng = 0;
	long numberl = 0;
	char *rt;

	tp = _abs(num);
	lng = get_numbase_len(tp, 10);

	if (num < 0 || numberl < 0)
		lng++;
	rt = malloc(lng + 1);
	if (!rt)
		return (NULL);

	fill_numbase_buff(tp, 10, rt, lng);
	if (num < 0 || numberl < 0)
		rt[0] = '-';

	return (rt);
}

/**
 * _abs - Returns the absolute value of an integer.
 * @i: The integer for which the absolute
 *	value is to be obtained.
 *
 * Return: The unsigned integer that represents
 *	the absolute value of the integer i.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Retrieves the length of the buffer required
 *	to store an unsigned integer.
 * @num: The unsigned integer for which the required
 *	buffer length is to be obtained.
 * @base: The base for the number representation that
 *	will be used by the buffer.
 *
 * Return: An integer that represents the length of the buffer needed to
 *	store the unsigned integer (excluding the null terminator).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int ln = 1;

	while (num > base - 1)
	{
		ln++;
		num /= base;
	}
	return (ln);
}

/**
 * fill_numbase_buff - Populates a buffer with the appropriate
 *	numbers in the range up to base 36.
 * @num: The number to be converted to a string,
 *	using the specified base.
 * @base: The base to be used for the conversion of the number
 *	to a string. This implementation only works up to base 36.
 * @buff: The buffer that will be filled with the result of the conversion.
 * @buff_size: The size of the buffer, in bytes.
 *
 * Return: The return type of the function is always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rm, n = buff_size - 1;

	buff[buff_size] = '\0';
	while (n >= 0)
	{
		rm = num % base;
		if (rm > 9)
			buff[n] = rm + 87;
		else
			buff[n] = rm + '0';
		num /= base;
		n--;
	}
}
