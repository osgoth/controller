gcc src/background.c -o background `pkg-config --cflags --libs glib-2.0 gdk-pixbuf-2.0` -lnotify
mv background /usr/bin/ctrl_bg

gcc src/main.c -o main
mv main /usr/bin/ctrl