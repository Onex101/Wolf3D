/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:18:34 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 12:26:36 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_H
# define OS_H

# if defined(__APPLE__) && defined(__MACH__)
#  define OS 1
# elif defined(__linux__)
#  define OS 0
# endif

#endif
