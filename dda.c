static	void	d_line(t_line line, t_point *pnt1, t_point *pnt2, t_param *p)
{
	int err;
	int m;

	err = line.dx + line.dy;
	while (1)
	{
		if (pnt1->x == pnt2->x && pnt1->y == pnt2->y)
			break ;
		m = 2 * err;
		if (m >= line.dy)
		{
			err += line.dy;
			pnt1->x += line.sx;
		}
		if (m <= line.dx)
		{
			err += line.dx;
			pnt1->y += line.sy;
		}
	}
}

void			dda(t_point *pnt1, t_point *pnt2, t_window *win)
{
	t_line line;

	line.dx = abs(pnt2->x - pnt1->x);
	line.dy = -(abs(pnt2->y - pnt1->y));
	line.sx = pnt1->x < pnt2->x ? 1 : -1;
	line.sy = pnt1->y < pnt2->y ? 1 : -1;
	d_line(line, pnt1, pnt2, win);
}