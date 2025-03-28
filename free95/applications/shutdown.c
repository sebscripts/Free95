/*++

Free95

You may only use this code if you agree to the terms of the Free95 Source Code License agreement (GNU GPL v3) (see LICENSE).
If you do not agree to the terms, do not use the code.


	PROJECT: Free95 Userspace Components
	FILE: shutdown.c
	DESCRIPTION: A Native NT Application To Shutdown The System.
	AUTHOR: @KapTheGuy

--*/

typedef enum _SHUTDOWN_ACTION
{
    ShutdownNoReboot,
    ShutdownReboot,
    ShutdownPowerOff
} SHUTDOWN_ACTION, *PSHUTDOWN_ACTION;

void _start()
{
    const unsigned long syscall_number = 0x00b4;
    const unsigned long shutdown_action = ShutdownPowerOff;
    int status;

    __asm__ __volatile__(
        "mov %1, %%eax\n"  // Load syscall number into EAX
        "mov %2, %%ebx\n"  // Load shutdown action into EBX
        "int $0x2e\n"      // Trigger interrupt 0x2e
        "mov %%eax, %0\n"  // Store the return status in 'status'
        : "=r"(status)     // Output operand
        : "r"(syscall_number), "r"(shutdown_action) // Input operands
        : "eax", "ebx"     // Clobbered registers
    );
}
