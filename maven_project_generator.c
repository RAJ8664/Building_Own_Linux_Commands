/* NOTE --> make sure to install libreadline-dev */
/* TO Compile --> gcc maven-project-generator.c -o maven-project-generator -lreadline */
/* Used to generate a Maven Java project using the Maven CLI */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

// ANSI styling
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define GREEN       "\033[32m"
#define CYAN        "\033[36m"
#define YELLOW      "\033[33m"
#define RED         "\033[31m"
#define BLUE        "\033[34m"

void printBanner() {
    printf(BOLD CYAN "╔═══════════════════════════════════════════════╗\n");
    printf("║       Maven Java Project Generator (CLI)      ║\n");
    printf("╚═══════════════════════════════════════════════╝\n" RESET);
}

int main() {
    printBanner();
    printf(YELLOW ">> Please fill in the following configuration:\n" RESET);

    char *groupId = readline(BLUE "🏷️  Group ID (e.g. com.example): " RESET);
    char *artifactId = readline(BLUE "📦 Artifact ID (project folder name): " RESET);
    char *version = readline(BLUE "🗂️  Version (default: 1.0-SNAPSHOT): " RESET);
    char *packageName = readline(BLUE "📦 Package Name (e.g. com.example.app): " RESET);

    // Default to "1.0-SNAPSHOT" if user doesn't provide version
    if (version == NULL || strlen(version) == 0) {
        version = strdup("1.0-SNAPSHOT");
    }

    printf(YELLOW "\n>> Generating your Maven project...\n" RESET);

    char command[2048];
    snprintf(command, sizeof(command),
        "/usr/bin/mvn archetype:generate "
        "-DgroupId=%s "
        "-DartifactId=%s "
        "-Dversion=%s "
        "-Dpackage=%s "
        "-DarchetypeArtifactId=maven-archetype-quickstart "
        "-DinteractiveMode=false",
        groupId, artifactId, version, packageName
    );

    printf(GREEN "\n🚀 Executing command:\n" CYAN "%s\n" RESET, command);

    int status = system(command);
    if (status == 0) {
        printf(GREEN "\n✅ Project created successfully in folder: " BOLD "%s\n" RESET, artifactId);
    } else {
        printf(RED "\n❌ Failed to generate Maven project. Make sure Maven is installed and in PATH.\n" RESET);
    }

    // Free memory
    free(groupId);
    free(artifactId);
    free(version);
    free(packageName);

    return 0;
}
