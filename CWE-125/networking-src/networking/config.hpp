namespace networking::config
{
constexpr char SERVER_IP_ADDR[] = "127.0.0.1";
constexpr int SERVER_PORT = 5003;
// in bytes / chars
// the first 5 bytes + '\0' contain the size of the message that is being transfered
constexpr int MESSAGE_HEADER_SIZE = 6;

}  // namespace networking::config
