/*NOTE--> make sure to install lreadline and spring cli first */
/* TO Compile --> gcc spring-boot-project-generator.c -o spring-boot-project-generator -lreadline */
/*Used to generate a Spring Boot project using the Spring Boot CLI */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

// ANSI escape codes for styling
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define GREEN       "\033[32m"
#define CYAN        "\033[36m"
#define YELLOW      "\033[33m"
#define RED         "\033[31m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define WHITE       "\033[97m"

void printBanner() {
    printf(BOLD CYAN "╔═══════════════════════════════════════════════╗\n");
    printf("║     Spring Boot Project Generator (CLI)       ║\n");
    printf("╚═══════════════════════════════════════════════╝\n" RESET);
}

int main() {
    printBanner();
    printf(YELLOW ">> Please fill in the following configuration:\n" RESET);
    char *javaVersion = readline(BLUE "🧩 Java version (e.g. 8, 11, 17): " RESET);
    char *buildTool = readline(BLUE "⚙️  Build tool (maven/gradle): " RESET);
    char *groupId = readline(BLUE "🏷️  Group ID (e.g. com.example): " RESET);
    char *artifactId = readline(BLUE "📦 Artifact ID (e.g. my-app): " RESET);
    char *projectName = readline(BLUE "📁 Project Name: " RESET);
    char *dependencies = readline(BLUE "📚 Dependencies (comma-separated): " RESET);

    printf(YELLOW "\n>> Generating your project...\n" RESET);

    char command[2048];

    snprintf(command, sizeof(command),
         "spring init --build=%s --java-version=%s --groupId=\"%s\" --artifactId=\"%s\" --name=\"%s\" --dependencies=\"%s\" \"%s\"",
         buildTool, javaVersion, groupId, artifactId, projectName, dependencies, projectName);

    printf(GREEN "\n🚀 Executing command:\n" CYAN "%s\n" RESET, command);

    int status = system(command);
    if (status == 0) {
        printf(GREEN "\n✅ Project created successfully in folder: " BOLD "%s\n" RESET, projectName);
    } else {
        printf(RED "\n❌ Failed to generate project. Please ensure Spring Boot CLI is installed and in PATH.\n" RESET);
    }

    free(javaVersion);
    free(buildTool);
    free(groupId);
    free(artifactId);
    free(projectName);
    free(dependencies);

    return 0;
}

