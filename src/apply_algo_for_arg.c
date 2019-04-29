#include "ft_ssl.h"

void	apply_hash_algo_for_arg(char *arg, t_hash *data, t_state *state)
{
	state->hash_algo->f(data);
	display_digest(arg, data, state);
	clean_hash_data(data);
}
