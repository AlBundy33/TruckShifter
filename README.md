# DIY real truck shifter

Because I'm playng Eurotruck Simulator 2 with my T300 + TH8A I wanted to have a shifter that has buttons for range and splitter.

Because I didn't want to spent over 100EUR for a simple gear stick with two or three buttons I decided to bought a cheap MAN shifter (81326200043) from china (in fact something about 16EUR on Amazon).

After that I've used my multimeter to find out the connections between the pins on the socket.

<del>Next step is to write the program and find out how to mount the shifter knob on my TH8A because the TH8A uses an M8 thread where the shifter provides an M12 thread.</del>

<del>Therefore I bought an M8 to M12 adapter on Amazon (not arrived yet) for 5EUR (maybe a litte bit expensive for a single adapter).</del>

Next step is to write the program and find out how to mount the shifter knob on my TH8A because the TH8A uses an M9x1.25 thread where the shifter provides an M14x1.5 thread.
If you have a 3D printer you can try this thing: https://www.thingiverse.com/thing:4827444

# Pinout

This is my numbering according to the colors on the plug.
```
0 (black)   1 (blue)    2 (two wires, green/yellow)
3 (purple)  4 (red)     5 (white)
```

an this seems to be the connections between the pins
- range (front): 4 + 5
- splitter (side): 2 + 3
- comfort shift (top): 0 + 2 (normally closed), 1 + 2 (normally open), 1 + 3 (normally open, only if splitter is closed), 0 + 3 (normally closed, if splitter is closed)

so i think the wiring could be done like this.
```
4 + 2 -> GND
1 -> PIN0
3 -> PIN1
5 -> PIN2
```

Because I need only three buttons I think that I'll us a digispark for this project.
