/*
 * wifi-password - Lists all saved WiFi networks and their passwords
 * 
 * A command-line utility to display WiFi network credentials stored in NetworkManager
 * 
 * Author: @RAJ ROY
 * Date: 2025-04-04
 * Usage: sudo wifi-password
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    /* File pointers for command execution */
    FILE *fp;
    
    /* Buffers for storing data */
    char line[1024];
    char ssid[256];
    char password[256];
    
    /* Query NetworkManager for list of saved connections */
    fp = popen("nmcli -g NAME connection show", "r");
    if (fp == NULL) {
        printf("Failed to execute command. Make sure NetworkManager is installed.\n");
        return 1;
    }

    /* Print header for the output */
    printf("WiFi Networks and Passwords:\n");
    printf("============================\n\n");

    /* Iterate through each network connection */
    while (fgets(ssid, sizeof(ssid), fp) != NULL) {
        /* Remove newline character from SSID */
        ssid[strcspn(ssid, "\n")] = 0;
        
        /* Variables for password retrieval */
        FILE *fp2;
        char command[1024];

        /* Construct command to fetch password for current network */
        snprintf(command, sizeof(command),
                "sudo nmcli -s -g 802-11-wireless-security.psk connection show \"%s\"",
                ssid);
        
        /* Execute password retrieval command */
        fp2 = popen(command, "r");
        if (fp2 != NULL) {
            printf("Network: %s\n", ssid);
            
            /* Read and display password if available */
            if (fgets(password, sizeof(password), fp2) != NULL) {
                password[strcspn(password, "\n")] = 0;
                printf("Password: %s\n", password);
            }
            else {
                printf("Password: Not found or no password required\n");
            }
            printf("\n");
            pclose(fp2);
        }
    }
    pclose(fp);
    return 0;
}

