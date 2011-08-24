/* $Id$
 *
 * Buzztard
 * Copyright (C) 2011 Buzztard team <buzztard-devel@lists.sf.net>
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
/**
 * SECTION:btsettingspageshortcuts
 * @short_description: keyboard shortcut settings page
 *
 * Edit and manage keyboard shortcut schemes.
 */
/* @todo: we need a shortcut scheme management (buzz,fasttracker,..)
 * - select current scheme
 * - save edited scheme under new/current name
 * - check the midi-profiles in lib/ic/learn.c for the gkeyfile handling
 */
/* @todo: we need a way to edit the current scheme
 * - we can look at the shortcut editor code from the gnome-control-center
 *   http://git.gnome.org/browse/gnome-control-center/tree/capplets/keybindings?h=gnome-2-32
 * - we need to ensure that keys are unique and not otherwise bound
 */

#define BT_EDIT
#define BT_SETTINGS_PAGE_SHORTCUTS_C

#include "bt-edit.h"

struct _BtSettingsPageShortcutsPrivate {
  /* used to validate if dispose has run */
  gboolean dispose_has_run;

  /* the application */
  BtEditApplication *app;
};

//-- the class

G_DEFINE_TYPE (BtSettingsPageShortcuts, bt_settings_page_shortcuts, GTK_TYPE_TABLE);



//-- event handler

//-- helper methods

static void bt_settings_page_shortcuts_init_ui(const BtSettingsPageShortcuts *self) {
  BtSettings *settings;
  GtkWidget *label,*spacer;
  gchar *str;

  gtk_widget_set_name(GTK_WIDGET(self),"keyboard shortcut settings");

  // get settings
  g_object_get(self->priv->app,"settings",&settings,NULL);
  //g_object_get(settings,NULL);

  // add setting widgets
  spacer=gtk_label_new("    ");
  label=gtk_label_new(NULL);
  str=g_strdup_printf("<big><b>%s</b></big>",_("Shortcuts"));
  gtk_label_set_markup(GTK_LABEL(label),str);
  g_free(str);
  gtk_misc_set_alignment(GTK_MISC(label),0.0,0.5);
  gtk_table_attach(GTK_TABLE(self),label, 0, 3, 0, 1,  GTK_FILL|GTK_EXPAND, GTK_SHRINK, 2,1);
  gtk_table_attach(GTK_TABLE(self),spacer, 0, 1, 1, 4, GTK_SHRINK,GTK_SHRINK, 2,1);

  /* FIXME: */
  label=gtk_label_new("no keyboard settings yet");
  gtk_misc_set_alignment(GTK_MISC(label),0.5,0.5);
  gtk_table_attach(GTK_TABLE(self),label, 1, 3, 1, 4, GTK_FILL,GTK_FILL, 2,1);

  g_object_unref(settings);
}

//-- constructor methods

/**
 * bt_settings_page_shortcuts_new:
 *
 * Create a new instance
 *
 * Returns: the new instance
 */
BtSettingsPageShortcuts *bt_settings_page_shortcuts_new(void) {
  BtSettingsPageShortcuts *self;

  self=BT_SETTINGS_PAGE_SHORTCUTS(g_object_new(BT_TYPE_SETTINGS_PAGE_SHORTCUTS,
    "n-rows",4,
    "n-columns",3,
    "homogeneous",FALSE,
    NULL));
  bt_settings_page_shortcuts_init_ui(self);
  gtk_widget_show_all(GTK_WIDGET(self));
  return(self);
}

//-- methods

//-- wrapper

//-- class internals

static void bt_settings_page_shortcuts_dispose(GObject *object) {
  BtSettingsPageShortcuts *self = BT_SETTINGS_PAGE_SHORTCUTS(object);
  return_if_disposed();
  self->priv->dispose_has_run = TRUE;

  GST_DEBUG("!!!! self=%p",self);
  g_object_unref(self->priv->app);

  G_OBJECT_CLASS(bt_settings_page_shortcuts_parent_class)->dispose(object);
}

static void bt_settings_page_shortcuts_finalize(GObject *object) {
  BtSettingsPageShortcuts *self = BT_SETTINGS_PAGE_SHORTCUTS(object);

  GST_DEBUG("!!!! self=%p",self);

  G_OBJECT_CLASS(bt_settings_page_shortcuts_parent_class)->finalize(object);
}

static void bt_settings_page_shortcuts_init(BtSettingsPageShortcuts *self) {
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE(self, BT_TYPE_SETTINGS_PAGE_SHORTCUTS, BtSettingsPageShortcutsPrivate);
  GST_DEBUG("!!!! self=%p",self);
  self->priv->app = bt_edit_application_new();
}

static void bt_settings_page_shortcuts_class_init(BtSettingsPageShortcutsClass *klass) {
  GObjectClass *gobject_class = G_OBJECT_CLASS(klass);

  g_type_class_add_private(klass,sizeof(BtSettingsPageShortcutsPrivate));

  gobject_class->dispose      = bt_settings_page_shortcuts_dispose;
  gobject_class->finalize     = bt_settings_page_shortcuts_finalize;
}
