#include <gtk/gtk.h>

void shutDown(GtkWidget *widget, gpointer data){
	
	system("shutdown now");
	
}

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *halign;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  /*
   * Center the window
   */
  gtk_window_set_title(GTK_WINDOW(window), "Center");
  gtk_window_set_default_size(GTK_WINDOW(window), 650, 450);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  //gtk_widget_show(window);
  
  button = gtk_button_new_with_label("Shutdown");
  
  halign = gtk_alignment_new(0, 0, 0, 0);
  gtk_container_add(GTK_CONTAINER(halign), button);
  gtk_container_add(GTK_CONTAINER(window), halign);
  
  gtk_widget_show_all(window);
  
  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);  
      
  g_signal_connect(G_OBJECT(button), "clicked",
		G_CALLBACK(shutDown), NULL);

  gtk_main();

  return 0;
}
