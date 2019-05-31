/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:47:16 by jterrazz          #+#    #+#             */
/*   Updated: 2019/06/01 00:36:48 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./test.h"
#include <stdio.h>
#include <unistd.h>

static void test_malloc_null()
{
    void *t = malloc(0);
    if (t)
        printf("malloc(0) should return NULL\n");
    free(t);
}

static void test_malloc_one()
{
    char *t = (char *)malloc(1);
    if (!t) {
        printf("malloc(1) should return ptr\n");
        return;
    }
    t[0] = 0;
    free(t);
}

static void test_malloc_getpagesize()
{
    void *t = malloc(getpagesize());
    free(t);
}

static void test_malloc_limits()
{
    void	*t0	= malloc(TINY_BLOCK_SIZE);
    void	*t00	= malloc(TINY_BLOCK_SIZE);
    void	*t000	= malloc(TINY_BLOCK_SIZE);
    void	*t1	= malloc(SMALL_BLOCK_SIZE);
    void	*t2	= malloc(SMALL_BLOCK_SIZE + 1);

    // Should print mallocs in all categories (TINY, SMALL, LARGE)
    free(t0);

    t0 = malloc(TINY_BLOCK_SIZE - sizeof(t_block));
    // show_alloc_mem();
    free(t0);
    free(t00);
    free(t000);
    free(t1);
    free(t2);
}

static void test_malloc_free_size()
{
    void *t = malloc(SMALL_BLOCK_SIZE + 1);

    // heap should have 0 free_space
    // show_heap_list();

    free(t);
}

void run_test_malloc(void)
{
    test_malloc_null();
    test_malloc_one();
    test_malloc_getpagesize();
    test_malloc_limits();
    test_malloc_free_size();

    // show_alloc_mem();
    // show_heap_list();
}