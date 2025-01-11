/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:51:45 by gmasid            #+#    #+#             */
/*   Updated: 2022/05/17 16:46:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

static int get_len(long n) {
  size_t result = 0;

  if (n < 0) {
    result++;
    n = -n;
  }

  while (n) {
    result++;
    n /= 10;
  }

  return (result);
}

static char *generate(char *result, long nbr, int len, int isneg) {
  if (nbr == 0)
    return (result = ft_strdup("0"));

  result = malloc(sizeof(char) * (len + 1));

  if (!result)
    return (0);

  isneg = 0;

  if (nbr < 0) {
    isneg = 1;
    nbr = -nbr;
  }

  result[len] = '\0';

  while (--len) {
    result[len] = (nbr % 10) + '0';
    nbr /= 10;
  }

  if (isneg == 1)
    result[0] = '-';
  else
    result[0] = (nbr % 10) + '0';

  return (result);
}

char *itoa(int n) {
  long nbr = n;
  int isneg = 0;
  int len = get_len(nbr);
  char *result = 0;

  result = generate(result, nbr, len, isneg);

  if (!result)
    return (0);

  return (result);
}
