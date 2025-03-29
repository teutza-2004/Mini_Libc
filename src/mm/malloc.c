// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
    void *mal = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mal == MAP_FAILED) {
        return NULL;
    }
	mem_list_add(mal, size);
    return mal;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *cal = malloc(nmemb * size);
	memset(cal, 0, nmemb * size);
	return cal;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (!ptr)
	    return;
	struct mem_list *x = mem_list_find(ptr);
	munmap(x->start, x->len);
	mem_list_del(x->start);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	return malloc(size);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
    return realloc(ptr, nmemb * size);
}
