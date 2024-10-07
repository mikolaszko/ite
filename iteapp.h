#pragma once

#include <gtk/gtk.h>

#define ITE_APP_TYPE (ite_app_get_type())
G_DECLARE_FINAL_TYPE(IteApp, ite_app, ITE, APP, GtkApplication)

IteApp *ite_app_new(void);
