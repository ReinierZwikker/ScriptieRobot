//WIP


//std::String recvRF() {
//  uint8_t buf[12];
//  uint8_t buflen = sizeof(buf);
//  if (driver.recv(buf, &buflen)) {
//    return (char*)buf);
//  }
//}


//void waitRF(String message) {
//  uint8_t buf[12];
//  uint8_t buflen = sizeof(buf);
//  while (!driver.recv(buf, &buflen) && !((char*)buf == message)) {
//    //do nothing.
//  }
//}
//
//void sendRF(String message) {
//  const char *msg = message;
//  driver.send((uint8_t *)msg, strlen(msg));
//  driver.waitPacketSent();
//  delay(1000);
//}
