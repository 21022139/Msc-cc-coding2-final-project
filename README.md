# 21/22 Coding Two: Advanced Frameworks
####Final project description
####Yansong Wang
####21022139

![Screenshot 2022-03-15 at 13 52 11](https://user-images.githubusercontent.com/92035097/158420937-d8a918dc-e951-4105-a894-d52a7788e370.jpg)

Imagine your computer becoming your instrument, with keys on the keyboard generating all sorts of notes - a completely new experience from traditional instruments. 
I also generated a spectrum of sounds, drawing rectangles and circles around the screen, and each person can generate different visuals through their compositions.

To begin with, I loaded two types of musical material, guitar and saxophone. To make my graphics change to the rhythm of the music, I used ofSoundGetSpectrum, 
which reads the frequency spectrum of a piece of audio, in other words, it makes the graphics I create change according to the frequency of the music. 
I then set a set of variables bandsToGet, set it to 512 bands and asked ofSoundGetSpectrum to get the value of each band. Using these values, 
I drew a set of rectangles and, using ofRotateRade, rotated it around to create what looked like a ray emitted at the midpoint of the screen. 
Using the same method, I drew two sets of circles whose radius would change through the total bandsToGet and whose position would change through time, 
these dynamic circles resembling musical notes bouncing around the screen. As for the colour part, I set the HSB colour and let the colour change according 
to the value of bandsToGet. I then set the keyboard keys, '1-9' to load different sound effects, 's' and 'g' to load the sax and guitar sound banks respectively.

So far all I have been able to achieve is to switch between the guitar and saxophone instruments. Since the two instruments have different ranges, 
they will derive different visuals. But if I could continue with this project, I wonder if I could add a recording function to record the music created 
by each person who experiences it and download it. If it was possible, it would be a more meaningful experience. Also, if possible, I would like to try 
to change the visuals produced by the music, so that the graphics fit the melody of the music better than just simple radiating rays.

