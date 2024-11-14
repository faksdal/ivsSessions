/*
 * openSessionOnline.cpp
 *
 *  Created on: Nov 14, 2024
 *      Author: leijon
 */

#include <unistd.h> // For fork, execlp
#include <string>
#include <sys/types.h>
#include <sys/wait.h>

//#include <cstdio>
//#include <cstdlib>
#include <fcntl.h>

#include "ivsSessions.h"



void ivsSessions::openSessionOnline(const std::string& url)
{
	// Temporarily redirect stderr to /dev/null to suppress any Gtk-messages

    // Save the current stderr file descriptor
    int stderr_backup = dup(STDERR_FILENO);

    // Redirect stderr to /dev/null
    int null_fd = open("/dev/null", O_WRONLY);
    dup2(null_fd, STDERR_FILENO);
    close(null_fd);

    // Run the command to open the URL
    std::string command = "xdg-open " + url;
    std::system(command.c_str());

    // Restore stderr
    dup2(stderr_backup, STDERR_FILENO);
    close(stderr_backup);

	/*
    std::string command = "xdg-open " + url;
    std::system(command.c_str());
    */

    /*
	pid_t pid = fork();
	if (pid == 0) {
		// Child process
		execlp("xdg-open", "xdg-open", url.c_str(), nullptr);
		_exit(1); // Exit if execlp fails
	} else if (pid > 0) {
		// Parent process
		int status;
		waitpid(pid, &status, 0); // Wait for the child process to complete
	} else {
		// Fork failed
		perror("fork");
	}
	*/
}



/*
void openURL(const std::string& url) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execlp("xdg-open", "xdg-open", url.c_str(), nullptr);
        _exit(1); // Exit if execlp fails
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for the child process to complete
    } else {
        // Fork failed
        perror("fork");
    }
}
*/
