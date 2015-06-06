# Hand Coding Gerbers
Where Carlyn gets a wee bit controlling. 

 
![alt text](https://c1.staticflickr.com/1/450/18501083412_c6003eb3a6.jpg "Image of Otherplan software rendering of gerber file in this repo")


## Why did Carlyn want to hand code gerber files?

Because she's crazy.

## No, really...

Well, I was interested in the difference between how Otherplan imported .svg files 
and Eagle .brd files. Specifically with svg files I didn't feel like I had enough 
control over "put a tiny hole here." 

Eagle, however, isn't a design package. 

I wanted some lower level control so I could someday create algorithmically 
generated designs. 

This very much not be the best path to go down for this. But it was entertaining. 

## Whats a gerber file?

Gerber files are the set up files for PCB board houses so they can deliver do precisely 
what you want with super tiny tolerances.

A given project might have lots of files for different aspects of the board.
  
### How did you learn how to write them?

Well, I already know Eagle and ulp scr scripts and exporting to gerber, blah blah blah 
so I wasn't starting from zero.

3 most helpful links:
- https://learn.sparkfun.com/tutorials/using-eagle-board-layout/generating-gerbers
- http://www.artwork.com/gerber/274x/rs274x.htm
- http://www.ucamco.com/downloads (where the specification lives)

## Annotations

There doesn't seem to be the ability to comment inside of gerber files and I will 
totally forget.

| Gerber File Says       | It means(ish)          |
| ------------- |:------------- |
| `G04 Beginning of File Message*` | Start the file with a message |
| `%FSLAX25Y25*%` |  Tell the file how you are going to handle numbers. (7 characters, where the right 5 are decimal places, leave off leading zeros.| 
| `%MOIN*%` | Measurements are in inches. |
| `%TF.FileFunction,Plated,1,8,PTH*%` | The roll of the file in the project (top copper?) |
| `%TF.Part,Single*%` | Not super clear on this myself. Think it means that it might be referred to by other files, but it has no references? |
| `%LPD*%` | Dark or Clear (what is the significant information)|
| `%TA.DrillTolerance,0.01,0.005*%` | Can you have any play in your tool? in mils|
| `%TA.AperFunction,ComponentDrill*%` | Named apertures? An analogy for apertures in a drawing program would be a brush-type |
| `%ADD10C,0.0625*% ` | my circular aperture should have an outer circumference of 0.0625 inches |
| `%TA.AperFunction,MySpecialDrill*% ` | starting a new drill bit/brush stroke with a new name. Could have changed the tolerances. |
| `%ADD11C,0.25X0.125X0.125*%` | This one will be a circle with a square cut out of it. (think pad on a board) |
| `%AMOC8*` | I'm going to have a shape 0C8 |
| `5,1,8,0,0,1.08239X$1,22.5*` | with properties (the 8 is for octagon) |
| `%` | End of my super fun shape. |
| `%ADD12OC8,0.25000*%` | I'm going to use that shape to create a 0.25 inch aperture(brush) |
| `%TD.AperFunction*% ` | close mucking about with aperture functions |
| `%TD.DrillTolerance*%` | close mucking about with drill tolerances |
| `G01*` | get into the normal drawing mode |
| `D10*` | pull out bush "10" |
| `X100000Y0D01*` | I assumed that I was starting at 0,0, that was probably bad. But from (0,0) goto (1 inch,0) with the brush down. |
| `X100000Y100000D01*` | goto (1 inch ,1 inch) with the brush down. |
| `X0Y100000D01*` | goto (0,1 inch) with the brush down. |
| `X0Y0D01*` | goto (0,0) with the brush down. |
| `X50000Y25000D02*` | goto (0.5,0.25) with the brush UP |
| `X50000Y75000D01*` | goto (0.5,0.75) with the brush DOWN |
| `X25000Y50000D02*` | goto (0.25,0.5) with the brush UP |
| `X75000Y50000D01*` | goto (0.75,0.5) with the brush DOWN |
| `D11*` | switch brushes |
| `X25000Y25000D03*` | At (0.25, 0.25) stamp something that looks like brush D11 |
| `Y75000D03*` | At (0.25, 0.75) stamp something that looks like brush D11 (no change in X) could have done the square like this, I think.|
| `X75000D03*` | At (0.75, 0.75) stamp something that looks like brush D11 (no change in Y) |
| `Y25000D03*` | At (0.75, 0.25) stamp something that looks like brush D11 (no change in X) |
| `D12*` | switch brushes |
| `X50000Y50000D03*` | stamp an octagon in the middle (0.5, 0.5) |
| `M02*` | End of File | 





