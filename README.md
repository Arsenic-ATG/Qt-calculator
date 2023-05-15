# Qt-calculator
## Introduction
Welcome to the Qt-calculator project!</br>
As the name suggests , We build a calculator with variety of commonly used functions,interacted by gui.</br>
We use the Qt creator ide to setup the project, due to its excellent internal build tools , especially for gui. </br>
The calculator can be used on all platforms(altough the gui may differ on each platform).</br>



### requirements ✅
**Qt creator** or **Qmake** build system set up in your IDE

### Setting up Qt 💻
* Start by installing the Qt SDK from [qt.io](https://www.qt.io/download). Since the online installers can be pretty buggy ,it was decided to go with the offline Open Source version
* The installer does not include any compailer on its default install.Make sure you select the fitting mingw compailer.
* As mentioned above,Qt Creator is a sort of an IDE with internal build tools. So currently, it's a good idea to install this.
* We will not be using CMake since QMake comes bundled with the creator

## Contributing
The calculator is evolving each day, and yet there are always new features to implement , code to optimize , or documentation to add.
For this very reason , contributers(completely new ones or veterans) are more then welcome to make the changes.
If you wish to contribute,please read [CONTRIBUTING.md](https://github.com/Arsenic-ATG/Qt-calculator/blob/master/CONTRIBUTING.md) for details on the code of conduct and process for submitting pull requests to the repo.

### Get it running 🏃‍♂️
1. clone/download the repository

1. Open ```QtCalculator => calculator.pro``` using Qt creator.If you havent downloaded qt creator, go back to the ***Setting up Qt 💻*** section

1. Once inside Qt creator click on ```configure Project``` options (it will configure the project according to your device) 👇
![main screen](https://github.com/Arsenic-ATG/Qt-calculator/blob/master/screenshots/instructions.png)

### Publishing the changes 🔧
Before making the needed changes , follow these instructions(if you are familiar with github and its source control functions, you can skip this explanation)
1. Fork the repository(the button on the top-right of the page)
1. Create a new branch on the created fork(meaningful branch names are importent)
1. Make the needed changes on this branch
1. commit the changes to the branch.Right now they are saved on your local repository
    - make sure you summarize the changes you made , on the commit description
1. push it to the online repository
1. Create a pull request , on which your changes from the branch commits are explained more deeply
1. your changes will be reviewed by the project maintainers.
1. Congratulations 🎉 , you made your first contribution to the project!



---
## screen shots 📸
```
- These screen shots were taken on Windows 10 OS, result might vary according to your Operating System
```
### calculator themes:
![light mode screenshot](https://user-images.githubusercontent.com/94454456/228864882-e7d9558a-facc-4e7d-a48a-4c5c1f2912af.png)
![dark mode screenshot](https://user-images.githubusercontent.com/94454456/228865275-a596d267-f213-4a11-8d17-0c17a3bfcc73.png)

### unary functions:

![Sqrt](https://user-images.githubusercontent.com/94454456/228865918-667add86-f5f8-4e82-bbab-e930266c6032.png)
![Log_error](https://user-images.githubusercontent.com/94454456/228866137-8bead345-6ff9-491d-8706-15aafa1149fe.png)
![sin_on_degrees](https://user-images.githubusercontent.com/94454456/228866445-40649182-6ea9-460a-9f0b-30cc1d013c47.png)
![factorial](https://user-images.githubusercontent.com/94454456/228867444-c633ceb5-5930-4178-b28e-2736eea29657.png)


### binary functions
![divide](https://user-images.githubusercontent.com/94454456/228867052-22f27aed-c21a-479c-b4ed-8f7e7d3dcd9a.png)
![multiply](https://user-images.githubusercontent.com/94454456/228867254-3ff3cbe9-e2a3-4119-b0e8-72853d9da059.png)


## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2020 © <a href="https://github.com/Arsenic-ATG" target="_blank">Ankur Saini</a>.
