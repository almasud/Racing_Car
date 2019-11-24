## Steps to include graphics.h in Code::Blocks:

#### Step 1: Download of Code::Blocks (latest) and install it. 

#### Step 2: Now, download [winBGIm](https://raw.githubusercontent.com/almasud/Racing_Car/master/WinBGIm_Graphics_Libraries.rar) graphics library

#### Step 3: Extract the file and you'll get these files:
```
graphics.h
winbgim.h
libbgi.a
```

If you have Code::Blocks installed in C drive of your computer, go through:
Drive ```C > Program files or Program files(x86) > CodeBlocks > MinGW```
#### Step 4: Copy and paste ```graphics.h``` and ```winbgim.h``` files into the ```include``` folder of your compiler directory.

#### Step 5: Copy and paste ```libbgi.a``` to the ```lib``` folder of your compiler directory. Same path as above.

#### Step 6: Now, open Code::Blocks. Go to ```Settings > Compiler > Linker settings```

#### Step 7: In that window, click the ```Add``` button under the ```Link libraries``` part, and browse and select the ```libbgi.a``` file copied to the lib folder in Step 5.

![Step 7](https://github.com/almasud/Racing_Car/blob/master/Step%207.jpg)

#### Step 8: Go to ```Other linker option``` on the right part of same window and paste these commands:
```
-lbgi 
-lgdi32 
-lcomdlg32 
-luuid 
-loleaut32 
-lole32
```

![Step 7](https://github.com/almasud/Racing_Car/blob/master/Step%208.jpg)

#### Step 9: Make sure you got Steps 7 and 8 right!

### Watch output on YouTube:
[![Racing Car Image](https://github.com/almasud/Racing_Car/blob/master/screenshot.jpg)](https://youtu.be/jOWOaJvT8As)


##### Thank you all and happy codding... 
[Abdullah Almasud](https://facebook.com/almasud.arm)
