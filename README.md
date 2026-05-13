# Personal Notes (old 3ds support)

Thanks to the incredible work of the OoT3D and Nintendo 3DS homebrew community, I was able to create a game patch that enables input support for the Circle Pad Pro, making it compatible with a game that does not originally support this accessory.

I reused code from [Skyfloogle](https://github.com/skyfloogle/red-viper/blob/master/source/3ds/cpp.c) to handle Circle Pad Pro inputs and integrated it into this [patch](https://github.com/Roberto-Nessy/OoT3D_Standalone_Free_Cam). But, I adapted the implementation to allocate the thread stack statically instead of dynamically.

I hope this is just the beginning, and that it will lead to more patches for other games in the future, helping expand the list of titles compatible with the Circle Pad Pro.

I also recently improved the patch to make it accessible to players who do not have a second analog stick, by adding support for the D-pad and the touchscreen.

### Demo: click to see the full video
[![Demo](demoCPP.gif)](https://www.youtube.com/watch?v=Ai_3MEJ3sHk)

# OoT3D Free Cam
This project allows 3DS(old and new) systems and Citra to control the camera in The Legend of Zelda: Ocarina of Time 3D with use of the c-stick or the Circle Pad Pro, just like Majora's Mask 3D or with the Dpad and the touchscreen. 

This project still lacks several features that may be added in the future.

* Further version support (KOR/TWN)
* Improved UI & retained settings
* Improved collision checks
* ZR/ZL/R support on CPP and c-stick
* free camera when riding epona

# Shoutouts
* Shoutouts to [Skyfloogle](https://github.com/skyfloogle/red-viper/blob/master/source/3ds/cpp.c) that made Circle Pad Pro implementation possible. 
* Shoutouts to [Roberto Nessy](https://github.com/Roberto-Nessy) who is the original developer of this patch and who made the shoutouts below.
* Shoutouts to [gamestabled](https://github.com/gamestabled) for creating the practice patch and randomizer projects this shamelessly steals from
  * By extension, shoutouts to anyone gamestabled shouts out in those projects
* Shoutouts to the OoT decomp team for creating an invaluable resource I referenced heavily while creating this
* Shoutouts to Ura Yukimitsu for showing me how to get c-stick input working
* Shoutouts to Hylian Freddy for creating the practice patch's memory viewer, another fantastic resource
* Shoutouts to Kestron for motivating me to create the original free cam
* Shoutouts to Skilar for getting me to make it a standalone project
* Shoutouts to the whole OoT3DR dev team for being cool people and the community for keeping me motivated

# How to Use:
* Find the patch files inside the "Patch Files" folder in this repository. They're divided by regional version of OoT3D (USA/EUR/JP) and by platform (3DS/Citra), so choose the correct ones.

##### 7 versions are available based on 3 features :
- rightstick : Circle Pad Pro on old 3ds | C-Stick on new 3ds
- dpad
- touchscreen

> [!CAUTION]
> Do not choose a rightstick patch if you are using an Old 3DS without a Circle Pad Pro, as it may cause audio crackling due to infrared interference. 

### 3DS
* Install a recent build of Luma3DS. If you already have Luma3DS, you can upgrade by simply replacing ```boot.firm``` at the root of your SD card.
* Take the correct ```exheader.bin``` file depending on your game version. e.g: ```/Patch Files/USA/3DS/exheader.bin```
* Take the ```code.ips``` file with the features you want from the subfolders. e.g: ```/Patch Files/USA/3DS/all/code.ips```
* Place these patch files ("code.ips" and "exheader.bin") in the following folder (you may need to create the folder):

| Version | Location |
|---|---|
| USA | /luma/titles/0004000000033500 |
| JP  | /luma/titles/0004000000033400 |
| EUR | /luma/titles/0004000000033600 |

* Hold Select while powering on the console to launch the Luma3DS menu. Turn on "Enable game patching". You should only need to do this once, unless if you disable game patching in the future.
* It should work now! If not, you likely need to use a different version of Luma3DS.

### Citra Emulator
* Right-click on OoT3D from the game list and select "Open Mods Location". Place the patch files ("code.ips" and "exheader.bin") there.

### In Game Controls
The free camera's settings can be adjusted with the following button combinations:

* **L + R + DPad Up/Down** = Increase/Decrease Sensitivity
* **L + R + DPad Left/Right** = Invert Axes (Neither, Just X, Just Y, Both)

The selected setting will be displayed on the top screen in the upper left briefly after selecting it.

#### With Circle Pad Pro

Press ZR to connect the Circle Pad Pro to the 3DS, and make sure it has enough battery power.

> [!WARNING]
> The game's audio may crackle when the Circle Pad Pro is not connected due to infrared interference.
> To avoid that, Press **L + R + Select** to disable Circle Pad Pro support when it is not in use.

# Build

Use the ```makeAll.sh``` script to build all the patches: ```sh makeAll.sh```.
You can specify a region (EUR, JP, USA): ```sh makeAll.sh USA```.