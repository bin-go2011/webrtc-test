#include <string>
#include "webrtc/tools/simple_command_line_parser.h"
#include "data_socket.h"

int main(int argc, char** argv) {
  std::string program_name = argv[0];
  std::string usage = "Example usage: " + program_name + " --port=8888";
  webrtc::test::CommandLineParser parser;
  parser.Init(argc, argv);
  parser.SetUsageMessage(usage);
  parser.SetFlag("port", "8888");
  parser.SetFlag("help", "false");
  parser.ProcessFlags();

  if (parser.GetFlag("help") == "true") {
    parser.PrintUsageMessage();
    return 0;
  }

  int port = strtol((parser.GetFlag("port")).c_str(), NULL, 10);

  // Abort if the user specifies a port that is outside the allowed
  // range [1, 65535].
  if ((port < 1) || (port > 65535)) {
    printf("Error: %i is not a valid port.\n", port);
    return -1;
  }

  ListeningSocket listener;
  if (!listener.Create()) {
    printf("Failed to create server socket\n");
    return -1;
  } else if (!listener.Listen(port)) {
    printf("Failed to listen on server socket\n");
    return -1;
  }

  printf("Server listening on port %i\n", port);

}