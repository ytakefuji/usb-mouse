#include "hidboot.h"
#include "usbhub.h"
#include <SPI.h>

class MouseRptParser : public MouseReportParser
{
protected:
  void OnWheelMove (MOUSEINFO *mi);
};

void MouseRptParser::OnWheelMove (MOUSEINFO *mi)  
{
    Serial.println(mi->dZ, DEC);
};

USB     Usb;
USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_MOUSE>    HidMouse(&Usb);

uint32_t next_time;

MouseRptParser Prs;

void setup()
{
    Serial.begin( 115200 );
    Serial.println("Start");

    if (Usb.Init() == -1)
        Serial.println("OSC did not start.");

    delay( 200 );

    next_time = millis() + 5000;

    HidMouse.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
}
