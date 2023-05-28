#include <string.h>
#include <stdlib.h>

typedef struct   s_info
{
    char    *north;
    char    *west;
    char    *east;
    char    *south;
    char    *ceil;
    char    *floor;
    int     map_start_at_line;
    int     width;
    int     height;

} t_info;

char	**ft_split(char const *s, char c);