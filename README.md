# Xono2L

Xono2L is a [LabVIEW][labview]-compatible, extensible C++ API that supports the capture of live ultrasound streams.
Xono2L links with one of the following:
* Ulterius library, which is part of the Sonix SDK, a proprietary software development kit provided for use with
[Sonix ultrasound systems][sonix]
* Epiphan Video Grabber SDK, a proprietary software development kit provided for use with [Epiphan frame grabbers][epiphan]

The following animated image shows a [demo VI][demo-vi] with Xono2L in action:

![alt text][labview-with-xono2l]

[labview-with-xono2l]: ./doc/res/xono2l.gif

[labview]: https://www.ni.com/labview
[sonix]: https://www.bkmedical.com/
[demo-vi]: vi/demo.vi
[epiphan]: https://www.epiphan.com/


## Getting started

### Dependencies

Depending on how it's configured, Xono2L uses functionality provided by either the Ulterius library or the
Epiphan Video Grabber SDK.
So one of these two will be the only run-time dependency if you're using a [pre-built DLL][xono2L-dll].

Xono2L was tested on a platform with:

- Windows 10 version 1803
- LabVIEW version 17.0.1f1 (32-bit)
- CMake version 3.12.4
- Sonix SDK (Ulterius) version 6.1.0
- Epiphan Video Grabber SDK version 3.30.3.0007

### Usage

The [provided pre-built DLL][xono2L-dll] can be [imported in LabVIEW][labview-howto].
Please note that the respective SDK should be accessible by your system when running LabVIEW.
We recommend installing:
* Sonix SDK under `C:/Program Files (x86)/sdk610` and [adding its `bin`
sub-folder to your `PATH` environment variable][win-env].
* Epiphan Video Grabber SDK under `C:/Program Files/Epiphan/epiphan_sdk-3.30.3.0007` and [adding its `epiphan\bin`
sub-folder to your `PATH` environment variable][win-env].

[xono2L-dll]: https://github.com/gift-surg/Xono2L/releases
[labview-howto]: ./doc/labview.md
[win-env]: https://docs.microsoft.com/en-us/windows/desktop/procthread/environment-variables

### Extending Xono2L

Please refer to the docstrings in the [DLL API specification][xono2L-api] for what functionality is already
available.
You can extend the DLL API by adding new functions that can subsequently be
[imported in LabVIEW][labview-howto].
In this process the DLL will need to be built by running the following CMake commands from within your
build directory:

```bash
cmake -D <sdk-option>:BOOL=ON <path-to-xono2L-source-code>
cmake --build . --config Release
```

where `<sdk-option>` is either `USE_ULTERIUS` or `USE_EPIPHAN`, activating the corresponding support.

The Xono2L CMake configuration files will be able to locate the needed Ulterius components
provided the Sonix SDK is installed in the recommended location on your computer (see the Usage
section above).

[xono2L-api]: api/xono2l.h

### Limitations

The Ulterius library is available only in 32-bit mode.
As a result, Xono2L is 32-bit only and hence requires LabVIEW to be run in 32-bit mode.


## Licensing and Copyright

### Xono2L

Xono2L is released under the [Apache License, Version 2.0][license].

Copyright 2018 Xono2L Contributors

[license]: ./LICENSE

### Ulterius

Ulterius is part of the Sonix SDK, and **not included in this repository**.

Copyright 2014 Ultrasonix Medical Corporation (now [BK Ultrasound][sonix])

### Epiphan Video Grabber SDK

**Not included in this repository**.

Copyright (C) 2008-2013 [Epiphan Systems Inc.][epiphan]

## Acknowledgements

This work is supported by the [Wellcome Trust][wt] [WT101957; 203145Z/16/Z and 203148/Z/16/Z] and the [Engineering and Physical Sciences Research Council (EPSRC)][epsrc] [NS/A000027/1; NS/A000050/1; NS/A000049/1 and EP/N021177/1], notably through the [GIFT-Surg][gift-surg] Innovative Engineering for Health award, the [Wellcome/EPSRC Centre for Interventional and Surgical Sciences (WEISS)][weiss] and the [Wellcome/EPSRC Centre for Medical Engineering (CME)][cme]. This work is also supported by the [National Institute for Health Research][nihr] Biomedical Research Centre UCLH/UCL High Impact Initiative.

[wt]: https://wellcome.ac.uk/
[epsrc]: https://epsrc.ukri.org/
[nihr]: https://www.nihr.ac.uk/
[cme]: https://medicalengineering.org.uk/
[gift-surg]: https://www.gift-surg.ac.uk
[weiss]: http://ucl.ac.uk/weiss
