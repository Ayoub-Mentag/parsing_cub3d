#include "get_next_line/get_next_line.h"
#include <stdbool.h>
#include <stdio.h>
#include "parsing.h"

bool    init_info(char *line, t_info *info)
{
    int i = 0;
    char    **result = ft_split(line, ' ');

    while (result[i])
        i++;
    if (i != 2)
        return (false);
    if (!strcmp(result[0], "NO"))
    {;
        if (!info->north)
        {
            info->north = strdup(result[1]);
            return (true);
        }
    }
    else if (!strcmp(result[0], "SO"))
    {;
        if (!info->south)
        {
            info->south = strdup(result[1]);
            return (true);
        }
    }
    else if (!strcmp(result[0], "WE"))
    {;
        if (!info->west)
        {
            info->west = strdup(result[1]);
            return (true);
        }
    }
    else if (!strcmp(result[0], "EA"))
    {;
        if (!info->east)
        {
            info->east = strdup(result[1]);
            return (true);
        }
    }
    else if (!strcmp(result[0], "C"))
    {
        if (!info->ceil)
        {
            info->ceil = strdup(result[1]);
            return (true);
        }
    }
    else if (!strcmp(result[0], "F"))
    {
        if (!info->floor)
        {
            info->floor = strdup(result[1]);
            return (true);
        }
    }
    return (false);
}

bool    check_option_map(int fd, t_info *info)
{
    char    *line;
    bool    r;
    int     i;

    i = 0;
    line = get_next_line(fd);
    while (line && i < 6)
    {
        if (strcmp(line, "\n"))
        {
            r = init_info(line, info);
            if (r == false)
                return (false);
            i++;
        }
        line = get_next_line(fd);
    }
    return (true);
}

bool    check(char *file_name, t_info *info)
{
    //TODO : check the file name is it correct

    int fd = open(file_name, O_RDONLY, 0777);
    //validation Options of the map 
    if (check_option_map(fd, info) == false)
        return (close(fd), false);
    return (true);
    // return (check_map(fd));
}

void    print_info(t_info info)
{
    printf("Info --- \n");
    printf("North %s\n South %s\n West %s\nEast %s\nCeil %s\nFloor %s\n", info.north, info.south, info.west, info.east, info.ceil, info.floor);
}

int main(int ac, char **av)
{
    t_info  info;

    if (ac != 2)
        return (write(2, "Error\n", 5), 1);
    //validation Options of the map 
    /*
        ◦ Except for the map content, each type of element can be separated by one or
        more empty line(s).
        ◦ Except for the map content which always has to be the last, each type of
        element can be set in any order in the file.
        ◦ Except for the map, each type of information from an element can be separated
        by one or more space(s).
    */
    //1- validations of the map
    /*
        The map must be composed of only 6 possible characters: 0 for an empty space,
        1 for a wall, and N,S,E or W for the player’s start position and spawning
        orientation
        The map must be closed/surrounded by walls, if not the program must return
        an error.
        ◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
        map and are up to you to handle. You must be able to parse any kind of map,
        as long as it respects the rules of the map.
    */


   info.ceil = NULL;
   info.floor = NULL;
   info.east = NULL;
   info.west = NULL;
   info.north = NULL;
   info.south = NULL;
    if (check(av[1], &info))
        print_info(info);
    else
        write(2, "Error\n", 6);
    //2- stock the map
    return (0);
}