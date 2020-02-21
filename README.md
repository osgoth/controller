# controller
Brightness and audio controller with notifications.

<strong>Currently wotking for intel backlight.</strong>
For it to work, both, user and "brightness" file in <i>/sys/class/backlight/intel_backlight</i> have to be in <b>video</b> group.
In order to have notifications working, you should first start <b>ctrl_bg</b> process.

Usage:
    ctrl [option] [-+(int)]
    options:
        current:
            br - brightnes
        potential:
            vol - volume
