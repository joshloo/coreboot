/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef MICROPY_INCLUDED_PY_MPERRNO_H
#define MICROPY_INCLUDED_PY_MPERRNO_H

#include "py/mpconfig.h"


// MP_Exxx errno's are defined directly as numeric values
// (Linux constants are used as a reference)

#define EPERM              (1) // Operation not permitted
#define ENOENT             (2) // No such file or directory
#define ESRCH              (3) // No such process
#define EINTR              (4) // Interrupted system call
#define EIO                (5) // I/O error
#define ENXIO              (6) // No such device or address
#define E2BIG              (7) // Argument list too long
#define ENOEXEC            (8) // Exec format error
#define EBADF              (9) // Bad file number
#define ECHILD            (10) // No child processes
#define EAGAIN            (11) // Try again
#define ENOMEM            (12) // Out of memory
#define EACCES            (13) // Permission denied
#define EFAULT            (14) // Bad address
#define ENOTBLK           (15) // Block device required
#define EBUSY             (16) // Device or resource busy
#define EEXIST            (17) // File exists
#define EXDEV             (18) // Cross-device link
#define ENODEV            (19) // No such device
#define ENOTDIR           (20) // Not a directory
#define EISDIR            (21) // Is a directory
#define EINVAL            (22) // Invalid argument
#define ENFILE            (23) // File table overflow
#define EMFILE            (24) // Too many open files
#define ENOTTY            (25) // Not a typewriter
#define ETXTBSY           (26) // Text file busy
#define EFBIG             (27) // File too large
#define ENOSPC            (28) // No space left on device
#define ESPIPE            (29) // Illegal seek
#define EROFS             (30) // Read-only file system
#define EMLINK            (31) // Too many links
#define EPIPE             (32) // Broken pipe
#define EDOM              (33) // Math argument out of domain of func
#define ERANGE            (34) // Math result not representable
#define EWOULDBLOCK  MP_EAGAIN // Operation would block
#define EOPNOTSUPP        (95) // Operation not supported on transport endpoint
#define EAFNOSUPPORT      (97) // Address family not supported by protocol
#define EADDRINUSE        (98) // Address already in use
#define ECONNABORTED     (103) // Software caused connection abort
#define ECONNRESET       (104) // Connection reset by peer
#define ENOBUFS          (105) // No buffer space available
#define EISCONN          (106) // Transport endpoint is already connected
#define ENOTCONN         (107) // Transport endpoint is not connected
#define ETIMEDOUT        (110) // Connection timed out
#define ECONNREFUSED     (111) // Connection refused
#define EHOSTUNREACH     (113) // No route to host
#define EALREADY         (114) // Operation already in progress
#define EINPROGRESS      (115) // Operation now in progress


// MP_Exxx errno's are defined in terms of system supplied ones

#include <errno.h>

#define MP_EPERM            EPERM
#define MP_ENOENT           ENOENT
#define MP_ESRCH            ESRCH
#define MP_EINTR            EINTR
#define MP_EIO              EIO
#define MP_ENXIO            ENXIO
#define MP_E2BIG            E2BIG
#define MP_ENOEXEC          ENOEXEC
#define MP_EBADF            EBADF
#define MP_ECHILD           ECHILD
#define MP_EAGAIN           EAGAIN
#define MP_ENOMEM           ENOMEM
#define MP_EACCES           EACCES
#define MP_EFAULT           EFAULT
#define MP_ENOTBLK          ENOTBLK
#define MP_EBUSY            EBUSY
#define MP_EEXIST           EEXIST
#define MP_EXDEV            EXDEV
#define MP_ENODEV           ENODEV
#define MP_ENOTDIR          ENOTDIR
#define MP_EISDIR           EISDIR
#define MP_EINVAL           EINVAL
#define MP_ENFILE           ENFILE
#define MP_EMFILE           EMFILE
#define MP_ENOTTY           ENOTTY
#define MP_ETXTBSY          ETXTBSY
#define MP_EFBIG            EFBIG
#define MP_ENOSPC           ENOSPC
#define MP_ESPIPE           ESPIPE
#define MP_EROFS            EROFS
#define MP_EMLINK           EMLINK
#define MP_EPIPE            EPIPE
#define MP_EDOM             EDOM
#define MP_ERANGE           ERANGE
#define MP_EWOULDBLOCK      EWOULDBLOCK
#define MP_EOPNOTSUPP       EOPNOTSUPP
#define MP_EAFNOSUPPORT     EAFNOSUPPORT
#define MP_EADDRINUSE       EADDRINUSE
#define MP_ECONNABORTED     ECONNABORTED
#define MP_ECONNRESET       ECONNRESET
#define MP_ENOBUFS          ENOBUFS
#define MP_EISCONN          EISCONN
#define MP_ENOTCONN         ENOTCONN
#define MP_ETIMEDOUT        ETIMEDOUT
#define MP_ECONNREFUSED     ECONNREFUSED
#define MP_EHOSTUNREACH     EHOSTUNREACH
#define MP_EALREADY         EALREADY
#define MP_EINPROGRESS      EINPROGRESS


#if MICROPY_PY_UERRNO

#include "py/obj.h"

qstr mp_errno_to_str(mp_obj_t errno_val);

#endif

#endif // MICROPY_INCLUDED_PY_MPERRNO_H
