#include <gtk/gtk.h>

#include "iteapp.h"

int main(int argc, char *argv[]) {
  return g_application_run(G_APPLICATION(ite_app_new()), argc, argv);
}
