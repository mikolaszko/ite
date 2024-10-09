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
static void draw_function(GtkDrawingArea *area, cairo_t *cr, int width,
                          int height, gpointer data) {
  GdkRGBA color;
  color.green = 1.0;
  color.blue = 1.0;
  color.red = 0.0;
  color.alpha = 1.0;

  cairo_arc(cr, width / 2.0, height / 2.0, MIN(width, height) / 2.0, 0,
            2 * G_PI);

  gdk_cairo_set_source_rgba(cr, &color);

  cairo_fill(cr);
}

void ite_app_window_open(IteAppWindow *win) {
  GtkWidget *area = gtk_drawing_area_new();
  gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(area), 500);
  gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(area), 500);
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(area), draw_function, NULL,
                                 NULL);
}
