/* $Id$
 *
 * Buzztard
 * Copyright (C) 2010 Buzztard team <buzztard-devel@lists.sf.net>
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

#ifndef BT_CRASH_RECOVER_DIALOG_H
#define BT_CRASH_RECOVER_DIALOG_H

#include <glib.h>
#include <glib-object.h>

#define BT_TYPE_CRASH_RECOVER_DIALOG            (bt_crash_recover_dialog_get_type ())
#define BT_CRASH_RECOVER_DIALOG(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BT_TYPE_CRASH_RECOVER_DIALOG, BtCrashRecoverDialog))
#define BT_CRASH_RECOVER_DIALOG_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BT_TYPE_CRASH_RECOVER_DIALOG, BtCrashRecoverDialogClass))
#define BT_IS_CRASH_RECOVER_DIALOG(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BT_TYPE_CRASH_RECOVER_DIALOG))
#define BT_IS_CRASH_RECOVER_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BT_TYPE_CRASH_RECOVER_DIALOG))
#define BT_CRASH_RECOVER_DIALOG_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), BT_TYPE_CRASH_RECOVER_DIALOG, BtCrashRecoverDialogClass))

/* type macros */

typedef struct _BtCrashRecoverDialog BtCrashRecoverDialog;
typedef struct _BtCrashRecoverDialogClass BtCrashRecoverDialogClass;
typedef struct _BtCrashRecoverDialogPrivate BtCrashRecoverDialogPrivate;

/**
 * BtCrashRecoverDialog:
 *
 * the about dialog for the editor application
 */
struct _BtCrashRecoverDialog {
  GtkDialog parent;
  
  /*< private >*/
  BtCrashRecoverDialogPrivate *priv;
};

struct _BtCrashRecoverDialogClass {
  GtkDialogClass parent;
  
};

GType bt_crash_recover_dialog_get_type(void) G_GNUC_CONST;

#endif // BT_CRASH_RECOVER_DIALOG_H