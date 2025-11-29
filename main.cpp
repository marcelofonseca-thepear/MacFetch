#include <print>
#include <fstream>
#include <string>
#include <vector>
#include "include/hwinfo.h"
#include "include/utils/unit.h"

const char* _0 = "\033[0m";
const char* _1 = "\033[34m"; 
const char* _B = "\033[37m";

using hwinfo::unit::bytes_to_MiB;

double convert_to_GB(size_t bytes){
  double gigabyte = (double)bytes / (1024 * 1024 * 1024);
  return gigabyte;
}

int get_used_percentage(size_t total, size_t available){
  int result = ((double)available * 100) / (double)total;
  return result;
}

int main(int argc, char** argv) {
  auto cpus = hwinfo::getAllCPUs();
  auto gpus = hwinfo::getAllGPUs();
  auto disks = hwinfo::getAllDisks();

  hwinfo::MainBoard main_board;
  hwinfo::Memory memory;
  hwinfo::OS os;

  std::string lines = "";
  std::ifstream pearOS ("./include/pearto.txt");

  while(std::getline(pearOS, lines)) std::println("{} {} {}", _B, lines, _0);

  /*===============================SYSTEM===============================================*/
  std::println("{}OS:{} {} {}", _1, _0, os.name(), os.is32bit() ? "x32" : "x86_64"); 
  std::println("{}Kernel:{} {}", _1, _0, os.kernel());
  std::println("{}Motherboard:{} {}", _1, _0, main_board.name());
  /*====================================================================================*/

  /*===============================CPUS=================================================*/
  for (const auto& cpu : cpus){
   static char i{'0'}; 
   if(cpus.size() < 2) i = '\0';

   ++i;
   std::println("{}CPU{}:{} {} ", _1, i, _0, cpu.modelName());
  }
  /*====================================================================================*/

  /*===============================GPUS=================================================*/
  for (const auto& gpu : gpus){
   static char i{'0'}; 
   if(gpus.size() < 2) i = '\0';

   ++i;
   std::println("{}GPU{}:{} {} ", _1, i, _0, gpu.name());
  }
  /*=====================================================================================*/

  /*===============================DISKS=================================================*/
  std::println("{}Disks: {}", _1, _0);
  for (const auto& disk : disks){
   static int i{0};
   i++;
    std::println(" {}# {} / size: {:.2f} GiB", i, disk.model(), convert_to_GB(disk.size_Bytes()));
  }
  /*=====================================================================================*/

  /*===============================MEMORY================================================*/
  std::println("{}Memory:{} total: {:.2f} GiB / available: {:.2f} GiB({}% used)\n\n",  _1, _0, 
                                                                 convert_to_GB(memory.total_Bytes()),
                                                                 convert_to_GB(memory.available_Bytes()),
                                                                 get_used_percentage(memory.total_Bytes(), memory.available_Bytes()));
  /*=====================================================================================*/

  return 0;
}
   



