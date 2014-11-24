#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream> 
#include <string>

int main ( int argc, int argv[] )
{
std::string message;
  try
    {

      ClientSocket client_socket ( "localhost", 44444 );

      std::string reply;
while(1) {
      try
	{
          std::cout << "Input message: ";
          std::getline(std::cin, message);
          if(message == "exit"){ break;}
	  client_socket << message;
	  client_socket >> reply;
	}
      catch ( SocketException& ) {}

      std::cout << "Received this request from server:\n\"" << reply << "\"\n";;
}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}
