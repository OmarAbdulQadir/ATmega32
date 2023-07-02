# ATmega32
Apps and Drivers for ATmega32 microcontroller. This was made for educational purposes. Reporting any test results, comments, or bugs will be appreciated.

This Repo consists of four main folder types:
  1. LIB: Folder that contains the vertical layer's files (standard libraries), There is only one "LIB" folder.
  2. Drivers: Folder that contains the horizontal layers' files (microcontroller drivers), and there is only one "Drivers" folder.
       * The "Drivers" folder contains two separate folders one for each layer (MCAL, HAL), To use any driver it must be included
         in the make file either manually or through your SDK.
  4. APP_x_app-name: App folder that contains the main app and its generated files from the build process, and there is a folder for each project.
  5. APP_x_app-name_SIM: Simulation folder contains simulation files created with proteus simulation.

At last, there is a file called Template_prog containing template main and template make file for manual use (without SDK).
