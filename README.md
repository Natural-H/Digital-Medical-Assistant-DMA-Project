# Digital Medical Assistant (DMA) Project
This is just a project

--To do:--

# Previous Requierements
- [Arduino IDE](https://www.arduino.cc/en/software) installed.
- [RF24](https://www.arduino.cc/reference/en/libraries/rf24/) and [Vector](https://www.arduino.cc/reference/en/libraries/vector/) libraries for Arduino IDE installed.

# Seeing the source code in a Code Editor

## Aditional Requierements:
- One of these Code Editors:

  - [Visual Studio Code.](https://code.visualstudio.com/)

> Later I will add more Code Editors.

## Visual Studio Code:

- Open a new window of Visual Studio Code.
- Then install the necessary extensions to use Arduino IDE in Visual Studio Code:

![image](https://user-images.githubusercontent.com/76983239/124502708-93829a00-dd89-11eb-83f1-9467d40812d2.png)

  - [C++ Extension.](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Arduino Extension.](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino)

- The next thing to do is clone this repository:

```shell
git clone https://github.com/Natural-H/Digital-Medical-Assistant-DMA-Project.git
```
Or you can download the code [here](https://github.com/Natural-H/Digital-Medical-Assistant-DMA-Project/archive/refs/heads/main.zip):

![image](https://user-images.githubusercontent.com/76983239/124518150-5a5b2180-ddab-11eb-9524-ad0d3c79e000.png)

Don't forget to unzip it.

- Open the folder __Digital-Medical-Assistant-DMA-Project__ in Visual Studio Code.
- Click in __DMA_Source__ and select __DMA_Source.ino__.

**Note that Visual Studio Code perhaps will show you a few erros, ignore them for now.**

![image](https://user-images.githubusercontent.com/76983239/124519326-9348c580-ddae-11eb-9182-48d46a7e92d6.png)

- Now press: _Ctrl + Alt + R_, _CMD + Alt + R_ or click the _"Verify"_ button:

![image](https://user-images.githubusercontent.com/76983239/124505890-1e669300-dd90-11eb-941d-b1e9a4bd4db3.png)

- You must get the next output or something similar:

![image](https://user-images.githubusercontent.com/76983239/124505964-448c3300-dd90-11eb-8f52-0c03d82a3df7.png)

Now you can explore the soruce code, I will very be grateful if you leave a opinion of this, or create a Pull Request if you like.


# Seeing the source code in Arduino IDE (Not Recommended)

I personally don't recommend see the soruce code at this way, due certains Arduino IDE behaviors.

- First, you need to clone the repository using:
```shell
git clone https://github.com/Natural-H/Digital-Medical-Assistant-DMA-Project.git
```

Or download the source code [here](https://github.com/Natural-H/Digital-Medical-Assistant-DMA-Project/archive/refs/heads/main.zip):

![image](https://user-images.githubusercontent.com/76983239/124518159-5e873f00-ddab-11eb-9286-d7f5dd2bdbe9.png)

Don't forget to unzip it.

- Then, open a new window of Arduino IDE, and press _Ctrl + O (CMD + O on Mac)_ or click on _"File > Open..."_:

![image](https://user-images.githubusercontent.com/76983239/124519514-2550ce00-ddaf-11eb-908c-a42bbcb483de.png)

- Got to __Digital-Medical-Assistant-DMA-Project__ folder, in __DMA_Source__ select __DMA_Source.ino__ and a new window of Arduino IDE will open.
- To see the rest of the source code, click on _"Sketch > Add File..."_:

![image](https://user-images.githubusercontent.com/76983239/124519799-0bfc5180-ddb0-11eb-8cb9-82893538b592.png)

- Then, select the file that you want to see.

![image](https://user-images.githubusercontent.com/76983239/124519872-4665ee80-ddb0-11eb-8a6a-b94405ca0c3a.png)

- Although, do this can be very annoying and verify the sketch with added files will cause the files to be imported out of the folder and an error verifying of:
> "No such file or directory"
