#define T_DIR 1  // Directory
#define T_FILE 2 // File
#define T_DEV 3  // Device

struct uproc
{
  char *name;  // name of the process
  int pid;     // process id
  int ppid;    // parent process id
  int size;    // size of process
  int state;   // process state
  int channel; // waiting on a channel
  int killed;  // if process is killed
};

struct stat
{
  short type;  // Type of file
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short nlink; // Number of links to file
  uint size;   // Size of file in bytes
};