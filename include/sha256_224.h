/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_224.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <curquiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:18:05 by curquiza          #+#    #+#             */
/*   Updated: 2019/04/30 18:19:07 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_224_H
# define SHA256_224_H

# include "libft.h"

# define SHA256_MSG_LEN_BITS		64
# define SHA256_MSG_LEN_BYTES		SHA256_MSG_LEN_BITS / 8

# define SHA256_CHUNK_BITS			512
# define SHA256_CHUNK_BYTES			SHA256_CHUNK_BITS / 8

# define SHA256_DIGEST_BITS			256
# define SHA256_DIGEST_BYTES		SHA256_DIGEST_BITS / 8

# define SHA256_WORD_NB_FROM_CHUNK	16
# define SHA256_WORD_NB				64

# define SHA256_ROUNDS				64

# define SHA256_A0_INIT				0x6a09e667
# define SHA256_B0_INIT				0xbb67ae85
# define SHA256_C0_INIT				0x3c6ef372
# define SHA256_D0_INIT				0xa54ff53a
# define SHA256_E0_INIT				0x510e527f
# define SHA256_F0_INIT				0x9b05688c
# define SHA256_G0_INIT				0x1f83d9ab
# define SHA256_H0_INIT				0x5be0cd19

# define SHA224_A0_INIT				0xc1059ed8
# define SHA224_B0_INIT				0x367cd507
# define SHA224_C0_INIT				0x3070dd17
# define SHA224_D0_INIT				0xf70e5939
# define SHA224_E0_INIT				0xffc00b31
# define SHA224_F0_INIT				0x68581511
# define SHA224_G0_INIT				0x64f98fa7
# define SHA224_H0_INIT				0xbefa4fa4

# define SHA224_DIGEST_BITS			224
# define SHA224_DIGEST_BYTES		SHA224_DIGEST_BITS / 8

typedef struct	s_sha256_incr
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
}				t_sha256_incr;

uint32_t		g_k_sha256[SHA256_CHUNK_BYTES];

/*
** init
*/
void			message_padding_sha256_224(t_hash *data);

/*
** algo
*/
void			fill_words_sha256_224(uint32_t words[SHA256_WORD_NB],
					uint32_t i, t_hash *data);
void			run_one_chunk_sha256_224(uint32_t words[SHA256_WORD_NB],
					t_sha256_incr *rslt);
void			run_sha256_224_algo(t_hash *data, int alt);
void			fill_sha256_digest(t_hash *data);
void			fill_sha224_digest(t_hash *data);

#endif
