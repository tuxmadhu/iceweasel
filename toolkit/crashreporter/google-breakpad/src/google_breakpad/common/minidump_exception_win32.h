/* Copyright (c) 2006, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

/* minidump_exception_win32.h: Definitions of exception codes for
 * Win32 platform
 *
 * (This is C99 source, please don't corrupt it with C++.)
 *
 * Author: Mark Mentovai
 * Split into its own file: Neal Sidhwaney */
 

#ifndef GOOGLE_BREAKPAD_COMMON_MINIDUMP_EXCEPTION_WIN32_H__
#define GOOGLE_BREAKPAD_COMMON_MINIDUMP_EXCEPTION_WIN32_H__

#include <stddef.h>

#include "google_breakpad/common/breakpad_types.h"


/* For (MDException).exception_code.  These values come from WinBase.h
 * and WinNT.h (names beginning with EXCEPTION_ are in WinBase.h,
 * they are STATUS_ in WinNT.h). */
typedef enum {
  MD_EXCEPTION_CODE_WIN_CONTROL_C                = 0x40010005,
      /* DBG_CONTROL_C */
  MD_EXCEPTION_CODE_WIN_GUARD_PAGE_VIOLATION     = 0x80000001,
      /* EXCEPTION_GUARD_PAGE */
  MD_EXCEPTION_CODE_WIN_DATATYPE_MISALIGNMENT    = 0x80000002,
      /* EXCEPTION_DATATYPE_MISALIGNMENT */
  MD_EXCEPTION_CODE_WIN_BREAKPOINT               = 0x80000003,
      /* EXCEPTION_BREAKPOINT */
  MD_EXCEPTION_CODE_WIN_SINGLE_STEP              = 0x80000004,
      /* EXCEPTION_SINGLE_STEP */
  MD_EXCEPTION_CODE_WIN_ACCESS_VIOLATION         = 0xc0000005,
      /* EXCEPTION_ACCESS_VIOLATION */
  MD_EXCEPTION_CODE_WIN_IN_PAGE_ERROR            = 0xc0000006,
      /* EXCEPTION_IN_PAGE_ERROR */
  MD_EXCEPTION_CODE_WIN_INVALID_HANDLE           = 0xc0000008,
      /* EXCEPTION_INVALID_HANDLE */
  MD_EXCEPTION_CODE_WIN_ILLEGAL_INSTRUCTION      = 0xc000001d,
      /* EXCEPTION_ILLEGAL_INSTRUCTION */
  MD_EXCEPTION_CODE_WIN_NONCONTINUABLE_EXCEPTION = 0xc0000025,
      /* EXCEPTION_NONCONTINUABLE_EXCEPTION */
  MD_EXCEPTION_CODE_WIN_INVALID_DISPOSITION      = 0xc0000026,
      /* EXCEPTION_INVALID_DISPOSITION */
  MD_EXCEPTION_CODE_WIN_ARRAY_BOUNDS_EXCEEDED    = 0xc000008c,
      /* EXCEPTION_BOUNDS_EXCEEDED */
  MD_EXCEPTION_CODE_WIN_FLOAT_DENORMAL_OPERAND   = 0xc000008d,
      /* EXCEPTION_FLT_DENORMAL_OPERAND */
  MD_EXCEPTION_CODE_WIN_FLOAT_DIVIDE_BY_ZERO     = 0xc000008e,
      /* EXCEPTION_FLT_DIVIDE_BY_ZERO */
  MD_EXCEPTION_CODE_WIN_FLOAT_INEXACT_RESULT     = 0xc000008f,
      /* EXCEPTION_FLT_INEXACT_RESULT */
  MD_EXCEPTION_CODE_WIN_FLOAT_INVALID_OPERATION  = 0xc0000090,
      /* EXCEPTION_FLT_INVALID_OPERATION */
  MD_EXCEPTION_CODE_WIN_FLOAT_OVERFLOW           = 0xc0000091,
      /* EXCEPTION_FLT_OVERFLOW */
  MD_EXCEPTION_CODE_WIN_FLOAT_STACK_CHECK        = 0xc0000092,
      /* EXCEPTION_FLT_STACK_CHECK */
  MD_EXCEPTION_CODE_WIN_FLOAT_UNDERFLOW          = 0xc0000093,
      /* EXCEPTION_FLT_UNDERFLOW */
  MD_EXCEPTION_CODE_WIN_INTEGER_DIVIDE_BY_ZERO   = 0xc0000094,
      /* EXCEPTION_INT_DIVIDE_BY_ZERO */
  MD_EXCEPTION_CODE_WIN_INTEGER_OVERFLOW         = 0xc0000095,
      /* EXCEPTION_INT_OVERFLOW */
  MD_EXCEPTION_CODE_WIN_PRIVILEGED_INSTRUCTION   = 0xc0000096,
      /* EXCEPTION_PRIV_INSTRUCTION */
  MD_EXCEPTION_CODE_WIN_STACK_OVERFLOW           = 0xc00000fd,
      /* EXCEPTION_STACK_OVERFLOW */
  MD_EXCEPTION_CODE_WIN_POSSIBLE_DEADLOCK        = 0xc0000194
      /* EXCEPTION_POSSIBLE_DEADLOCK */
} MDExceptionCodeWin;


#endif  /* GOOGLE_BREAKPAD_COMMON_MINIDUMP_EXCEPTION_WIN32_H__ */
