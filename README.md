# devicesManager
An application to monitor any generic device, it counts all the received messages from connected devices and print the number upon finish.
The project is written in c++, and it uses "shared_ptr" object to avoid manual deallocation so it's done automatically.


The application is structured in the following manner:
- DeviceManager.cpp

This class manage the logic of monitoring, by starting and stopping devices in bulk
- devices/

This folder must contain all devices classes

- devices/Device.cpp

This is the main abstract class that any new device must inherit. 

- devices/KeyboardDevice.cpp

This is a device binding for the keyboard, follow the example of this class to create new device bindings.


<h2>Compile and Run</h2>

To compile the project type:
<pre>
make
</pre>

and then simply run it:
<pre>
  dist/devicesmonitor
</pre>
