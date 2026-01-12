#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

// NOTE: This code requires a POSIX environment (Linux, WSL, MacOS) to run.
// It will not compile with standard Windows compilers (MSVC) without specific POSIX libraries.

int main() {
    cout << "Demonstrating fork() system call" << endl;
    
    pid_t process_id = fork();
    
    if (process_id < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    } else if (process_id == 0) {
        // Child process
        cout << "Hello from Child Process!" << endl;
        cout << "Child PID: " << getpid() << endl;
        cout << "Parent PID: " << getppid() << endl;
    } else {
        // Parent process
        cout << "Hello from Parent Process!" << endl;
        cout << "Parent PID: " << getpid() << endl;
        cout << "Child PID: " << process_id << endl;
    }
    
    return 0;
}
