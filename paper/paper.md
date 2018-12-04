---
title: 'Xono2L: an eXtensible, LabVIEW-compatible real-time sONOgraphic data capture and processing TOOL'
tags:
  - Medical Imaging
  - Real-time Video Streaming
  - Ultrasound Imaging
  - LabVIEW
  - Windows
authors:
  - name: Dzhoshkun Ismail Shakir
    orcid: 0000-0003-3009-4178
    affiliation: "1, 2, 3"
  - name: Sunish Mathews
    orcid: 0000-0002-2289-3669
    affiliation: "3, 4"
  - name: Wenfeng Xia
    orcid: 0000-0002-1147-6886
    affiliation: "1, 3"
  - name: Adrien Desjardins
    orcid: 0000-0002-1932-1811
    affiliation: "3, 4"
  - name: Tom Vercauteren
    orcid: 0000-0003-1794-0456
    affiliation: "1, 3"
affiliations:
 - name: "School of Biomedical Engineering and Imaging Sciences, King's College London"
   index: 1
 - name: University College London Hospitals NHS Foundation Trust
   index: 2
 - name: "Department of Medical Physics and Biomedical Engineering, University College London"
   index: 3
 - name: "Wellcome/EPSRC Centre for Interventional and Surgical Sciences, University College London"
   index: 4
date: 27 November 2018
bibliography: paper.bib
---

# Summary

Research in advanced sonographic real-time clinical imaging methods such as ultrasonic needle tracking
[@Xia2018JoVE,@Xia2016MICCAI,@Guo2014SPIE,@Mung2011MICCAI,@nikolov2008precision] is facilitated by the
[LabVIEW][labview] rapid system-design and development environment.
This research and associated clinical translational developments [@Xia2016MedPhys,@xia2017looking,@Xia2017MICCAI]
involve the capture and processing of live ultrasound data streams with LabVIEW.

Existing open-source software packages such as Plus [@Lasso2014TBME] and NifTK [@Clarkson2015IJCARS] support
the capture of live ultrasound streams; however, they do not provide a LabVIEW interface.
To bridge this gap, we have designed and developed [Xono2L][xono2l] as a LabVIEW-compatible, extensible C++ API.
Xono2L links with the Ulterius library, a component of the proprietary Sonix SDK provided for use with
[Sonix ultrasound systems][sonix] commercialised initially by Ultrasonix Medical Corp. and currently by BK Medical
Holding Company, Inc.

[Xono2L][xono2l] is intended as an extensible tool that allows for the real-time capture of ultrasound imaging data,
which in turn facilitates processing with LabVIEW.
Although Xono2L's scope is currently limited to Sonix ultrasound systems, we have made it available to the
research community to facilitate research with these devices.
Xono2L's API is flexible and can be extended to cover a broad range of use cases.

[xono2l]: https://github.com/gift-surg/Xono2L
[labview]: https://www.ni.com/labview
[sonix]: https://www.bkmedical.com/

# Acknowledgements

This work is supported by the [Wellcome Trust][wt] [WT101957; 203145Z/16/Z and 203148/Z/16/Z] and the [Engineering and
Physical Sciences Research Council (EPSRC)][epsrc] [NS/A000027/1; NS/A000050/1; NS/A000049/1 and EP/N021177/1], notably
through the [GIFT-Surg][gift-surg] Innovative Engineering for Health award, the [Wellcome/EPSRC Centre for
Interventional and Surgical Sciences (WEISS)][weiss] and the [Wellcome/EPSRC Centre for Medical Engineering (CME)][cme].
This work is also supported by the [National Institute for Health Research][nihr] Biomedical Research Centre UCLH/UCL
High Impact Initiative.

[wt]: https://wellcome.ac.uk/
[epsrc]: https://epsrc.ukri.org/
[nihr]: https://www.nihr.ac.uk/
[cme]: https://medicalengineering.org.uk/
[gift-surg]: https://www.gift-surg.ac.uk
[weiss]: http://ucl.ac.uk/weiss

# References
