// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int ftr = syscall(__NR_ftruncate, fd, length);
	if (ftr == 0)
		return ftr;
	errno = -ftr;
	return -1;
}
