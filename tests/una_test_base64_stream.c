/*
 * Library base64 stream functions test program
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

#if defined( __GNUC__ ) && !defined( LIBUNA_DLL_IMPORT )

int libuna_base64_character_copy_to_sixtet(
     uint8_t base64_character,
     uint8_t *base64_sixtet,
     uint32_t base64_variant,
     libcerror_error_t **error );

#endif /* defined( __GNUC__ ) && !defined( LIBUNA_DLL_IMPORT ) */

uint8_t una_test_base64_stream_rfc1421_byte_stream[ 25 ] = {
	'V', 'G', 'h', 'p', 'c', 'y', 'B', 'p', 'c', 'y', 'D', 'D', 'o', 'S', 'B', '0', 'Z', 'X', 'N', '0',
        'L', 'g', '=', '=', '\n' };

uint8_t una_test_base64_stream_rfc1642_byte_stream[ 22 ] = {
	'V', 'G', 'h', 'p', 'c', 'y', 'B', 'p', 'c', 'y', 'D', 'D', 'o', 'S', 'B', '0', 'Z', 'X', 'N', '0',
        'L', 'g' };

uint8_t una_test_base64_stream_rfc1421_utf16be_stream[ 50 ] = {
	0, 'V', 0, 'G', 0, 'h', 0, 'p', 0, 'c', 0, 'y', 0, 'B', 0, 'p', 0, 'c', 0, 'y', 0, 'D', 0, 'D',
        0, 'o', 0, 'S', 0, 'B', 0, '0', 0, 'Z', 0, 'X', 0, 'N', 0, '0', 0, 'L', 0, 'g', 0, '=', 0, '=',
        0, '\n' };

uint8_t una_test_base64_stream_rfc1421_utf32le_stream[ 100 ] = {
	'V', 0, 0, 0, 'G', 0, 0, 0, 'h', 0, 0, 0, 'p', 0, 0, 0, 'c', 0, 0, 0, 'y', 0, 0, 0, 'B', 0, 0, 0,
        'p', 0, 0, 0, 'c', 0, 0, 0, 'y', 0, 0, 0, 'D', 0, 0, 0, 'D', 0, 0, 0, 'o', 0, 0, 0, 'S', 0, 0, 0,
        'B', 0, 0, 0, '0', 0, 0, 0, 'Z', 0, 0, 0, 'X', 0, 0, 0, 'N', 0, 0, 0, '0', 0, 0, 0, 'L', 0, 0, 0,
        'g', 0, 0, 0, '=', 0, 0, 0, '=', 0, 0, 0, '\n', 0, 0, 0 };

#if defined( __GNUC__ ) && !defined( LIBUNA_DLL_IMPORT )

/* Tests the libuna_base64_character_copy_to_sixtet function
 * Returns 1 if successful or 0 if not
 */
