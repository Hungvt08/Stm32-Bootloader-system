\# STM32 Custom Bootloader



A custom STM32 bootloader project with two independent applications.



The bootloader selects which application to run based on button state during startup.



\## Features

\- Custom bootloader

\- Multi-application support

\- Flash memory partitioning

\- VTOR remapping

\- Register-level programming

\- Application jumping



\## Flash Layout



| Firmware | Flash Sector | Address |

|----------|--------------|----------|

| Bootloader | Sector 0 | 0x08000000 |

| Application1 | Sector 1 | 0x08004000 |

| Application2 | Sector 2 | 0x08008000 |



\## Boot Flow



\- Button pressed → Run Application1

\- Button released → Run Application2



\## Technologies

\- STM32F411VE

\- Embedded C

\- STM32CubeIDE

\- ARM Cortex-M4

