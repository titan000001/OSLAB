#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

// NOTE: This code requires a POSIX environment (Linux, WSL, MacOS) to run.
// It will not compile with standard Windows compilers (MSVC) without specific POSIX libraries.

int main() {
    cout << "Demonstrating exec() family system call" << endl;
    
    pid_t pid = fork();
    
    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        cout << "Child process calling execlp()..." << endl;
        
        // execlp replaces the current process image with a new one
        // Here we run "ls -l" command
        execlp("ls", "ls", "-l", NULL);
        
        // If exec succeeds, this line will NOT be reached
        cerr << "Exec failed!" << endl;
        return 1;
    } else {
        // Parent process
        wait(NULL); // Wait for child to complete
        cout << "Parent process: Child has finished." << endl;
    }
    
    return 0;
}
