# # Only to be used on terminals. A bunch of the main features were taken from Hwinfo lib. [![Lib](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/lfreist/hwinfo)

Build:

- create a temporary enviroment path:
  ```sh
  export LD_LIBRARY_PATH="$(pwd)/lib:$LD_LIBRARY_PATH"
  ```

- execute .sh:
  ```sh
  sh build.sh / bash build.sh
  ```
  
  if you are skeptical, you can analyze .sh for yourself or compile yourself using this command on your terminal:
  
  ```sh
  g++ main.cpp -o macfetch -std=c++23 -I./include/ -L./lib -lhwinfo_mainboard -lhwinfo_cpu -lhwinfo_ram -lhwinfo_disk -lhwinfo_gpu -lhwinfo_network -lhwinfo_os -lhwinfo_battery
  ```
### and done!

The code is very rubbish, it will be fixed in the future(but who knows when).
