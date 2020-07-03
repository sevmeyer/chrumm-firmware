Chrumm firmware
===============

This is the firmware for the [Chrumm] keyboard prototype.
It is implemented in the [Arduino C++ dialect] and can be
compiled and installed with [arduino-cli].

[Chrumm]: https://github.com/sevmeyer/chrumm-keyboard
[Arduino C++ dialect]: https://www.arduino.cc/reference/en
[arduino-cli]: https://arduino.github.io/arduino-cli/


Setup
-----

The command line examples are written for the
[Adafruit ItsyBitsy 32u4 5V 16MHz] board, but it should
be possible to adapt them to any other capable board.
The third-party index URL for the ItsyBitsy is provided
in the `arduino-cli.yaml` configuration file.

Update the index:

	arduino-cli core update-index

Install the platform cores:

	arduino-cli core install arduino:avr
	arduino-cli core install adafruit:avr

Install the [HID-Project] library:

	arduino-cli lib install HID-Project

[Adafruit ItsyBitsy 32u4 5V 16MHz]: https://www.adafruit.com/product/3677
[HID-Project]: https://github.com/NicoHood/Hid


Compile
-------

Compile the firmware:

	arduino-cli compile --fqbn adafruit:avr:itsybitsy32u4_5V chrumm

Upload to board (adjust the port if necessary):

	arduino-cli upload --fqbn adafruit:avr:itsybitsy32u4_5V --port /dev/ttyACM0 chrumm

On Linux, I had to add the current user to the
dialout group to get permission for the upload:

	sudo adduser USERNAME dialout

I also had to uninstall `modemmanager`,
because it interfered with the connection.
