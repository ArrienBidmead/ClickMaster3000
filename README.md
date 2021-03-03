<img align="left" src="DevOnlyImages/CM3000Icon.png" width="100px"/>
<h1>ClickMaster 3000 v2</h1>
<a href="https://arrien.co.uk/ClickMaster3000.html">Arrien.co.uk/ClickMaster3000</a>
<br><br>

The ClickMaster 3000 is a graphically rich program made with C++ and SFML to aid in the playing of the popular game Cookie Clicker. This simple program when engaged will automatically click the mouse very rapidly (auto clicker) which allows the user to simply leave their mouse over the cookie and let the points roll in.
<br><br>

![preview](DevOnlyImages/ProgramPicture.png "Preview")

# Usage
1. Arm the clicker by pressing the power button.
2. Set the CPS (clicks per second) to what you want.
3. Toggle “Capslock” to engage/ disengage clicker.

# Developer Stuff

## TODO

- Optimise so that buttons won't get polled if mouse isn't over window.

## Suggestions

- Make buttons array a binary tree so I can automatically optimise not updating buttons if parent button isn't being hovered over
