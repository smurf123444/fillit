# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_tet {
	int			x[4];
	int			y[4];
	char		c;
}				t_tet;

typedef struct	s_map {
	char		**array;
	int			xmax;
	int			ymax;
}				t_map;

typedef struct	s_char {
	int			hash;
	int			dot;
	int			newline;
}				t_char;

char			*ft_extract_tetrimino(char *filename);
t_tet			**ft_read_all_tetrimino(char *tetrimino);
void			ft_free_map(t_map *map);
char			**ft_new_array(int x, int y);
int				ft_load_tetrimino(t_tet *t, t_map *map, int x, int y);
void			ft_remove_tetrimino(t_tet *t, t_map *map, int x, int y);
t_map			*ft_starting_map(char *tetrimino);
t_map			*ft_resize_map(t_map *old_map);
void			ft_print_array(char **array);
void			ft_print_tetrimino(t_tet *tetrimino);
char			**ft_fillit(char *tetrimino);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int num);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strnew(size_t size);
int				check_colrow(char *str, int tet);
void			*ft_memset(void *b, int c, size_t len);
int				main_check(char *str);
int				check_hash(char *str);

static int	tet_one(char *str, int i)
{
	int		col;
	int		row;

	while (str[i] != '\0')
	{
		row = 1;
		while (row < 5)
		{
			col = 1;
			while (str[i] != '\n')
			{
				col++;
				i++;
			}
			if (col != 5)
				return (1);
			row++;
			i++;
		}
		if (str[i] != '\0')
			return (1);
	}
	return (0);
}

static int	tet_multiple(char *str, int tet)
{
	int		i;
	int		col;
	int		row;

	i = -1;
	while (tet-- != 1 && str[++i] != '\0')
	{
		row = 0;
		while (++row < 5)
		{
			col = 1;
			while (str[i] != '\n' && col++ >= 0)
				i++;
			if (col != 5)
				return (1);
			i++;
		}
		if ((row == 5) && (str[i] != '\n'))
			return (1);
	}
	if (tet == 1 & str[i] != '\0')
		tet_one(str, i);
	return (0);
}

int			check_colrow(char *str, int tet)
{
	int val;

	if (tet == 1)
		val = tet_one(str, 0);
	if (tet > 1)
		val = tet_multiple(str, tet);
	if (val)
		return (1);
	else
		return (0);
}

/*
** Increments a counter each time a # has a neighboring #.
** Total number of times we should find a neighbor is 6.
*/

static int			count_neighbor(char *map, int i)
{
	int				n;

	n = 0;
	if (map[i - 1] == '#')
		n++;
	if (map[i - 5] == '#')
		n++;
	if (map[i + 1] == '#')
		n++;
	if (map[i + 5] == '#')
		n++;
	return (n);
}

/*
** Checks the number of #s and if adjacency is valid
*/

int					check_hash(char *str)
{
	int				hash;
	int				i;
	int				x;
	int				neighbor;

	i = 0;
	while (str[i] != '\0')
	{
		hash = 0;
		neighbor = 0;
		x = 0;
		while (x++ < 21)
		{
			if (str[i] == '#')
			{
				hash++;
				neighbor += count_neighbor(str, i);
				if (neighbor < 6 && hash == 4)
					return (1);
			}
			i++;
		}
	}
	return (0);
}

static int			check_chars(t_char *count)
{
	if (count->hash < 4)
		return (1);
	if (((count->hash % 4) != 0) || ((count->dot % 4) != 0)
		|| ((count->newline + 1) % 5 != 0))
		return (1);
	else
		return (0);
}

static t_char		*count_chars(char *str, int i)
{
	t_char			*count;

	count = (t_char*)malloc(sizeof(t_char));
	count->hash = 0;
	count->dot = 0;
	count->newline = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			count->hash++;
		if (str[i] == '.')
			count->dot++;
		if (str[i] == '\n')
			count->newline++;
		i++;
	}
	return (count);
}

