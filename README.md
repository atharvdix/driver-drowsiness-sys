# Driver Drowsiness Detection System
In this project, an ML application was created to detect driver drowsiness detection in real-time.

<H1><STRONG>Introduction</STRONG></H1>
<DIV>
Driver drowsiness detection is a car safety technology which helps prevent accidents caused by the driver getting drowsy. 
Various studies have suggested that around 20% of all road accidents are fatigue-related, up to 50% on certain roads.
</DIV>
This project implements Drowsiness detection system using <EM>OPENCV</EM> and <EM>DLIB</EM> library. It is a real-time system project 
which uses face detection and face landmark to obtain the eye landmark coordinates. These landmark coordinates
are used to calculate eye aspect ratio(EAR). The EAR value is compared with the EAR Threshold and when
it drops below the threshold an event is triggered. The event may be anything ranging from an alarm
to engaging brakes of a vehicle.
<DIV>
Important links for documentation, <a href="http://dlib.net/">DLIB</a> and <a href="https://docs.opencv.org/">OpenCV</a>.
</DIV>

<H1><STRONG>Working details</STRONG></H1>

<H2><STRONG>Face Detection</STRONG></H2>
The face detection part of program was implemented using OPENCV library. The opencv library provides easy implementation method 
to detect face using Haar Cascade algorithm. Haar feature-based cascade classifiers is an effective object detection method proposed 
by Paul Viola and Michael Jones in their paper, “Rapid Object Detection using a Boosted Cascade of Simple Features” in 2001.

<H2><STRONG>Face Landmark</STRONG></H2>
The face landmarking was done using DLIB library. The DLIB library is a open source library which provides utilies ranging from linear
algebra to machine learning for embedded systems. Face landmark detection is the process of finding points of interest in an image of a 
human face. For more details, visit the shape predictor module of the DLIB library,<a href="http://dlib.net/imaging.html#shape_predictor">Face Landmark</a>

<p align="centre">
<figure>
  <img src="http://1.bp.blogspot.com/-FtyIjfFokzQ/U__h1sAoEEI/AAAAAAAAAR0/URuVhX9cR-E/s1600/landmarked_face2.png" style="width:40%">
  <figcaption>Fig.1 - Face Landmarking (<a href="http://blog.dlib.net/2014/08/real-time-face-pose-estimation.html">Source</a>)</figcaption>
</figure>
</p>

<H2><STRONG>Eye aspect ratio</STRONG></H2>
The Eye Aspect Ratio is an estimate of the eye opening state. The Eye Aspect Ratio is a constant value when the eye is open, 
but rapidly falls to 0 when the eye is closed. The figure below shows the eye aspect ratio points.

<p align="centre">
<figure>
  <img src="https://lh4.googleusercontent.com/nRrUTXr-8JDgU90YI_eKentZtQQeMSRWshc1TW73SBRKiJzRcund2J4T_VjyGAMHOB7nhgZJskpSa2o93e-eL7pyUhU_1D6UuNxC2f6SXlPLGr3iN9eWTCujRpOcn_OAf_KYHzIb" class="center">
  <figcaption>Fig.2 - Eye aspect ratio points (<a href="https://hackaday.io/project/27552-blinktotext/log/68360-eye-blink-detection-algorithms">Source</a>)</figcaption>
</figure>
</p>

The calculations of eye aspect ratio (EAR) are done using following formulas,

<p align="centre">
<DIV>A = euclidean_distance(p6,p2)</DIV>
<DIV>B = euclidean_distance(p5,p3)</DIV>
<DIV>C = euclidean_distance(p4,p1)</DIV>
<DIV>EAR = (A + B) / (2*C)</DIV>
</p>

Using the obtained EAR value the event is triggered whenever the value is below threshold for particular amount of time.

<H1><STRONG>Result</STRONG></H1>
<p align="centre">
<figure>
  <img src="https://github.com/atharvdix/driver-drowsiness-sys/blob/main/Figures/Face%20detection%20error.jpg">
  <figcaption>Fig.3 - Error flagged when face is covered</figcaption>
</figure>
</p>
<p align="centre">
<figure>
  <img src="https://github.com/atharvdix/driver-drowsiness-sys/blob/main/Figures/Event%20Check%20-%20eyes%20open.jpg">
  <figcaption>Fig.4 - No action when eyes are open</figcaption>
</figure>
</p>
<p align="centre">
<figure>
  <img src="https://github.com/atharvdix/driver-drowsiness-sys/blob/main/Figures/Event%20Triggers.jpg">
  <figcaption>Fig.5 - Events are triggered continuously as long as eyes remain closed</figcaption>
</figure>
</p>

<H3>Documentation</H3>
<p>To see the documentation click on the <a href="https://atharvdix.github.io/driver-drowsiness-sys/html/index.html">link</a></p>
