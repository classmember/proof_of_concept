#include <libnotify/notify.h>
#include <gtk/gtk.h>

/**
 * compile with:
 *     gcc crud.c -o crud $(pkg-config --libs --cflags gtk+-2.0) -lnotify
 */

static void yes(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Yes");
    g_print("Yes\n");
}

static void yes_notification(GtkWidget *widget, gpointer data) {
	notify_init ("crud");
	NotifyNotification * YesNote;
    YesNote = notify_notification_new(
        "Yes", "Yeah, I know, right?!", "dialog-information");
	notify_notification_show(YesNote, NULL);
	g_object_unref(G_OBJECT(YesNote));
}

static void no(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "No");
    g_print("No\n");
}

static void no_notification(GtkWidget *widget, gpointer data) {
	notify_init ("crud");
	NotifyNotification * NoNote;
    NoNote = notify_notification_new(
        "No", "Nah, I didn't think so.", "dialog-information");
	notify_notification_show(NoNote, NULL);
	g_object_unref(G_OBJECT(NoNote));
}

static void maybe(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Maybe");
    g_print("Maybe\n");
}

static void maybe_notification(GtkWidget *widget, gpointer data) {
	notify_init ("crud");
	NotifyNotification * MaybeNote;
    MaybeNote = notify_notification_new(
        "Maybe", "Who knows, ya know?", "dialog-information");
	notify_notification_show(MaybeNote, NULL);
	g_object_unref(G_OBJECT(MaybeNote));
}

static gboolean delete_event(GtkWidget *widget,
                             GdkEvent  *event,
                             gpointer   data) {
    /* If you return FALSE in the "delete-event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */

    g_print ("goodbye\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete-event". */

    return FALSE;
}

/* Another callback */
static void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit ();
}

int main(int argc, char *argv[]) {

	//notify_init ("crud");

    GtkWidget *window;
    GtkWidget *topbar_box; 
    GtkWidget *choices_box; 
    GtkWidget *display_box; 
	GtkWidget *choices_label;
    GtkWidget *display_label; 
    GtkWidget *yes_button;
    GtkWidget *no_button;
    GtkWidget *maybe_button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK (delete_event), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK (destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER (window), 5);

    topbar_box = gtk_hbox_new(FALSE, 0);
    choices_box = gtk_vbox_new(FALSE, 0);
    display_box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), topbar_box);

	choices_label = gtk_label_new("Choices");
	gtk_misc_set_alignment(GTK_MISC (choices_label), 0, 0);
	display_label = gtk_label_new("Display");
	gtk_misc_set_alignment(GTK_MISC (display_label), 0, 0);

    yes_button = gtk_button_new_with_label("Yes");
    g_signal_connect(yes_button, "clicked", G_CALLBACK (yes), display_label);
    g_signal_connect(yes_button, "clicked", G_CALLBACK (yes_notification), NULL);
    
    no_button = gtk_button_new_with_label("No");
    g_signal_connect(no_button, "clicked", G_CALLBACK (no), display_label);
    g_signal_connect(no_button, "clicked", G_CALLBACK (no_notification), NULL);

    maybe_button = gtk_button_new_with_label("Maybe");
    g_signal_connect(maybe_button, "clicked", G_CALLBACK (maybe), display_label);
    g_signal_connect(maybe_button, "clicked", G_CALLBACK (maybe_notification), NULL);

	gtk_box_pack_start(GTK_BOX(choices_box), choices_label, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(choices_box), yes_button, 1, 1, 1);
	gtk_box_pack_start(GTK_BOX(choices_box), no_button, 1, 1, 1);
	gtk_box_pack_start(GTK_BOX(choices_box), maybe_button, 1, 1, 1);
    
	gtk_box_pack_start(GTK_BOX(display_box), display_label, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(topbar_box), choices_box, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(topbar_box), display_box, FALSE, FALSE, 0);

	gtk_widget_show(choices_label);
    gtk_widget_show(yes_button);
    gtk_widget_show(no_button);
    gtk_widget_show(maybe_button);
	gtk_widget_show(choices_box);

	gtk_widget_show(display_label);
	gtk_widget_show(display_box);

	gtk_widget_show(topbar_box);

    gtk_widget_show(window);
    
	notify_uninit();
    gtk_main();
    
    return 0;
}
