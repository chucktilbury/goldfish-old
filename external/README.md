# External Libraries

These are files are are generated from sources other than GoldFish. To build this on a platform other than Linux, you will need to get these libraries and build them for yourself. Instructions below.

## libgc.a and libcord.a

These are the garbage collection and associated string handling libraries. To generate them, do a ```git clone https://github.com/ivmai/bdwgc.git``` and follow the instructions in the README.md file. For more information, look here: https://en.wikipedia.org/wiki/Boehm_garbage_collector and/or here: https://www.hboehm.info/gc/