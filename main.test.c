#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

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
    char *split_RGB[] = {"255", "255", "275", NULL};
    int i = 0;
    int j = 0;

    printf("-> %d\n", funtion(split_RGB));
    while (split_RGB[i] != NULL)
    {
        int j = 0;
        while(split_RGB[i][j])
        {
            if (!ft_isdigit(split_RGB[i][j]))
            {
                printf("%s\n", "error");
                exit (1);
            }
            j++;
        }
        i++;  
    }
// "255"
// "255"
// "255"                
        // else
        //     split_RGB = atoi(split_RGB);
        printf("%d\n", i);
    i = 0;
    while (split_RGB[i] != NULL)
    {
        
        if (check_range(atoi(split_RGB[i])) == 0)
        {
            write(2, "Error !!\n", 9);
            exit (EXIT_FAILURE);
        }
        i++;
    }
    return (0);
}
