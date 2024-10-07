#pragma once

#include "iteapp.h"
#include <gtk/gtk.h>

#define ITE_APP_WINDOW_TYPE (ite_app_window_get_type())
G_DECLARE_FINAL_TYPE(IteAppWindow, ite_app_window, ITE, APP_WINDOW,
                     GtkApplicationWindow)

IteAppWindow *ite_app_window_new(IteApp *app);
void ite_app_window_open(IteAppWindow *win, GFile *file);
