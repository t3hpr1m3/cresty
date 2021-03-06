/*======================================================================*
 *                                                                      *
 *  Copyright (C) 2016 Josh Williams (vmizzle@gmail.com)                *
 *                                                                      *
 * Permission is hereby granted, free of charge, to any person          *
 * obtaining a copy of this software and associated documentation files *
 * (the "Software"), to deal in the Software without restriction,       *
 * including without limitation the rights to use, copy, modify, merge, *
 * publish, distribute, sublicense, and/or sell copies of the Software, *
 * and to permit persons to whom the Software is furnished to do so,    *
 * subject to the following conditions:                                 *
 *                                                                      *
 * The above copyright notice and this permission notice shall be       *
 * included in all copies or substantial portions of the Software.      *
 *                                                                      *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                *
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  *
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   *
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    *
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     *
 * SOFTWARE.                                                            *
 *                                                                      *
 *======================================================================*/
#ifndef __SOCKET_H_INCLUDED__
#define __SOCKET_H_INCLUDED__

#include "cresty.h"

typedef enum {
	CRESTY_SOCKET_UNINITIALIZED,
	CRESTY_SOCKET_INITIALIZED,
	CRESTY_SOCKET_BOUND,
	CRESTY_SOCKET_LISTENING,
	CRESTY_SOCKET_CONNECTED
} cresty_socket_status;

struct cresty_socket {
	int fd;
	cresty_socket_status status;
};

struct cresty_socket*   cresty_socket_create();
cresty_result           cresty_socket_init(struct cresty_socket *s);
void                    cresty_socket_destroy(struct cresty_socket *s);
cresty_result           cresty_socket_bind(struct cresty_socket *s,
                            const char *address, int port);
cresty_result           cresty_socket_listen(struct cresty_socket *s,
                            int backlog);
void                    cresty_socket_shutdown(struct cresty_socket *s);

#endif /* __SOCKET_H_INCLUDED__ */

/* vi: set ts=4: */