int una_test_base64_character_copy_to_sixtet(
     void )
{
	uint8_t base64_sixtet[ 8 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) '+',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) '-',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_URL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 'A',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 'J',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 'S',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 'a',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 'j',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 's',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) '0',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) '#',
		  base64_sixtet,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
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

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 'A',
		  NULL,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL,
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

	result = libuna_base64_character_copy_to_sixtet(
	          (uint8_t) 'A',
		  base64_sixtet,
	          0x000f0000UL,
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

#endif /* defined( __GNUC__ ) && !defined( LIBUNA_DLL_IMPORT ) */

/* Tests the libuna_base64_stream_size_to_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int una_test_base64_stream_size_to_byte_stream(
     void )
{
	libcerror_error_t *error = NULL;
	size_t byte_stream_size  = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libuna_base64_stream_size_to_byte_stream(
	          una_test_base64_stream_rfc1421_byte_stream,
	          25,
		  &byte_stream_size,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL | LIBUNA_BASE64_VARIANT_CHARACTER_LIMIT_64 | LIBUNA_BASE64_VARIANT_PADDING_REQUIRED,
	          0,
		  &error );

	UNA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	UNA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	UNA_TEST_ASSERT_EQUAL_SIZE(
	 "byte_stream_size",
	 byte_stream_size,
	 (size_t) 16 );

	/* Test error cases
	 */
	result = libuna_base64_stream_size_to_byte_stream(
	          NULL,
		  25,
		  &byte_stream_size,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL | LIBUNA_BASE64_VARIANT_CHARACTER_LIMIT_64 | LIBUNA_BASE64_VARIANT_PADDING_REQUIRED,
	          0,
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

	result = libuna_base64_stream_size_to_byte_stream(
	          una_test_base64_stream_rfc1421_byte_stream,
		  (size_t) SSIZE_MAX + 1,
		  &byte_stream_size,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL | LIBUNA_BASE64_VARIANT_CHARACTER_LIMIT_64 | LIBUNA_BASE64_VARIANT_PADDING_REQUIRED,
	          0,
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

	result = libuna_base64_stream_size_to_byte_stream(
	          una_test_base64_stream_rfc1421_byte_stream,
		  25,
	          NULL,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL | LIBUNA_BASE64_VARIANT_CHARACTER_LIMIT_64 | LIBUNA_BASE64_VARIANT_PADDING_REQUIRED,
	          0,
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

	/* Invalid character limit
	 */
	result = libuna_base64_stream_size_to_byte_stream(
	          una_test_base64_stream_rfc1421_byte_stream,
		  25,
		  &byte_stream_size,
	          0x000000ffUL,
	          0,
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

	/* Invalid alphabet
	 */
	result = libuna_base64_stream_size_to_byte_stream(
	          una_test_base64_stream_rfc1421_byte_stream,
	          25,
		  &byte_stream_size,
	          0x000f0000UL | LIBUNA_BASE64_VARIANT_CHARACTER_LIMIT_64,
	          0,
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

	/* Invalid encoding
	 */
	result = libuna_base64_stream_size_to_byte_stream(
	          una_test_base64_stream_rfc1421_utf16be_stream,
	          40,
		  &byte_stream_size,
	          0xf0000000UL | LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL | LIBUNA_BASE64_VARIANT_CHARACTER_LIMIT_64,
	          0,
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

	/* Invalid flags
	 */
	result = libuna_base64_stream_size_to_byte_stream(
	          una_test_base64_stream_rfc1421_byte_stream,
	          25,
		  &byte_stream_size,
	          LIBUNA_BASE64_VARIANT_ALPHABET_NORMAL | LIBUNA_BASE64_VARIANT_CHARACTER_LIMIT_64 | LIBUNA_BASE64_VARIANT_PADDING_REQUIRED,
	          0xff,
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

#if defined( __GNUC__ ) && !defined( LIBUNA_DLL_IMPORT )

	UNA_TEST_RUN(
	 "libuna_base64_character_copy_to_sixtet",
	 una_test_base64_character_copy_to_sixtet );

#endif /* defined( __GNUC__ ) && !defined( LIBUNA_DLL_IMPORT ) */

	/* TODO add tests for libuna_base64_triplet_copy_from_base64_stream */
	/* TODO add tests for libuna_base64_triplet_copy_to_base64_stream */
	/* TODO add tests for libuna_base64_triplet_copy_from_byte_stream */
	/* TODO add tests for libuna_base64_triplet_copy_to_byte_stream */

	UNA_TEST_RUN(
	 "libuna_base64_stream_size_to_byte_stream",
	 una_test_base64_stream_size_to_byte_stream );

	/* TODO add tests for libuna_base64_stream_copy_to_byte_stream */
	/* TODO add tests for libuna_base64_stream_size_from_byte_stream */
	/* TODO add tests for libuna_base64_stream_copy_from_byte_stream */
	/* TODO add tests for libuna_base64_stream_with_index_copy_from_byte_stream */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
