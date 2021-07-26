Pre-requisite, run make menuconfig and save.

Able to perform the same with coreinfo and compile other libpayload based payload

Steps:

1. In this directory, run "make"

2. Run "./movefile.sh"

3. Run "cd ../.." then "make menuconfig", go to "Payload -> Payload Path and Filename", modify it to "micropython.elf", go to "Payload -> Add a payload", modify it to "An ELF executable payload". Exit, save.

4. Run "make"

5. Run "./runqemu.sh"

6. You should see "hello Micropython. Arithmetic operations: 100+200 = 300, 12*12 = 144" in QEMU serial log.
