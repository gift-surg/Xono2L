# Importing Xono2L into LabVIEW

This basic tutorial demonstrates how to capture a live ultrasound video stream with LabVIEW using Xono2L.
The screenshots in this tutorial are based on the [demo VI][demo-vi] included as part of this repository.

[demo-vi]: ../vi/demo.vi

DLL API functions are imported into LabVIEW using the `Call Library Function Node`s.
For this you will first need to let each such node know the path to your local copy of the Xono2L DLL.
Then you will need to specify the input and output argument types.
Finally you will need to connect them to LabVIEW input and output nodes of appropriate types.

The sections below illustrate how to do all of this using the [demo VI][demo-vi] provided.
This animated image illustrates what to expect after completing all these steps:

<img src="res/xono2l.gif" align="center" width=480>

## Starting the acquisition

Import the `start_acquisition` API function:

![alt text][start_import]

[start_import]: ./res/start_import.png "Importing the acquisition starter function into LabVIEW"

Set its input and output parameters:

![alt text][start_params]

[start_params]: ./res/start_params.png "Parameters of the acquisition starter function"

## Stopping the acquisition

Import the `stop_acquisition` API function:

![alt text][stop_import]

[stop_import]: ./res/stop_import.png "Importing the acquisition stopper function into LabVIEW"

Set its input and output parameters:

![alt text][stop_params]

[stop_params]: ./res/stop_params.png "Parameters of the acquisition stopper function"

## Checking the acquisition status

Import the `is_acquiring` API function:

![alt text][status_import]

[status_import]: ./res/status_import.png

Set its input and output parameters:

![alt text][status_params]

[status_params]: ./res/status_params.png

## Capturing the ultrasound video frames

Import the `get_data` API function:

![alt text][capture_import]

[capture_import]: ./res/capture_import.png

Set its input and output parameters:

![alt text][capture_params]

[capture_params]: ./res/capture_params.png

