/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_GUI_H
    #define ZAPPY_GUI_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus
    #include "server.h"

    /**
     * @brief Struct for the list of the gui commands
     *
     * This structure represents a gui command in the game Zappy.
     * Each gui command has a command and a function pointer.
     *
     */
    typedef struct gui_game_command_s {
        char *cmd;
        void (*func)(game_t *game, char *msg);
    } gui_game_command_t;

    /**
     * @brief Struct for the list of the gui commands
     *
     * This structure represents a gui command in the game Zappy.
     * Each gui command has a command and a function pointer.
     *
     */
    typedef struct gui_server_command_s {
        char *cmd;
        void (*func)(server_t *server, char *msg);
    } gui_server_command_t;

    /**
     * @brief Run the differents gui commands
     *
     * @param server The server
     */
    void run_gui_commands(server_t *server);

    /**
     * @brief update the graphic client buffer with the game log
     *
     * @param server The server
     */
    void update_graphic_clients_buffer(server_t *server);

    /**
     * @brief msz command
     *
     * @param game The game
     * @param arg The argument
     */
    void msz_log_gui(game_t *game, char *arg);

    /**
     * @brief bct command
     *
     * @param game The game
     * @param arg The argument
     */
    void bct_log_gui(game_t *game, char *arg);

    /**
     * @brief mct command
     *
     * @param game The game
     * @param arg The argument
     */
    void mct_log_gui(game_t *game, char *arg);

    /**
     * @brief tna command
     *
     * @param game The game
     * @param arg The argument
     */
    void tna_log_gui(game_t *game, char *arg);

    /**
     * @brief pnw command
     *
     * @param game The game
     * @param arg The argument
     */
    void pnw_log_gui(game_t *game, trantorian_t *trantorian, char *team_name);

    /**
     * @brief ppo command
     *
     * @param game The game
     * @param arg The argument
     */
    void ppo_log_gui(game_t *game, char *arg);

    /**
     * @brief plv command
     *
     * @param game The game
     * @param arg The argument
     */
    void plv_log_gui(game_t *game, char *arg);

    /**
     * @brief pin command
     *
     * @param game The game
     * @param arg The argument
     */
    void pin_log_gui(game_t *game, char *arg);

    /**
     * @brief pbc command
     *
     * @param game The game
     * @param trantorian The trantorian that broadcasted
     * @param msg The message broadcasted
     */
    void pbc_log_gui(game_t *game, trantorian_t *trantorian, char *msg);

    /**
     * @brief pic command
     *
     * @param game The game
     * @param trantorians The trantorians in the incantation
     * @param level The level of the incantation
     * @param pos The position of the incantation
     */
    void pic_log_gui(game_t *game, array_t *trantorians, size_t level, coordinates_t pos);

    /**
     * @brief pfk command
     *
     * @param game The game
     * @param trantorian The trantorian
     */
    void pfk_log_gui(game_t *game, trantorian_t *trantorian);

    /**
     * @brief pdr command
     *
     * @param game The game
     * @param trantorian The trantorian
     * @param resource The resource
     */
    void pdr_log_gui(game_t *game, trantorian_t *trantorian, size_t resource);

    /**
     * @brief pgt command
     *
     * @param game The game
     * @param trantorian The trantorian
     * @param resource The resource
     */
    void pgt_log_gui(game_t *game, trantorian_t *trantorian, size_t resource);

    /**
     * @brief pdi command
     *
     * @param game The game
     * @param trantorian The trantorian
     */
    void pdi_log_gui(game_t *game, trantorian_t *trantorian);

    /**
     * @brief enw command
     *
     * @param game The game
     * @param egg The egg
     * @param trantorian The trantorian
     */
    void enw_log_gui(game_t *game, egg_t *egg, trantorian_t *trantorian);

    /**
     * @brief ebo command
     *
     * @param game The game
     * @param egg The egg
     */
    void ebo_log_gui(game_t *game, egg_t *egg);

    /**
     * @brief edi command
     *
     * @param game The game
     * @param egg The egg
     */
    void edi_log_gui(game_t *game, egg_t *egg);

    /**
     * @brief sgt command
     *
     * @param server The server
     * @param arg The argument
     */
    void sgt_log_gui(server_t *server, char *arg);

    /**
     * @brief sst command
     *
     * @param server The server
     * @param arg The argument
     */
    void sst_log_gui(server_t *server, char *arg);

    /**
     * @brief seg command
     *
     * @param game The game
     * @param team_name The name of the team that won
     */
    void seg_log_gui(game_t *game, char *team_name);

    /**
     * @brief smg command
     *
     * @param game The game
     * @param msg The message
     */
    void smg_log_gui(game_t *game, char *msg);

    /**
     * @brief suc command
     *
     * @param game The game
     */
    void suc_log_gui(game_t *game);

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif // ZAPPY_GUI_H
