#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
//#include "./include/getnextline/get_next_line.h"
#include "include/minirt.h"


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

int check_range_vec(int n)
{
    if (n >= -1 && n <= 1)
        return (1);
    return (0);
}

int count(char **str)
{
    int i = 0;
    while (str[i] != NULL)
       i++;
    return (i);
}

int main(void)
{
    char *line;
    char **split_vec = ft_split(line, ',');
    int i = 0;
    if (count(split_vec) != 3)
        exit (1);
    while (split_vec[i] != NULL)
    {
        
        if (check_range_vec(atoi(split_vec[i])) == 0)
        {
            write(2, "Error !!\n", 9);
            exit (EXIT_FAILURE);
        }
        i++;
    }
    while (split_vec[i] != NULL)
    {
        int j = 0;
        int count = 0;
        while(split_vec[i][j])
        {
            if (!ft_isdigit(split_vec[i][0]) || split_vec[i][0] != '-' || (split_vec[i][0] == '-' && split_vec[i][1] == '.'))
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            else if (!ft_isdigit(split_vec[i][j]) && split_vec[i][j] != '.')
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            else if (split_vec[i][j] == '.')
            {
                count++;
                if (count > 1)
                {
                    write(2, "Error !!\n", 9);
                    exit (1);
                }
            }
            j++;
        }
        i++;  
    } 
    return (0); 
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
   

