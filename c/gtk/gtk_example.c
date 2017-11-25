#include <gtk/gtk.h>
/**
 * compile with:
 *     gcc gtk_example.c -o gtk_example $(pkg-config --cflags --libs gtk+-2.0)
 */

/* This is a callback function. The data arguments are ignored
 * in this example. More on callbacks below. */
static void yes(GtkWidget *widget, gpointer data) {
    g_print ("Yes\n");
}

static void no(GtkWidget *widget, gpointer data) {
    g_print ("No\n");
}

static void maybe(GtkWidget *widget, gpointer data) {
    g_print ("Maybe\n");
}

static gboolean delete_event(GtkWidget *widget,
                             GdkEvent  *event,
                             gpointer   data) {
    /* If you return FALSE in the "delete-event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */

    g_print ("delete event occurred\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete-event". */

    return TRUE;
}

/* Another callback */
static void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit ();
}

int main(int argc, char *argv[]) {

    GtkWidget *window;
    GtkWidget *choices_box; 
	GtkWidget *label;
    GtkWidget *yes_button;
    GtkWidget *no_button;
    GtkWidget *maybe_button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK (delete_event), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK (destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER (window), 5);

    choices_box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), choices_box);

	label = gtk_label_new("Choices");
	gtk_misc_set_alignment(GTK_MISC (label), 0, 0);

    yes_button = gtk_button_new_with_label("Yes");
    g_signal_connect(yes_button, "clicked", G_CALLBACK (yes), NULL);
    g_signal_connect_swapped(yes_button,
                             "clicked",
                              G_CALLBACK (gtk_widget_destroy),
                              window);
    
    no_button = gtk_button_new_with_label("No");
    g_signal_connect(no_button, "clicked", G_CALLBACK (no), NULL);
    g_signal_connect_swapped(no_button,
                             "clicked",
                              G_CALLBACK (gtk_widget_destroy),
                              window);

    maybe_button = gtk_button_new_with_label("Maybe");
    g_signal_connect(maybe_button, "clicked", G_CALLBACK (maybe), NULL);
    g_signal_connect_swapped(maybe_button,
                             "clicked",
                              G_CALLBACK (gtk_widget_destroy),
                              window);


	gtk_box_pack_start(GTK_BOX(choices_box), label, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(choices_box), yes_button, 1, 1, 1);
	gtk_box_pack_start(GTK_BOX(choices_box), no_button, 1, 1, 1);
	gtk_box_pack_start(GTK_BOX(choices_box), maybe_button, 1, 1, 1);
    
	gtk_widget_show(label);
    gtk_widget_show(yes_button);
    gtk_widget_show(no_button);
    gtk_widget_show(maybe_button);
	gtk_widget_show(choices_box);
    gtk_widget_show(window);
    
    gtk_main();
    
    return 0;
}
