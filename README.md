# Self-linker

Middlebury College CS315 Systems Programming- Fall 2018: This assignment implements its own runtime linking. The executable will be a program that, when run, will call a function in libc that does not cause the official linker to run. This call is preceded by code that obviates the need to call the official linker (by examining addresses within the GOT and hardcodes memory addresses as necessary). 

* **Calder Birdsey** - *Initial work* - [c-birdsey](https://github.com/c-birdsey)

See also the list of [contributors](https://github.com/c-birdsey/io-syscalls/contributors) who participated in this project.

## Acknowledgments

* Professor Pete C. Johnson

## Sources: 
https://reverseengineering.stackexchange.com/questions/16677/why-does-my-shellcode-work-in-gdb-but-not-on-the-command-line
http://pubs.opengroup.org/onlinepubs/009695399/functions/dlsym.html
https://www.binaryhexconverter.com/hex-to-decimal-converter
