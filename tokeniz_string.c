#include <stdlib.h>

int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
char **strtow(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * is_delim - Function ckeks if stream has a delimitor char
 * @ch: character in the stream
 * @delims: A Pointer to null terminated array of delimitors
 * Return: 1 if (success) and 0 if (failure)
 */

int is_delim(char ch, char *delims)
{
	int a;

	for (a = 0; delims[a]; a++)
	{
		if (delims[a] == ch)
			return (1);
	}
	return (0);
}

/**
 * get_word_length - Function gets word len of cur word in str
 * @str: string to get word len from the current word
 * @delims: The delimiters to delimit words
 * Return: word len of the current word
 */

int get_word_length(char *str, char *delims)
{
	int len = 0, rest = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			rest = 1;
		else if (rest)
		{
			len++;
		}
		if (len > 0 && is_delim(str[a], delims))
			break;
		a++;
	}
	return (len);
}

/**
 * strtow - Function takes string and seperates to words
 * @str: string to be seperated to words
 * @delims: delimitors to delimit words
 * Return: 2D array of pointers
 */

char **strtow(char *str, char *delims)
{
	char **word = NULL;
	int word_count, word_len, n;
	int a = 0;

	if (str == NULL || !*str)
		return (NULL);
	word_count = get_word_count(str, delims);


	if (word_count == 0)
		return (NULL);
	word = malloc((word_count + 1) * sizeof(char *));
	if (word == NULL)
		return (NULL);
	while (a < word_count)
	{
		word_len = get_word_length(str, delims);
		if (is_delim(*str, delims))
			str = get_next_word(str, delims);
		word[a] = malloc((word_len + 1) * sizeof(char));
		if (word[a] == NULL)
		{
			while (a >= 0)
			{
				a--;
				free(word[a]);
			}
			free(word);
			return (NULL);
		}
		n = 0;
		while (n < word_len)
		{
			word[a][n] = *(str + n);
			n++;
		}
		word[a][n] = '\0';
		str = get_next_word(str, delims);
		a++;
	}
	word[a] = NULL;
	return (word);
}

/**
 * get_word_count - function gets the word count of a string
 * @str: string to get word count.
 * @delims: delimitors  to delimit words
 * Return: word count of a string
 */

int get_word_count(char *str, char *delims)
{
	int word_count = 0;
	int rest = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			rest = 1;
		else if (rest)
		{
			rest = 0;
			word_count++;
		}
		a++;
	}
	return (word_count);
}

/**
 * get_next_word - Function gets next word a string
 * @str: string to get next word
 * @delims: delimitors to delimit words
 * Return: pointer to the first char of the next word
 */

char *get_next_word(char *str, char *delims)
{
	int rest = 0;
	int a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			rest = 1;
		else if (rest)
			break;
		a++;
	}
	return (str + a);
}
