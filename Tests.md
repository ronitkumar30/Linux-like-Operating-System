# Testing Strategy

## Unit Tests
We ensured all core OS components were tested independently. Key unit tests include:
- **Paging:** verified that all virtual-to-physical address mappings work as expected
- **IDT:** Confirmed interrupts are correctly routed, and handlers are invoked properly
- **File System:** Validated that files are correctly read from read-only file system image

## Integration Tests
For overall system behavior, we tested:
- Booting with paging and executing a simple shell
- Receiving keyboard input and processing RTC interrupts
