#include "get_next_line.h"

char *ft_dup(char *str)
{
	char *dst;
	int i;

	i = 0;
	while(str[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while(str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


char	  *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	char	line[100000];

	int i;
	int j;
	int	bytes;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	j = 0;
	while(1)
	{
		i = 0;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
				buffer[bytes] = '\0';
				while (buffer[i])
					line[j++] = buffer[i++];
		}
		else
		{
			if (j == 0)
				return(NULL);
			line[j] = '\0';
			break;
		}
	}
	return (ft_dup(line));
}



// int main ()
// {
// 	int fd = open("txt.txt", O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	close (fd);
// }




