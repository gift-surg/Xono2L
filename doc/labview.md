# Importing Xono2L into LabVIEW

This basic tutorial demonstrates how to capture a live ultrasound video stream with LabVIEW using Xono2L.
The screenshots in this tutorial are based on the [demo VI][demo-vi] included as part of this repository.

[demo-vi]: ../vi/demo.vi

DLL API functions are imported into LabVIEW using the `Call Library Function Node`s.
For this you will first need to let each such node know the path to your local copy of the Xono2L DLL.
Then you will need to specify the input and output argument types.
Finally you will need to connect them to LabVIEW input and output nodes of appropriate types.
Please see the [demo VI][demo-vi] for an example.

## Starting the acquisition

Import the `start_acquisition` API function:

![alt text][start]

[start]: ./res/start.png "Importing the acquisition starter function into LabVIEW"

## Stopping the acquisition

Import the `stop_acquisition` API function:

![alt text][stop]

[stop]: ./res/stop.png "Importing the acquisition stopper function into LabVIEW"

## Checking the acquisition status

Import the `is_acquiring` API function:

![alt text][status]

[status]: ./res/status.png

## Capturing the ultrasound video frames

Import the `get_data` API function:

![alt text][capture]

[capture]: ./res/capture.png
