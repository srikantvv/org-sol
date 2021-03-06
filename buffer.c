//    Organic Photovoltaic Device Model - a drift diffusion base/Shockley-Read-Hall
//    model for organic solar cells. 
//    Copyright (C) 2012 Roderick C. I. MacKenzie
//
//	roderick.mackenzie@nottingham.ac.uk
//	www.roderickmackenzie.eu
//	Room B86 Coates, University Park, Nottingham, NG7 2RD, UK
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "buffer.h"

void buffer_init(struct buffer *in)
{
	in->len = 0;
	in->max_len = 0;
	in->max_len += 1024;
	in->buf = (char *)malloc(sizeof(char) * in->max_len);
	memset(in->buf, 0, in->max_len);
}

void buffer_add_string(struct buffer *in, char *string)
{
	int str_len = strlen(string);
	int pos = in->len;
	in->len += str_len;

	if (in->len > in->max_len) {
		in->max_len += 1024;
		in->buf = (char *)realloc(in->buf, sizeof(char) * in->max_len);
	}

	strcpy(in->buf + pos, string);
}

void buffer_free(struct buffer *in)
{
	free(in->buf);
	in->len = 0;
	in->max_len = 0;
}
