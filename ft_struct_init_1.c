#include "wolf3d."

t_vec2  *ft_vec2_init(double x, double y)
{
    t_vec2  *new;

    new = NULL;
    if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
    {
        new->x = x;
        new->y = y;
    }
    return (new);
}

t_pnt  *ft_pnt_init(int x, int y)
{
    t_pnt  *new;

    new = NULL;
    if ((new = (t_pnt *)malloc(sizeof(t_pnt))))
    {
        new->x = x;
        new->y = y;
    }
    return (new);
}

t_line  *ft_line_init(double x1, double y1, double x2, double y2)
{
    t_line  *new;

    new = NULL;
    if ((new = (t_line *)malloc(sizeof(t_line))))
    {
        new->x = x;
        new->y = y;
    }
    return (new);
}