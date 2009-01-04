/*
 * UTF-32 stream functions
 *
 * Copyright (c) 2008, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBUNA_UTF32_STREAM_H )
#define _LIBUNA_UTF32_STREAM_H

#include <common.h>
#include <types.h>

#include "libuna_extern.h"
#include "libuna_inline.h"

#if defined( __cplusplus )
extern "C" {
#endif

LIBUNA_EXTERN LIBUNA_INLINE int libuna_utf32_stream_copy_byte_order_mark(
                                 uint8_t *utf32_stream,
                                 size_t utf32_stream_size,
                                 size_t *utf32_stream_index,
                                 uint8_t byte_order );

LIBUNA_EXTERN ssize_t libuna_utf32_stream_size_from_utf8(
                       libuna_utf8_character_t *utf8_string,
                       size_t utf8_string_size );

LIBUNA_EXTERN int libuna_utf32_stream_copy_from_utf8(
                   uint8_t *utf32_stream,
                   size_t utf32_stream_size,
                   uint8_t byte_order,
                   libuna_utf8_character_t *utf8_string,
                   size_t utf8_string_size );

/* The functionality for libuna_utf32_stream_copy_to_utf8 is implemented by
 * libuna_utf8_string_copy_from_utf32_stream
 */

LIBUNA_EXTERN ssize_t libuna_utf32_stream_size_from_utf16(
                       libuna_utf16_character_t *utf16_string,
                       size_t utf16_string_size );

LIBUNA_EXTERN int libuna_utf32_stream_copy_from_utf16(
                   uint8_t *utf32_stream,
                   size_t utf32_stream_size,
                   uint8_t byte_order,
                   libuna_utf16_character_t *utf16_string,
                   size_t utf16_string_size );

/* The functionality for libuna_utf32_stream_copy_to_utf16 is implemented by
 * libuna_utf16_string_copy_from_utf32_stream
 */

LIBUNA_EXTERN ssize_t libuna_utf32_stream_size_from_utf32(
                       libuna_utf32_character_t *utf32_string,
                       size_t utf32_string_size );

LIBUNA_EXTERN int libuna_utf32_stream_copy_from_utf32(
                   uint8_t *utf32_stream,
                   size_t utf32_stream_size,
                   uint8_t byte_order,
                   libuna_utf32_character_t *utf32_string,
                   size_t utf32_string_size );

/* The functionality for libuna_utf32_stream_copy_to_utf32 is implemented by
 * libuna_utf32_string_copy_from_utf32_stream
 */

#if defined( __cplusplus )
}
#endif

#endif
