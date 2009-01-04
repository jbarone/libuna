/*
 * Support functions
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

#include <common.h>
#include <notify.h>

#include "libuca_definitions.h"
#include "libuca_support.h"

const char libuca_error_strings[] = {
};

/* Returns the library version as a string
 */
const char *libuca_get_version(
             void )
{
	return( (const char *) LIBUCA_VERSION_STRING );
}

/* Returns the error code as a string
 */
const char *libuca_get_error_string(
             int error_code )
{
	return( (const char *) LIBUCA_VERSION_STRING );
}

/* Set the notify values
 */
void libuca_set_notify_values(
      FILE *stream,
      uint8_t verbose )
{
	notify_set_values(
	 stream,
	 verbose );
}

