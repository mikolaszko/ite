#include <gtk/gtk.h>

#include "iteapp.h"
#include "iteappwin.h"

struct _IteApp {
  GtkApplication parent;
};

G_DEFINE_TYPE(IteApp, ite_app, GTK_TYPE_APPLICATION)

static void ite_app_init(IteApp *app) {}

static void ite_app_activate(GApplication *app) {
  IteAppWindow *win;

  win = ite_app_window_new(ITE_APP(app));
  gtk_window_present(GTK_WINDOW(win));
}

static void ite_app_open(GApplication *app, GFile **files, int n_files,
                         const char *hint) {
  GList *windows;
  IteAppWindow *win;
  int i;

  windows = gtk_application_get_windows(GTK_APPLICATION(app));
  if (windows)
    win = ITE_APP_WINDOW(windows->data);
  else
    win = ite_app_window_new(ITE_APP(app));

  for (i = 0; i < n_files; i++)
    ite_app_window_open(win, files[i]);

  gtk_window_present(GTK_WINDOW(win));
}

static void ite_app_class_init(IteAppClass *class) {
  G_APPLICATION_CLASS(class)->activate = ite_app_activate;
  G_APPLICATION_CLASS(class)->open = ite_app_open;
}

IteApp *ite_app_new(void) {
  return g_object_new(ITE_APP_TYPE, "application-id", "org.gtk.iteapp", "flags",
                      G_APPLICATION_HANDLES_OPEN, NULL);
}
