#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// bl au -10
// bl br 20
int main(int argc, char *argv[])
{

    if (argc <= 2)
    {
        printf("Too little arguments\n");

        return -1;
    }

    if (strcmp(argv[1], "br") == 0)
    {
        int add = atoi(argv[2]);
        int curr = 0;
        int max = 0;
        int brightness = 0;
        int proc = 0;
        int newproc = 0;
        int coef = 0;
        int newbr = 0;
        FILE *f;

        if ((f = fopen("/sys/class/backlight/intel_backlight/max_brightness", "r")) == NULL)
            return 1;

        fscanf(f, "%d", &max);
        coef = (max * 1.0) / 100;

        if ((f = fopen("/sys/class/backlight/intel_backlight/brightness", "r")) == NULL)
            return 1;

        fscanf(f, "%d", &brightness);

        proc = brightness / coef;

        add *= coef;

        newbr = brightness + add;

        newproc = newbr / coef;

        if ((f = fopen("/sys/class/backlight/intel_backlight/brightness", "w")) == NULL)
            return 1;

        fprintf(f, "%d", newbr);

        fclose(f);

        printf("current brigthness: %d\n", brightness);
        printf("max: %d\n", max);
        printf("current procent: %d\n", proc);
        printf("to add: %d\n", add);
        printf("after addition: %d\n", newbr);
        printf("new procent: %d\n", newproc);

        send_notification(newproc);
    }

    return 0;
}

void send_notification(int procent)
{
    FILE *pidf;
    FILE *buf;
    int pid;

    if ((pidf = fopen("/tmp/ctrl.pid", "rb")) == NULL)
        exit(-1);
    fscanf(pidf, "%d", &pid);
    fclose(pidf);

    if ((buf = fopen("/tmp/ctrl.proc", "wb")) == NULL)
        exit(-1);
    fprintf(buf, "%d", procent);
    fclose(buf);

    kill(pid, SIGUSR1);
}