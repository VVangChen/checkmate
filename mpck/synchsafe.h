/*
 *   This file is part of mpck, a program to check MP3 files for errors
 *   
 *   Copyright (C)  2006  Sjoerd Langkemper
 *   
 *   mpck is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *   
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *****************************************************************************
 *
 *   synchsafe.h - functions for converting synchsafe integers
 *
 *   Synchsafe integers are integers that keep its highest bit (bit 7) zeroed, 
 *   making seven bits out of eight available. Thus a 32 bit synchsafe integer 
 *   can store 28 bits of information.
 *
 *   Example:
 *   255 (%11111111) encoded as a 16 bit synchsafe integer is 383
 *   (%00000001 01111111).
 * 
 * This is used in ID3 v2 tags, so that MP3 players do not see it as a
 * MP3 frame.
 *
 */

#define UCP(ptr)      (unsigned char *)(ptr)
#define INT_SS(buf)   (SHORT_SS(UCP(buf)) << 14 | SHORT_SS(UCP(buf) + 2))
#define SHORT_SS(buf) (CHAR_SS(UCP(buf)) << 7 | CHAR_SS(UCP(buf) + 1))
#define CHAR_SS(buf)  (*UCP(buf))
