#include "ft_ssl.h"

uint32_t	ptr_to_uint32_swap(t_byte *str)
{
	uint32_t		rslt;

	rslt = 0;
	rslt = (rslt | (t_byte)str[3]) << 8;
	rslt = (rslt | (t_byte)str[2]) << 8;
	rslt = (rslt | (t_byte)str[1]) << 8;
	rslt |= (t_byte)str[0];
	return (rslt);
}

uint32_t	ptr_to_uint32(t_byte *str)
{
	uint32_t		rslt;

	rslt = 0;
	rslt = (rslt | (t_byte)str[0]) << 8;
	rslt = (rslt | (t_byte)str[1]) << 8;
	rslt = (rslt | (t_byte)str[2]) << 8;
	rslt |= (t_byte)str[3];
	return (rslt);
}

uint64_t	ptr_to_uint64(t_byte *str)
{
	uint64_t		rslt;

	rslt = 0;
	rslt = (rslt | (t_byte)str[0]) << 8;
	rslt = (rslt | (t_byte)str[1]) << 8;
	rslt = (rslt | (t_byte)str[2]) << 8;
	rslt = (rslt | (t_byte)str[3]) << 8;
	rslt = (rslt | (t_byte)str[4]) << 8;
	rslt = (rslt | (t_byte)str[5]) << 8;
	rslt = (rslt | (t_byte)str[6]) << 8;
	rslt |= (t_byte)str[7];
	return (rslt);
}
