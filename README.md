# ascii-maze-solver
A maze solver written to find a path through mazes whose borders are represented by ASCII characters.

# Maze Key

In the form: *top right bottom left*

'0': none none none none<br>
'1': none solid none none<br>
'2': none none solid none<br>
'3': none solid solid none<br>
'4': none none none solid<br>
'5': none solid none solid<br>
'6': none none solid solid<br>
'7': none solid solid solid<br>
'8': solid none none none<br>
'9': solid solid none none<br>
'a': solid none solid none<br>
'b': solid solid solid none<br>
'c': solid none none solid<br>
'd': solid solid none solid<br>
'e': solid none solid solid<br>
'f': solid solid solid solid<br>


So, a simple maze would be: <br>

  *aa9*<br>
  *cb5*<br>
  *6a2*<br>


And can be seen at the [Cabrillo College CS21 Maze Viewer](https://jeff.cis.cabrillo.edu/tools/cs21_maze_viewer)
