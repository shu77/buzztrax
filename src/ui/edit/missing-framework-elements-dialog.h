/* $Id: missing-framework-elements-dialog.h,v 1.1 2007-04-01 16:18:22 ensonic Exp $
 *
 * Buzztard
 * Copyright (C) 2007 Buzztard team <buzztard-devel@lists.sf.net>
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

#ifndef BT_MISSING_FRAMEWORK_ELEMENTS_DIALOG_H
#define BT_MISSING_FRAMEWORK_ELEMENTS_DIALOG_H

#include <glib.h>
#include <glib-object.h>

#define BT_TYPE_MISSING_FRAMEWORK_ELEMENTS_DIALOG            (bt_missing_framework_elements_dialog_get_type ())
#define BT_MISSING_FRAMEWORK_ELEMENTS_DIALOG(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BT_TYPE_MISSING_FRAMEWORK_ELEMENTS_DIALOG, BtMissingFrameworkElementsDialog))
#define BT_MISSING_FRAMEWORK_ELEMENTS_DIALOG_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BT_TYPE_MISSING_FRAMEWORK_ELEMENTS_DIALOG, BtMissingFrameworkElementsDialogClass))
#define BT_IS_MISSING_FRAMEWORK_ELEMENTS_DIALOG(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BT_TYPE_MISSING_FRAMEWORK_ELEMENTS_DIALOG))
#define BT_IS_MISSING_FRAMEWORK_ELEMENTS_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BT_TYPE_MISSING_FRAMEWORK_ELEMENTS_DIALOG))
#define BT_MISSING_FRAMEWORK_ELEMENTS_DIALOG_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), BT_TYPE_MISSING_FRAMEWORK_ELEMENTS_DIALOG, BtMissingFrameworkElementsDialogClass))

/* type macros */

typedef struct _BtMissingFrameworkElementsDialog BtMissingFrameworkElementsDialog;
typedef struct _BtMissingFrameworkElementsDialogClass BtMissingFrameworkElementsDialogClass;
typedef struct _BtMissingFrameworkElementsDialogPrivate BtMissingFrameworkElementsDialogPrivate;

/**
 * BtMissingFrameworkElementsDialog:
 *
 * the root window for the editor application
 */
struct _BtMissingFrameworkElementsDialog {
  GtkDialog parent;

  /*< private >*/
  BtMissingFrameworkElementsDialogPrivate *priv;
};
/* structure of the machine-preset-properties-dialog class */
struct _BtMissingFrameworkElementsDialogClass {
  GtkDialogClass parent;

};

/* used by MISSING_FRAMEWORK_ELEMENTS_DIALOG_TYPE */
GType bt_missing_framework_elements_dialog_get_type(void) G_GNUC_CONST;

#endif // BT_MISSING_FRAMEWORK_ELEMENTS_DIALOG_H
