/* Copyright (c) 2011 by Markus Duft <mduft@gentoo.org>
 * This file is part of the 'tachyon' operating system. */

#pragma once

#include "thread.h"
#include "syscall.h"

/**
 * Describs the user-space mapped kernel APIs,
 * and where they are to be found
 */
typedef struct _tag_uapi_desc_t {
    uintptr_t (*syscall)(syscall_t, uintptr_t, uintptr_t);
} uapi_desc_t;

/**
 * Delegates a system call from the userspace to the
 * kernel. How this is done depends on the impl.
 *
 * @param call      the system call to execute.
 * @param param0    first param (depends on call)
 * @param param1    second param (depends on call)
 * @return          depends on call
 */
uintptr_t uapi_sysc_call(syscall_t call, uintptr_t param0, uintptr_t param1);

/**
 * Thread startup trampoline, mapped to user space.
 * Must clean up the thread after it returns.
 *
 * This is also used for kernel mode threads!
 *
 * @param thread the thread that is starting.
 * @param entry  the threads entry point to call.
 */
void uapi_thr_trampoline(thread_t* thread, thread_start_t entry);

/**
 * Maps the UAPI into the specified address space.
 *
 * @param space the address space to modify
 */
bool uapi_map(spc_t space);