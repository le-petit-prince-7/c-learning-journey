#include <stdio.h>      // For FILE, fopen, fprintf, fscanf, fgets, fclose

// ========================================
// FILE I/O DEMO - FOR COMPLETE BEGINNERS
// ========================================

int main() {
    // ========================================
    // 1. WRITING TO A FILE
    // ========================================
    // fopen(filename, mode)
    // "w" = write mode (creates file if not exists, overwrites if exists)

    FILE *file = fopen("fruit_list.txt", "w");

    if (file == NULL) {     // Always check if file opened successfully
        printf("Error: Could not open file for writing!\n");
        return 1;
    }

    // Write lines to file - fprint is like printf, but to file
    fprintf(file, "Apple - 15 CZK\n");
    fprintf(file, "Pear - 20 CZK\n");
    fprintf(file, "Banana - 90 CZK\n");
    fprintf(file, "Orange - 30 CZK\n");

    // Always close the file when done
    fclose(file);
    printf("Data successfully written to fruit_list.txt\n");

    // ========================================
    // 2. READING FROM A FILE
    // ========================================
    // "r" = read mode

    file = fopen("fruit_list.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file for reading!\n");
        return 1;
    }

    // Buffer for reading ne line at a time
    char line[100];     //Max 99 characters + \0

    printf("\nContents of fruit_list.txt\n");

    // fgets reads one line (up to newline or buffer size)
    // Returns NULL when end of file is reached
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);         // %s prints the string, no need for & because line is array
    }

    fclose(file);  // Close file again
    return 0;
}

/*
 * FILE I/O IN C - REAL-WORLD APPLICATION IN CYBERSECURITY
 * (Explanation for beginners – why this matters in security)
 *
 * What does this code demonstrate?
 * Basic file operations: opening a file, writing data to it, reading data back, and closing it.
 * This is the foundation of almost every security-related tool written in C.
 *
 * Why is file I/O so important in cybersecurity?
 *
 * 1. Defensive side (Blue Team):
 *    - Log analysis: Security tools (IDS, antivirus, SIEM) constantly read log files
 *      (e.g., /var/log/auth.log, Windows Event Logs) using fopen + fgets/fread
 *      to detect brute-force attacks, malware activity, or suspicious logins.
 *    - Forensic analysis: Investigators open disk images or memory dumps with fopen("rb")
 *      and search for deleted files, hidden data, or malware signatures.
 *    - Malware scanning: Antivirus opens suspicious files in read mode and scans for known bad patterns.
 *
 * 2. Offensive side (Red Team / Penetration testing):
 *    - Exploit development: Many exploits read payload/shellcode from a file
 *      (fopen("payload.bin", "rb") + fread) before injecting it into vulnerable program.
 *    - Ransomware: Real ransomware enumerates files on disk, opens them with fopen,
 *      reads content with fread, encrypts it, and writes back with fwrite.
 *    - Persistence: Malware often modifies system files (e.g., /etc/passwd, startup scripts)
 *      using file write operations to survive reboot.
 *
 * 3. Vulnerability classes directly related to file I/O:
 *    - Path traversal / Local File Inclusion (LFI): Attacker manipulates filename
 *      passed to fopen() to read arbitrary files on server (e.g., /etc/passwd).
 *    - Buffer overflows in file parsing: Badly written fgets/fread can overflow buffers
 *      if input size is not checked → classic exploitation vector.
 *
 * Key security best practices shown in this code:
 *    - Always check if fopen() returned NULL (file might not exist or no permission)
 *    - Always fclose() when done (prevents resource leaks)
 *    - Use "rb"/"wb" for binary files to avoid text translation issues
 *
 * Mastering file I/O in C is essential for anyone serious about low-level security,
 * reverse engineering, exploit development, or systems programming.
 * Almost every professional security tool (Wireshark plugins, YARA rules engine,
 * custom exploit frameworks) uses these exact functions.
 */