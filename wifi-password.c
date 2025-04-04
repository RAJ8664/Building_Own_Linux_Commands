#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    FILE *fp;
    char line[1024];
    char ssid[256];
    char password[256];
    // Command to get WiFi connections from NetworkManager
    fp = popen("nmcli -g NAME connection show", "r");
    if (fp == NULL) {
        printf("Failed to execute command. Make sure NetworkManager is installed.\n");
        return 1;
    }
    printf("WiFi Networks and Passwords:\n");
    printf("============================\n\n");
    while (fgets(ssid, sizeof(ssid), fp) != NULL) {
        ssid[strcspn(ssid, "\n")] = 0;
        FILE *fp2;
        char command[1024];
        snprintf(command, sizeof(command),"sudo nmcli -s -g 802-11-wireless-security.psk connection show \"%s\"", ssid);
        fp2 = popen(command, "r");
        if (fp2 != NULL) {
            printf("Network: %s\n", ssid);
            if (fgets(password, sizeof(password), fp2) != NULL) {
                password[strcspn(password, "\n")] = 0;
                printf("Password: %s\n", password);
            } 
            else printf("Password: Not found or no password required\n");
            printf("\n");
            pclose(fp2);
        }
    }
    pclose(fp);
}

