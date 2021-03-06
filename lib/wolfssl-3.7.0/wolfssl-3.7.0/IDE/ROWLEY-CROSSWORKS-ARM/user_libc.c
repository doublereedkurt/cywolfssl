/* user_libc.c
 *
 * Copyright (C) 2006-2015 wolfSSL Inc.
 *
 * This file is part of wolfSSL. (formerly known as CyaSSL)
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#include "hw.h"

double current_time(int reset)
{
    double time;
    time = hw_get_time_sec();
    time += (double)hw_get_time_msec() / 1000;
    return time;
}

int custom_rand_generate(void)
{
    return hw_rand();
}

// Debug print handler
int __putchar(int c, __printf_tag_ptr ctx)
{
    hw_uart_printchar(c);
}


// Rowley CrossWorks, runtime support.
//
//  Copyright (c) 2001-2015 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <__libc.h>

#if defined(__CROSSWORKS_ARM) || defined(__SES_ARM)

extern unsigned char __stack_process_start__[];

unsigned char * __aeabi_read_tp(void)
{
    // thread-local storage addressing refers to the thread pointer
    // This is returning start address of stack process
    return (__stack_process_start__);
}

#elif defined(__CROSSWORKS_AVR) || defined(__CROSSWORKS_MSP430)

unsigned char * __RAL_read_tp(void)
{
  return 0;
}

#endif

void __heap_lock(void)
{
}

void __heap_unlock(void)
{
}

void __printf_lock(void)
{
}

void __printf_unlock(void)
{
}

void __scanf_lock(void)
{
}

void __scanf_unlock(void)
{
}

void __debug_io_lock(void)
{
}

void __debug_io_unlock(void)
{
}
