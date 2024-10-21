
// sleep
#include <unistd.h>
// printf
#include <stdio.h>
// uintxx_t
#include <stdint.h>
#include <SocketCAN.h>
// #include <SLCAN.h>


void rx_handler(can_frame_t* frame, void* context)
{
    // TODO: Do something here with the received frame
}


void test_socketcan()
{
    printf("\nTesting SocketCAN adapter\n");
    printf("#############################\n");

    SocketCAN* adapter = new SocketCAN();
    adapter->open("vcan0");

    adapter->reception_handler = &rx_handler;

    sleep(3);

    can_frame_t frame;
    frame.can_id = 0x123;
    frame.can_dlc = 3;
    frame.data[0] = 1;
    frame.data[1] = 2;
    frame.data[2] = 3;
    adapter->transmit(&frame);

    delete adapter;
    sleep(1.1);
}


int main()
{
    test_socketcan();
    return 0;
}
