#include <gtk/gtk.h>

#include "iteapp.h"
#include "iteappwin.h"

struct _IteAppWindow {
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE(IteAppWindow, ite_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void ite_app_window_init(IteAppWindow *win) {
  gtk_widget_init_template(GTK_WIDGET(win));
}

static void ite_app_window_class_init(IteAppWindowClass *class) {
  gtk_widget_class_set_template_from_resource(
      GTK_WIDGET_CLASS(class), "/com/github/mikolaszko/ite/ui/window.ui");
}

IteAppWindow *ite_app_window_new(IteApp *app) {
  return g_object_new(ITE_APP_WINDOW_TYPE, "application", app, NULL);
}

void ite_app_window_open(IteAppWindow *win, GFile *file) {}
