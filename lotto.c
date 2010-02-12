#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid, tickets;

  if(argc != 3){
    printf(1 ,"usage: lotto PID [-]tickets\n");
    exit();
  }
  pid = atoi(argv[1]);
  if(pid <= 0){
    printf(1, "PID must be number greater than 0\n");
    exit();
  }
  
  if(argv[2][0] == '-'){
    argv[2][0] = '0';
    tickets = -(atoi(argv[2]));
  }
  else    
    tickets = atoi(argv[2]);

  if(tickets <= 0){
    printf(1, "tickets must be a non zero number\n");
    exit();
  }
  
  if(lotto(pid, tickets))
    printf(1, "lotto failed!\n");

  exit();
}
