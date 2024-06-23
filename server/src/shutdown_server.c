/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server.h"
#include <signal.h>

sig_atomic_t is_running = true;

int sigaction_init(void)
{
    struct sigaction action;
    action.sa_flags = 0;
    action.sa_sigaction = handle_sigint;
    sigemptyset(&action.sa_mask);

    if (sigaction(SIGINT, &action, NULL) == -1)
        return 84;
}

void shutdown_action(server_t *server)
{
    if (is_server_running())
        shutdown_server(server);
}

bool is_server_running(void)
{
    return is_running;
}

void handle_sigint(int sig, siginfo_t *info, void *ucontext)
{
    (void)info;
    (void)ucontext;
    (void)sig;
    is_running = false;
    printf("Shutting down server...\n");
}

void shutdown_server(server_t *server)
{
    client_t *client = NULL;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        close(client->socket);
    }
}
