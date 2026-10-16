# GameControl

**GameControl** is a lightweight Windows parental control application built with C++Builder (VCL) that helps parents limit and manage screen or gaming time for kids.

When the configured timer expires, the application automatically minimizes all open windows and displays a lock/control screen, preventing further play unless authorized.

---

## Key Features

* **Flexible Timer Setup:** Set custom countdown durations using hours and minutes, or quick-add presets (+30 mins, +1 hour, +2 hours).
* **System Tray Integration:** Runs silently in the background (minimized to the notification area/system tray) while the timer is active.
* **Automatic Session Interrupt:** Minimizes all open applications automatically upon timer expiration and brings the lock screen to the foreground.
* **Password Protection:** Prevents unauthorized setting adjustments, stopping the timer, or unauthorized access via a password prompt.
* **First-Run Wizard:** Detects initial setups and forces password configuration prior to enabling timer operations.
* **Modern UI Themes:** Native support for VCL styles, including Windows 11 White Smoke (Light) and MineShaft (Dark) modes, saved to `data.ini`.

---

## Requirements

* **OS:** Windows 7 / 8 / 10 / 11 (32-bit or 64-bit)
* **Subsystem:** Win32 (built with Embarcadero C++Builder VCL framework)
