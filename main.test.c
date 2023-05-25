#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/getnextline/get_next_line.h"


int funtion(char **str)
{
    int i = 0;
    while (str[i] != NULL)
       i++;
    return (i);
}

int ft_isdigit(int n)
{
    if(n >= '0' && n <= '9')
        return (1);
    return (0);
}

int check_range(int n)
{
    if (n >= 0 && n <= 255)
    {
        printf("%d\n", n);
        return (1);
    }
    return (0);
}

int main(void)
{
    // char **split_coor = ft_split(line, ',');
     int i = 0;
    // if (count(split_coor) != 3)
    //     exit (1);
    char    *split_coor[] = {"-20.0", "-50.22", "10", NULL};
    while (split_coor[i] != NULL)
    {
        int j = 0;
        int count = 0;
        while(split_coor[i][j])
        {
            if (j == 0)
            {
                if ((!ft_isdigit(split_coor[i][0]) && split_coor[i][0] != '-') || (split_coor[i][0] == '-' && split_coor[i][1] == '.'))
                {
                    write(2, "Error1 !!\n", 10);
                    exit (1);
                }
            }
            else if (!ft_isdigit(split_coor[i][j]) && split_coor[i][j] != '.')
            {
                write(2, "Error2 !!\n", 10);
                exit (1);
            }
            else if (split_coor[i][j] == '.')
            {
                count++;
                if (count > 1)
                {
                    write(2, "Error3 !!\n", 10);
                    exit (1);
                }
            }
            j++;
        }
        i++;  
}
    // int fd;
    // fd = open("note.c", O_RDONLY);
    // int i = 0;
    // char *line;
    // while (1)
    // {
    //     line = get_next_line(fd);
    //     if (line == NULL)
    //         break ;
    // }
    return (0);
   
}