int					main_check(char *str)
{
	t_char			*count;
	int				i;
	int				tet;

	i = 0;
	tet = 0;
	count = count_chars(str, i);
	if (check_chars(count))
		return (1);
	tet = count->hash / 4;
	if (check_colrow(str, tet))
		return (1);
	return (0);
}

char			**ft_new_array(int x, int y)
{
	char	**array;
	int		i;
	int		j;

	j = 0;
	array = (char**)malloc(sizeof(char*) * (y + 1));
	while (j < y)
	{
		i = 0;
		array[j] = (char*)malloc(sizeof(char) * (x + 1));
		while (i < x)
		{
			array[j][i] = '.';
			i++;
		}
		array[j][i] = '\0';
		j++;
	}
	array[j] = NULL;
	return (array);
}

static int		ft_starting_size(char *tetrimino)
{
	int x;
	int area;
	int square;

	x = 0;
	square = 0;
	area = ((ft_strlen(tetrimino) + 1) / 21) * 4;
	while ((x++ * square++) < area)
		;
	return (x - 1);
}

t_map			*ft_starting_map(char *tetrimino)
{
	int		x;
	int		y;
	t_map	*map;

	x = ft_starting_size(tetrimino);
	y = x;
	map = (t_map*)malloc(sizeof(t_map));
	map->array = ft_new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}

t_map			*ft_resize_map(t_map *old_map)
{
	int		x;
	int		y;
	t_map	*map;

	x = old_map->xmax + 1;
	y = old_map->ymax + 1;
	ft_free_map(old_map);
	map = (t_map*)malloc(sizeof(t_map));
	map->array = ft_new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}

static int		ft_is_legal(t_tet *t, t_map *map, int x, int y)
{
	if (x + t->x[1] < 0 || y + t->y[1] < 0)
		return (1);
	if (x + t->x[2] < 0 || y + t->y[2] < 0)
		return (1);
	if (x + t->x[3] < 0 || y + t->y[3] < 0)
		return (1);
	if (x + t->x[1] > (map->xmax - 1) || y + t->y[1] > (map->ymax - 1))
		return (1);
	if (x + t->x[2] > (map->xmax - 1) || y + t->y[2] > (map->ymax - 1))
		return (1);
	if (x + t->x[3] > (map->xmax - 1) || y + t->y[3] > (map->ymax - 1))
		return (1);
	return (0);
}

static int		ft_is_empty(t_tet *t, t_map *map, int x, int y)
{
	if (map->array[y][x] != '.')
		return (1);
	if (map->array[(y + t->y[1])][(x + t->x[1])] != '.')
		return (1);
	if (map->array[(y + t->y[2])][(x + t->x[2])] != '.')
		return (1);
	if (map->array[(y + t->y[3])][(x + t->x[3])] != '.')
		return (1);
	return (0);
}

void			ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->ymax)
	{
		free(map->array[i]);
		++i;
	}
	free(map->array);
	free(map);
}

int				ft_load_tetrimino(t_tet *t, t_map *map, int x, int y)
{
	if (ft_is_legal(t, map, x, y) == 1)
		return (0);
	else if (ft_is_empty(t, map, x, y) == 1)
		return (0);
	else
	{
		map->array[y][x] = t->c;
		map->array[(y + t->y[1])][(x + t->x[1])] = t->c;
		map->array[(y + t->y[2])][(x + t->x[2])] = t->c;
		map->array[(y + t->y[3])][(x + t->x[3])] = t->c;
	}
	return (1);
}

void			ft_remove_tetrimino(t_tet *t, t_map *map, int x, int y)
{
	map->array[y][x] = '.';
	map->array[(y + t->y[1])][(x + t->x[1])] = '.';
	map->array[(y + t->y[2])][(x + t->x[2])] = '.';
	map->array[(y + t->y[3])][(x + t->x[3])] = '.';
}

void	ft_print_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		++i;
	}
}

