# XonoVIEW

XonoVIEW is a [LabVIEW][labview]-compatible wrapper around Ulterius, a proprietary software development kit provided
for use with [Sonix ultrasound systems][sonix].

[labview]: https://www.ni.com/labview
[sonix]: https://www.bkmedical.com/


### Getting started

#### Dependencies

XonoVIEW uses functionality provided by the Ulterius library, and was tested on a platform with:

- Windows 10 version **TODO**
- Microsoft Visual Studio version **TODO**
- GCC version **TODO**, using C++11 as the standard **TODO**
- Sonix SDK (Ulterius) version 6.1.0
- LabVIEW version **TODO**

#### Usage

The [provided pre-built DLL][xonoview-dll] can be [imported in LabVIEW][labview-howto].
You will need to place it in a folder with all the DLLs provided as part of Ulterius.

[xonoview-dll]: ./lib/xonoview.dll
[labview-howto]: ./doc/labview.md

#### Extending XonoVIEW

Please refer to the docstrings in the [DLL API specification][xonoview-api] for what functionality is already
available.
You can extend the DLL API by adding new functions that can subsequently be
[imported in LabVIEW][labview-howto].
In this process the DLL will need to be [re-built][xonoview-howto].

[xonoview-api]: ./api/dll.h
[xonoview-howto]: ./doc/build.md

#### Limitations

The Ulterius library is available only in 32-bit mode.
As a result, XonoVIEW is 32-bit only and hence requires LabVIEW to be run in 32-bit mode.


### Licensing and Copyright

#### XonoVIEW

XonoVIEW is released under the [Apache License, Version 2.0][license].

Copyright 2018 XonoVIEW Contributors

[license]: ./LICENSE

#### Ulterius

Ulterius is part of the Sonix SDK.

Copyright 2014 Ultrasonix Medical Corporation (now [BK Ultrasound][sonix])


### Acknowledgements

XonoVIEW was developed as part of the [GIFT-Surg][gift-surg] project.
This work was supported through an Innovative Engineering for Health award by the [Wellcome Trust][wt] [WT101957], the
[Engineering and Physical Sciences Research Council (EPSRC)][epsrc] [NS/A000027/1] and a [National Institute for Health
Research][nihr] Biomedical Research Centre UCLH/UCL High Impact Initiative.

[gift-surg]: http://www.gift-surg.ac.uk
[wt]: https://wellcome.ac.uk/
[epsrc]: https://epsrc.ukri.org/
[nihr]: https://www.nihr.ac.uk/
