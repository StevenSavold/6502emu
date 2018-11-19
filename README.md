# 6502emu
## Description
A project to design an emulator for the 6502 CPU

We are planing on making the emulator compile into a shared object
file so it can be linked with other larger projects to allow for 
fast easy emulation of this iconic CPU.

## Why another emulator?
For education and fun.

We are designing this project with our education in mind. All contributors
to this project are students at SUNY Polyechnic Institute in Utica, NY. We
are trying to furthur our understanding of computer architechure and low 
level hardware nuances that can contribute to faster more reliable code.


This Family of CPUs powered machines like:
 - Apple II
 - Nintendo Entertainment System (NES)
 - Commodore PET
 - BBC Micro
 - Atari 800 and 2600
 - Commodore 64
 - and many more

## Planned Emulator Features 
(NOTE: Currently implemented features have a check mark)
- [ ] Well documented and easy to read code
- [ ] Full simulation of circutry inside the CPU
- [x] Portable code in the form of a shared library
- [ ] Multiple chip support
- [ ] Periferal support
- [ ] Concurrent emulation of multiple chips
- [ ] 6502 assembler
- [ ] and more...

## How to build
Our code uses [Premake](https://github.com/premake/premake-core) as our build system. Premake is a lua based build script generator. Our perticular script is set up to generate Visual Studio 2017 project files, XCode project files, and a Makefile. To generate any of these files simply run the batch/shell script for the corresponding files you wish to generate. For example, to generate Visual Studio 2017 project files, run the 'CreateBuild-vs2017.bat' file. 

To learn more about Premake and how to use it, please visit the [Premake wiki page](https://github.com/premake/premake-core/wiki).

## Useful Links and References
- [Online 6502 Emulator](http://visual6502.org/JSSim/expert.html)
- [MiniAT Home Page](http://miniat.org/)
- [6502 Instruction Set](http://www.llx.com/~nparker/a2/opcodes.html)
