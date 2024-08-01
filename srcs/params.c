#include "../include/philosophers.h"

t_params	*params(void)
{
	static t_params	params;

	return (&params);
}