void	ft_print_tetrimino(t_tet *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putnbr(tetrimino->x[i]);
		ft_putchar(' ');
		ft_putnbr(tetrimino->y[i]);
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
}

static int		ft_backtracking(t_tet **pieces, t_map *map, int i)
{
	int x;
	int y;

	if (pieces[i] == NULL)
		return (1);
	y = 0;
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (ft_load_tetrimino(pieces[i], map, x, y))
			{
				if (ft_backtracking(pieces, map, i + 1))
					return (1);
				else
					ft_remove_tetrimino(pieces[i], map, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

char			**ft_fillit(char *tetrimino)
{
	t_tet	**pieces;
	t_map	*map;

	pieces = ft_read_all_tetrimino(tetrimino);
	map = ft_starting_map(tetrimino);
	while (!ft_backtracking(pieces, map, 0))
	{
		map = ft_resize_map(map);
	}
	return (map->array);
}

static t_tet	*ft_create_tetrimino(void)
{
	t_tet *piece;

	piece = (t_tet*)malloc(sizeof(t_tet));
	if (piece == NULL)
		return (NULL);
	return (piece);
}

static int		ft_find_origin(char *tetrimino, int index)
{
	while (tetrimino[index] != '#')
		++index;
	return (index);
}

static t_tet	*ft_read_tetrimino(char *tetrimino, int index)
{
	t_tet	*piece;
	int		newline;
	int		origin;
	int		i;

	i = 0;
	index = ft_find_origin(tetrimino, index);
	origin = index;
	newline = 0;
	piece = ft_create_tetrimino();
	while (i < 4)
	{
		if (tetrimino[index] == '\n')
		{
			++newline;
			origin += 5;
		}
		if (tetrimino[index] == '#')
		{
			piece->x[i] = (index - origin);
			piece->y[i++] = newline;
		}
		index++;
	}
	return (piece);
}

t_tet			**ft_read_all_tetrimino(char *tetrimino)
{
	t_tet	**puzzle;
	int		count;
	int		i;
	int		j;
	char	c;

	count = (ft_strlen(tetrimino) + 1) / 21;
	puzzle = (t_tet**)malloc(sizeof(t_tet*) * (count + 1));
	i = 0;
	j = 0;
	c = 'A';
	while (j < count)
	{
		puzzle[j] = ft_read_tetrimino(tetrimino, i);
		puzzle[j]->c = c;
		c++;
		i += 21;
		j++;
	}
	puzzle[j] = NULL;
	return (puzzle);
}

static int		legal_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (1);
		++i;
	}
	return (0);
}

static int		check_if_valid(char *str)
{
	int			len;

	len = ft_strlen(str);
	if (legal_char(str))
		return (1);
	if (main_check(str))
		return (1);
	if (check_hash(str))
		return (1);
	else
		return (0);
}

static char		*ft_append_str(void *ptr, size_t size)
{
	void		*newptr;
	size_t		old_size;

	newptr = (char*)malloc(sizeof(char) * size);
	ft_memset(newptr, 0, size);
	old_size = ft_strlen(ptr);
	ft_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}

char			*ft_extract_tetrimino(char *filename)
{
	char		*tetrimino;
	char		*temp;
	int			fd;
	int			ret;
	int			size;

	size = 22;
	fd = open(filename, O_RDONLY);
	tetrimino = ft_strnew(21);
	temp = ft_strnew(21);
	while ((ret = read(fd, temp, 21)))
	{
		ft_strcat(tetrimino, temp);
		size += 21;
		tetrimino = ft_append_str(tetrimino, size);
		ft_memset(temp, 0, 21);
	}
	if (check_if_valid(tetrimino))
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (tetrimino);
}

int		main(int argc, char **argv)
{
	char	*tetrimino;
	char	**solution;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	tetrimino = ft_extract_tetrimino(argv[1]);
	solution = ft_fillit(tetrimino);
	ft_print_array(solution);
	return (0);
}

