# controller
Brightness and audio controller with notifications.<br>

<strong>Currently wotking for intel backlight.</strong><br>
For it to work, both, user and "brightness" file in <i>/sys/class/backlight/intel_backlight</i> have to be in <b>video</b> group.<br>
In order to have notifications working, you should first start <b>ctrl_bg</b> process.<br>

Usage:<br>
    ctrl [option] [-+(int)]<br><br>
    <ul>
        <li>
        options:
        <ul>
            <li>
                current:<ul><li>
                    br - brightnes</li></ul>
            </li>
            <li>
                potential:<ul><li>
                    vol - volume</li></ul>
            </li>
        </ul>
        </li>
    </ul>
