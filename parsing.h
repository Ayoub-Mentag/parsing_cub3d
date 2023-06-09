#include <string.h>
#include <stdlib.h>

#define CEIL 1
#define FLOOR 2
#define WEST 3
#define EAST 4
#define NORTH 5
#define SOUTH 6


typedef struct   s_info
{
    char    *north;
    char    *west;
    char    *east;
    char    *south;
    char    *ceil;
    char    *floor;
    int     floor_rgb[3];
    int     ceil_rgb[3];
    int     width;
    int     height;
} t_info;
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);