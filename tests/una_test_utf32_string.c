/*
 * Library utf32_string functions test program
 *
 * Copyright (C) 2008-2018, Joachim Metz <joachim.metz@gmail.com>
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

#include <common.h>
#include <file_stream.h>
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "una_test_libcerror.h"
#include "una_test_libuna.h"
#include "una_test_macros.h"
#include "una_test_unused.h"

uint8_t lnk_test_utf32_string_byte_stream[ 16 ] = {
	'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xe1, ' ', 't', 'e', 's', 't', '.', 0 };

uint8_t lnk_test_utf32_string_utf16_stream[ 32 ] = {
	'T', 0, 'h', 0, 'i', 0, 's', 0, ' ', 0, 'i', 0, 's', 0, ' ', 0, 0xe1, 0,
	' ', 0, 't', 0, 'e', 0, 's', 0, 't', 0, '.', 0, 0, 0 };

uint8_t lnk_test_utf32_string_utf32_stream[ 64 ] = {
	'T', 0, 0, 0, 'h', 0, 0, 0, 'i', 0, 0, 0, 's', 0, 0, 0, ' ', 0, 0, 0,
	'i', 0, 0, 0, 's', 0, 0, 0, ' ', 0, 0, 0, 0xe1, 0, 0, 0, ' ', 0, 0, 0,
	't', 0, 0, 0, 'e', 0, 0, 0, 's', 0, 0, 0, 't', 0, 0, 0, '.', 0, 0, 0, 0, 0, 0, 0 };

uint8_t lnk_test_utf32_string_utf7_stream[ 20 ] = {
	'T', 'h', 'i', 's', ' ', 'i', 's', ' ', '+', 'A', 'O', 'E', '-', ' ', 't', 'e', 's', 't', '.', 0 };

uint8_t lnk_test_utf32_string_utf8_stream[ 17 ] = {
	'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xc3, 0xa1, ' ', 't', 'e', 's', 't', '.', 0 };

uint16_t lnk_test_utf32_string_utf16_string[ 16 ] = {
	'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xe1, ' ', 't', 'e', 's', 't', '.', 0 };

uint32_t lnk_test_utf32_string_utf32_string[ 16 ] = {
	'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xe1, ' ', 't', 'e', 's', 't', '.', 0 };

uint8_t lnk_test_utf32_string_utf8_string[ 17 ] = {
	'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xc3, 0xa1, ' ', 't', 'e', 's', 't', '.', 0 };

/* Tests the libuna_utf32_string_size_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_size_from_byte_stream(
     void )
{
	libuna_error_t *error    = NULL;
	size_t utf16_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_size_from_byte_stream(
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &utf16_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_size",
	 utf16_string_size,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_utf32_string_size_from_byte_stream(
	          NULL,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &utf16_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_byte_stream(
	          lnk_test_utf32_string_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &utf16_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_byte_stream(
	          lnk_test_utf32_string_byte_stream,
	          16,
	          -1,
	          &utf16_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_byte_stream(
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          NULL,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_copy_from_byte_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error = NULL;
	int result            = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_copy_from_byte_stream(
	          utf32_string,
	          32,
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libuna_utf32_string_copy_from_byte_stream(
	          NULL,
	          32,
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_with_index_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_with_index_copy_from_byte_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error     = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_with_index_copy_from_byte_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libuna_utf32_string_with_index_copy_from_byte_stream(
	          NULL,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_byte_stream(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_byte_stream(
	          utf32_string,
	          32,
	          NULL,
	          lnk_test_utf32_string_byte_stream,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_byte_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          NULL,
	          16,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_byte_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_byte_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_byte_stream,
	          16,
	          -1,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_size_from_utf7_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_size_from_utf7_stream(
     void )
{
	libuna_error_t *error    = NULL;
	size_t utf32_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_size_from_utf7_stream(
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_utf32_string_size_from_utf7_stream(
	          NULL,
	          20,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf7_stream(
	          lnk_test_utf32_string_utf7_stream,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf7_stream(
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          NULL,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_copy_from_utf7_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_copy_from_utf7_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error = NULL;
	int result            = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_copy_from_utf7_stream(
	          utf32_string,
	          32,
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libuna_utf32_string_copy_from_utf7_stream(
	          NULL,
	          32,
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_with_index_copy_from_utf7_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_with_index_copy_from_utf7_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error     = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_with_index_copy_from_utf7_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libuna_utf32_string_with_index_copy_from_utf7_stream(
	          NULL,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf7_stream(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf7_stream(
	          utf32_string,
	          32,
	          NULL,
	          lnk_test_utf32_string_utf7_stream,
	          20,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf7_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          NULL,
	          20,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf7_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf7_stream,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_size_from_utf8 function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_size_from_utf8(
     void )
{
	libuna_error_t *error    = NULL;
	size_t utf32_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_size_from_utf8(
	          lnk_test_utf32_string_utf8_string,
	          17,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_utf32_string_size_from_utf8(
	          NULL,
	          17,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf8(
	          lnk_test_utf32_string_utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf8(
	          lnk_test_utf32_string_utf8_string,
	          17,
	          NULL,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_copy_from_utf8 function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_copy_from_utf8(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error = NULL;
	int result            = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_copy_from_utf8(
	          utf32_string,
	          32,
	          lnk_test_utf32_string_utf8_string,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libuna_utf32_string_copy_from_utf8(
	          NULL,
	          32,
	          lnk_test_utf32_string_utf8_string,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_with_index_copy_from_utf8 function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_with_index_copy_from_utf8(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error     = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_with_index_copy_from_utf8(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_string,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libuna_utf32_string_with_index_copy_from_utf8(
	          NULL,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_string,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_string,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8(
	          utf32_string,
	          32,
	          NULL,
	          lnk_test_utf32_string_utf8_string,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          NULL,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_size_from_utf8_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_size_from_utf8_stream(
     void )
{
	libuna_error_t *error    = NULL;
	size_t utf32_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_size_from_utf8_stream(
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_utf32_string_size_from_utf8_stream(
	          NULL,
	          17,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf8_stream(
	          lnk_test_utf32_string_utf8_stream,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf8_stream(
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          NULL,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_copy_from_utf8_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_copy_from_utf8_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error = NULL;
	int result            = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_copy_from_utf8_stream(
	          utf32_string,
	          32,
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libuna_utf32_string_copy_from_utf8_stream(
	          NULL,
	          32,
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_with_index_copy_from_utf8_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_with_index_copy_from_utf8_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error     = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_with_index_copy_from_utf8_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libuna_utf32_string_with_index_copy_from_utf8_stream(
	          NULL,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8_stream(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8_stream(
	          utf32_string,
	          32,
	          NULL,
	          lnk_test_utf32_string_utf8_stream,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          NULL,
	          17,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf8_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf8_stream,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_size_from_utf16 function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_size_from_utf16(
     void )
{
	libuna_error_t *error    = NULL;
	size_t utf32_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_size_from_utf16(
	          lnk_test_utf32_string_utf16_string,
	          16,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_utf32_string_size_from_utf16(
	          NULL,
	          16,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf16(
	          lnk_test_utf32_string_utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf16(
	          lnk_test_utf32_string_utf16_string,
	          16,
	          NULL,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_copy_from_utf16 function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_copy_from_utf16(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error = NULL;
	int result            = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_copy_from_utf16(
	          utf32_string,
	          32,
	          lnk_test_utf32_string_utf16_string,
	          16,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libuna_utf32_string_copy_from_utf16(
	          NULL,
	          32,
	          lnk_test_utf32_string_utf16_string,
	          16,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_with_index_copy_from_utf16 function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_with_index_copy_from_utf16(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error     = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_with_index_copy_from_utf16(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_string,
	          16,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libuna_utf32_string_with_index_copy_from_utf16(
	          NULL,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_string,
	          16,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_string,
	          16,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16(
	          utf32_string,
	          32,
	          NULL,
	          lnk_test_utf32_string_utf16_string,
	          16,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          NULL,
	          16,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_size_from_utf16_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_size_from_utf16_stream(
     void )
{
	libuna_error_t *error    = NULL;
	size_t utf32_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_size_from_utf16_stream(
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_utf32_string_size_from_utf16_stream(
	          NULL,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf16_stream(
	          lnk_test_utf32_string_utf16_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBUNA_ENDIAN_LITTLE,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf16_stream(
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          -1,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf16_stream(
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          NULL,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_copy_from_utf16_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_copy_from_utf16_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error = NULL;
	int result            = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_copy_from_utf16_stream(
	          utf32_string,
	          32,
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libuna_utf32_string_copy_from_utf16_stream(
	          NULL,
	          32,
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_with_index_copy_from_utf16_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_with_index_copy_from_utf16_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error     = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_with_index_copy_from_utf16_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libuna_utf32_string_with_index_copy_from_utf16_stream(
	          NULL,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16_stream(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16_stream(
	          utf32_string,
	          32,
	          NULL,
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          NULL,
	          32,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf16_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf16_stream,
	          32,
	          -1,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_size_from_utf32_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_size_from_utf32_stream(
     void )
{
	libuna_error_t *error    = NULL;
	size_t utf32_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_size_from_utf32_stream(
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_utf32_string_size_from_utf32_stream(
	          NULL,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf32_stream(
	          lnk_test_utf32_string_utf32_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBUNA_ENDIAN_LITTLE,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf32_stream(
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          -1,
	          &utf32_string_size,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_size_from_utf32_stream(
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          NULL,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_copy_from_utf32_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_copy_from_utf32_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error = NULL;
	int result            = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_copy_from_utf32_stream(
	          utf32_string,
	          32,
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libuna_utf32_string_copy_from_utf32_stream(
	          NULL,
	          32,
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libuna_utf32_string_with_index_copy_from_utf32_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_utf32_string_with_index_copy_from_utf32_stream(
     void )
{
	uint32_t utf32_string[ 32 ];

	libuna_error_t *error     = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libuna_utf32_string_with_index_copy_from_utf32_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 16 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          lnk_test_utf32_string_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 16 );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libuna_utf32_string_with_index_copy_from_utf32_stream(
	          NULL,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf32_stream(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf32_stream(
	          utf32_string,
	          32,
	          NULL,
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf32_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          NULL,
	          64,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf32_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf32_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBUNA_ENDIAN_LITTLE,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libuna_utf32_string_with_index_copy_from_utf32_stream(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          lnk_test_utf32_string_utf32_stream,
	          64,
	          -1,
	          &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	UNA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc UNA_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] UNA_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc UNA_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] UNA_TEST_ATTRIBUTE_UNUSED )
#endif
{
	UNA_TEST_UNREFERENCED_PARAMETER( argc )
	UNA_TEST_UNREFERENCED_PARAMETER( argv )

	UNA_TEST_RUN(
	 "libuna_utf32_string_size_from_byte_stream",
	 una_test_utf32_string_size_from_byte_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_copy_from_byte_stream",
	 una_test_utf32_string_copy_from_byte_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_with_index_copy_from_byte_stream",
	 una_test_utf32_string_with_index_copy_from_byte_stream );

	/* TODO libuna_utf32_string_compare_with_byte_stream */

	UNA_TEST_RUN(
	 "libuna_utf32_string_size_from_utf7_stream",
	 una_test_utf32_string_size_from_utf7_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_copy_from_utf7_stream",
	 una_test_utf32_string_copy_from_utf7_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_with_index_copy_from_utf7_stream",
	 una_test_utf32_string_with_index_copy_from_utf7_stream );

	/* TODO libuna_utf32_string_compare_with_utf7_stream */

	UNA_TEST_RUN(
	 "libuna_utf32_string_size_from_utf8",
	 una_test_utf32_string_size_from_utf8 );

	UNA_TEST_RUN(
	 "libuna_utf32_string_copy_from_utf8",
	 una_test_utf32_string_copy_from_utf8 );

	UNA_TEST_RUN(
	 "libuna_utf32_string_with_index_copy_from_utf8",
	 una_test_utf32_string_with_index_copy_from_utf8 );

	/* TODO libuna_utf32_string_compare_with_utf8 */

	UNA_TEST_RUN(
	 "libuna_utf32_string_size_from_utf8_stream",
	 una_test_utf32_string_size_from_utf8_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_copy_from_utf8_stream",
	 una_test_utf32_string_copy_from_utf8_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_with_index_copy_from_utf8_stream",
	 una_test_utf32_string_with_index_copy_from_utf8_stream );

	/* TODO libuna_utf32_string_compare_with_utf8_stream */

	UNA_TEST_RUN(
	 "libuna_utf32_string_size_from_utf16",
	 una_test_utf32_string_size_from_utf16 );

	UNA_TEST_RUN(
	 "libuna_utf32_string_copy_from_utf16",
	 una_test_utf32_string_copy_from_utf16 );

	UNA_TEST_RUN(
	 "libuna_utf32_string_with_index_copy_from_utf16",
	 una_test_utf32_string_with_index_copy_from_utf16 );

	/* TODO libuna_utf32_string_compare_with_utf16 */

	UNA_TEST_RUN(
	 "libuna_utf32_string_size_from_utf16_stream",
	 una_test_utf32_string_size_from_utf16_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_copy_from_utf16_stream",
	 una_test_utf32_string_copy_from_utf16_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_with_index_copy_from_utf16_stream",
	 una_test_utf32_string_with_index_copy_from_utf16_stream );

	/* TODO libuna_utf32_string_compare_with_utf16_stream */

	UNA_TEST_RUN(
	 "libuna_utf32_string_size_from_utf32_stream",
	 una_test_utf32_string_size_from_utf32_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_copy_from_utf32_stream",
	 una_test_utf32_string_copy_from_utf32_stream );

	UNA_TEST_RUN(
	 "libuna_utf32_string_with_index_copy_from_utf32_stream",
	 una_test_utf32_string_with_index_copy_from_utf32_stream );

	/* TODO libuna_utf32_string_compare_with_utf32_stream */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

