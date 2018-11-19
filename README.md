# Xono2L

Xono2L is a [LabVIEW][labview]-compatible wrapper around the Ulterius library, which is part of
the Sonix SDK, a proprietary software development kit provided for use with
[Sonix ultrasound systems][sonix].
Please see this YouTube video for a screencast showing a [demo VI][demo-vi] with Xono2L in action:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=z0DbbX2aZpU"
 target="_blank"><img src="http://img.youtube.com/vi/z0DbbX2aZpU/0.jpg"
 alt="IMAGE ALT TEXT HERE" width="480" height="360" border="10" /></a>

[labview]: https://www.ni.com/labview
[sonix]: https://www.bkmedical.com/
[demo-vi]: vi/demo.vi


## Getting started

### Dependencies

Xono2L uses functionality provided by the Ulterius library.
Ulterius is the only run-time dependency if you're using the [pre-built DLL][xono2L-dll].

Xono2L was tested on a platform with:

- Windows 10 version 1803
- LabVIEW version 17.0.1f1 (32-bit)
- CMake version 3.12.4
- Sonix SDK (Ulterius) version 6.1.0

### Usage

The [provided pre-built DLL][xono2L-dll] can be [imported in LabVIEW][labview-howto].
Please note that the Sonix SDK should be accessible by your system when running LabVIEW.
We recommend installing it under `C:/Program Files (x86)/sdk610` and [adding its `bin`
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
cmake <path-to-xono2L-source-code>
cmake --build . --config Release
```

The Xono2L CMake configuration files will be able to locate the needed Ulterius components
provided the Sonix SDK is installed in the recommended location on your computer (see the Usage
section above).

[xono2L-api]: ./api/xono2L.h

### Limitations

The Ulterius library is available only in 32-bit mode.
As a result, Xono2L is 32-bit only and hence requires LabVIEW to be run in 32-bit mode.


## Licensing and Copyright

### Xono2L

Xono2L is released under the [Apache License, Version 2.0][license].

Copyright 2018 Xono2L Contributors

[license]: ./LICENSE

### Ulterius

Ulterius is part of the Sonix SDK.

Copyright 2014 Ultrasonix Medical Corporation (now [BK Ultrasound][sonix])


## Acknowledgements

This work was supported through an Innovative Engineering for Health award by the [Wellcome Trust][wt]
[WT101957], the [Engineering and Physical Sciences Research Council (EPSRC)][epsrc] [NS/A000027/1 and EP/N021177/1]
and a [National Institute for Health Research][nihr] Biomedical Research Centre UCLH/UCL High Impact Initiative.

[gift-surg]: http://www.gift-surg.ac.uk
[wt]: https://wellcome.ac.uk/
[epsrc]: https://epsrc.ukri.org/
[nihr]: https://www.nihr.ac.uk/
