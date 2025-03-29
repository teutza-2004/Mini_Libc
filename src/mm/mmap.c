// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	void *mm = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (fd > 10) {
		errno = EBADF;
		return MAP_FAILED;
	} else if (fd == -1 && (flags & (MAP_PRIVATE | MAP_SHARED)) == 0) {
		errno = EINVAL;
		return MAP_FAILED;
	}
	return mm;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *mrm = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);
	return mrm;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int mum = syscall(__NR_munmap, addr, length);
	return mum;
}
