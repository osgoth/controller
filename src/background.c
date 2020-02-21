// gcc src/background.c src/daemonize.c -o bin/background `pkg-config --cflags --libs glib-2.0 gdk-pixbuf-2.0` -lnotify && ./bin/background

#include <libnotify/notify.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

void *shmem;

void notify(int num)
{
    FILE *buf;
    int pproc;
    char proc[6];
    NotifyNotification *msg;

    if ((buf = fopen("/tmp/ctrl.proc", "rb")) == NULL)
        exit(-1);
    fscanf(buf, "%d", &pproc);

    sprintf(proc, "[%d%%]", pproc);

    notify_notification_update(shmem, proc, NULL, NULL);
    notify_notification_show(shmem, NULL);
    printf("\nTRIGGERED!\n");
}

int main(int argc, char *argv[])
{
    FILE *buf;
    pid_t pid;
    notify_init("Controller");

    pid = getpid();

    if ((buf = fopen("/tmp/ctrl.pid", "wb")) == NULL)
        exit(-1);

    fprintf(buf, "%d", pid);
    fclose(buf);

    shmem = notify_notification_new("", NULL, NULL);

    //signal(SIGINT, notify);
    signal(SIGUSR1, notify);
    for (;;)
    {
        printf("%d\n", getpid());
        pause();
    }
    g_object_unref(G_OBJECT(shmem));
    notify_uninit();

    return (0);
}
