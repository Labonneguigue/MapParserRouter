# Parser and Router

This is a piece of code embedded in a bigger project, my final year project at INSA toulouse.
The project was to create an autonomous car. This map is used later on for the car's guidance system.

## Installing

You need to install OpenCV on your machine.

## Compiling

Execute
```
make
```
in the terminal in the folder containing the Makefile.

## What does the code do

The input is a xml file containing OpenStreetMap data. First, it parses the file to create an instance of each underlying element (Node, Road, Building) that would later on be useful for the car's guidance system.
It then renders these element so we can observe what is going on.

![ScreenShot](Images/insa.tiff)

On this screenshot, you can see the roads and buildings of my campus in Toulouse, France. You can compare it to the view from google maps.

![ScreenShot](Images/insa-gmaps.tiff)

Then, there is a zooming functionality :

![ScreenShot](Images/zoom.tiff)

The blue road is the road that is the closest to the current point (in red). It is therefore the road the algorithm assumes the car is on. The way each roads are computed is by a starting point and an ending point having as x and y coordinates the longitude and latitude.

The second functionality that this algorithm provides is the routing from the current position to a given destination. Each road has the form ax + b = y. From that coefficient a, the heading [0, 360[ in degrees is then deducted to guide the car to the next intermediate checkpoint. The full blue circle is the destination. 

![ScreenShot](Images/router.tiff)

Lastly, here is another output with the city center of Toulouse. The parsing algorithm is generic and can take any piece of land as long as it is inputed as OpenStreetMap data (the .osm files have in fact an xml format)

![ScreenShot](Images/capitole.tiff)

and the google version:

![ScreenShot](Images/capitole-gmaps.tiff)
