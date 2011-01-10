/* Copyright (c) 2010 by Markus Duft <mduft@gentoo.org>
 * This file is part of the 'tachyon' operating system. */

#pragma once

#include "tachyon.h"

/**
 * Initializes the physical memory management. This
 * initializes manegement structures for at least 4MB of
 * physical RAM. More can be added later, @see pmem_add.
 */
void pmem_init();

/**
 * Adds a new region of physical ram to the allocator.
 * The region must be contigous. If the regions extents
 * cross those of existing regions, it is shortened to
 * fit in the free area.
 *
 * @param start     the beginning physical address.
 * @param length    the length of the region in bytes.
 */
void pmem_add(phys_addr_t start, size_t length);

/**
 * Allocates a contigous chunk of physical memory with
 * the given length and alignment. The minimum alignment
 * is currently 4096 bytes.
 * This should probably only be used in conjunktion with
 * the virtual memory management facilities.
 *
 * @param length    the number of bytes to allocate.
 * @param align     the minimum alignment of the block.
 * @return          the address of the allocated block if
 *                  successfull, 0 (zero) otherwise.
 */
phys_addr_t pmem_alloc(size_t length, off_t align);

/**
 * Frees a previously allocated block of physical memory.
 * Since the physical memory management does not track
 * allocations, the length needs to match the length given
 * to pmem_alloc!
 *
 * @param addr      the address of the block to free.
 * @param length    the length of the block.
 */
void pmem_free(phys_addr_t addr, size_t length);