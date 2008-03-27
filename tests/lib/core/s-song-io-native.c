/* $Id: s-song-io-native.c,v 1.2 2006-08-24 20:00:55 ensonic Exp $
 *
 * Buzztard
 * Copyright (C) 2006 Buzztard team <buzztard-devel@lists.sf.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "m-bt-core.h"

extern TCase *bt_song_io_native_test_case(void);
extern TCase *bt_song_io_native_example_case(void);

Suite *bt_song_io_native_suite(void) { 
  Suite *s=suite_create("BtSongIONative"); 

  suite_add_tcase(s,bt_song_io_native_test_case());
  suite_add_tcase(s,bt_song_io_native_example_case());
  return(s);
}
