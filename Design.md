# Design Decisions

## Memory Management
We implemented 4 MB paging for kernel memory and 4 KB paging for user-level processes. This choice was driven by the need to map kernel and video memory in a way that's efficient yet simple.

## Interrupt Handling
Our OS includes keyboard and RTC interrupt handling. The IDT is used to manage interrupt vectors, while device drivers for keyboard and RTC handle actual processing of interrupts. This design provides a modular way to handle interrupt sources without complicating the kernel.
