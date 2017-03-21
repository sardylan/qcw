#ifndef __QCW_CONFIG_DEFAULT_H
#define __QCW_CONFIG_DEFAULT_H

#if defined(Q_OS_WIN)
#define CONFIG_PORTNAME_DEFAULT "COM3"
#else
#define CONFIG_PORTNAME_DEFAULT "/dev/ttyACM0"
#endif

#define CONFIG_PORTSPEED_DEFAULT QSerialPort::Baud115200

#endif
