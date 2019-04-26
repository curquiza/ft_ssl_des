#include "ft_ssl.h"

t_ex_ret		get_hash_algo(char *algo_arg, t_state *state, t_hash_algo *algo_tab)
{
	int		i;

	i = 0;
	while (i < HASH_FUNC_TAB_SIZE)
	{
		if (ft_strcmp(algo_tab[i].name, algo_arg) == 0)
		{
			state->hash_algo = &algo_tab[i];
			return SUCCESS;
		}
		i++;
	}
	return ft_ret_err(HASH_ALGO_ERR);
}
