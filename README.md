# OoT3D Free Cam
This project allows new 3DS systems and Citra to control the camera in The Legend of Zelda: Ocarina of Time 3D with use of the c-stick, just like Majora's Mask 3D.

This project is still a WIP with the following planned features:

* JP version support (although the patch files are there they will currently crash as soon as you enter free cam)

# Shoutouts
* Shoutouts to gamestabled for creating the practice patch and randomizer projects this shamelessly steals from
  * By extension, shoutouts to anyone gamestabled shouts out in those projects
* Shoutouts to the OoT decomp team for creating an invaluable resource I referenced heavily while creating this
* Shoutouts to Ura Yukimitsu for showing me how to get c-stick input working
* Shoutouts to Hylian Freddy for creating the practice patch's memory viewer, another fantastic resource
* Shoutouts to Kestron for motivating me to create the original free cam
* Shoutouts to Skilar for getting me to make it a standalone project
* Shoutouts to the whole OoT3DR dev team for being cool people and the community for keeping me motivated

# How to Use:
* Find the patch files inside the "Patch Files" folder in this repository. They're divided by regional version of OoT3D (USA/EUR/JP) and by platform (3DS/Citra), so choose the correct ones.
### 3DS
* Install a recent build of Luma3DS. If you already have Luma3DS, you can upgrade by simply replacing "boot.firm" at the root of your SD card.
* Place the patch files ("code.ips" and "exheader.bin") in the following folder (you may need to create the folder):

| Version | Location | Notes |
|---|---|---|
| USA | /luma/titles/0004000000033500 | |
| JP  | /luma/titles/0004000000033400 | WIP - will crash |
| EUR | /luma/titles/0004000000033600 | |

* Hold Select while powering on the console to launch the Luma3DS menu. Turn on "Enable game patching". You should only need to do this once, unless if you disable game patching in the future.
* It should work now! If not, you likely need to use a different version of Luma3DS.

### Citra Emulator
* Right-click on OoT3D from the game list and select "Open Mods Location". Place the patch files ("code.ips" and "exheader.bin") there.

### In Game Controls
The free camera's settings can be adjusted with the following button combinations:

* L + R + DPad Up/Down = Increase/Decrease Sensitivity
* L + R + DPad Left/Right = Invert Axes (Neither, Just X, Just Y, Both)

The selected setting will be displayed on the top screen in the upper left briefly after selecting it.
