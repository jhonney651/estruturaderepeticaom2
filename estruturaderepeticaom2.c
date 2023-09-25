#include <stdio.h>
#include <ncurses.h>

int main() {
    initscr();
    raw();
    keypad(stdscr, TRUE);

    int voto, votosWindows = 0, votosUnix = 0, votosLinux = 0, votosNetware = 0, votosMac = 0, votosOutros = 0, totalVotos = 0, contWindows, contUnix, contLinux, contNetware, contMac, contOutros, reiniciar = 0;

    do {
        clear();
        refresh();
        voto = 7;
        curs_set(1);
        mvprintw(1, 3, "=Bem-vindo à nossa votação=");
        mvprintw(3, 0, "insira apenas valores entre 0 e 6, sendo 0 para encerrar a votação e de 1 a 6 para votar");
        mvprintw(4, 0, "qual sistema voce deseja votar?\n1-Windows\n2-Unix\n3-Linux\n4-Netware\n5-Mac OS\n6-Outros\n0-Encerrar Votação\n\n");
        scanw("%d", &voto);

        switch (voto) {
            case 1:
                votosWindows++;
                totalVotos++;
                break;
            case 2:
                votosUnix++;
                totalVotos++;
                break;
            case 3:
                votosLinux++;
                totalVotos++;
                break;
            case 4:
                votosNetware++;
                totalVotos++;
                break;
            case 5:
                votosMac++;
                totalVotos++;
                break;
            case 6:
                votosOutros++;
                totalVotos++;
                break;
            case 0:
                clear();
                refresh();

                contWindows = votosWindows * 100 / totalVotos;
                contUnix = votosUnix * 100 / totalVotos;
                contLinux = votosLinux * 100 / totalVotos;
                contNetware = votosNetware * 100 / totalVotos;
                contMac = votosMac * 100 / totalVotos;
                contOutros = votosOutros * 100 / totalVotos;

                mvprintw(1, 0, "=Votação encerrada=");                
                mvprintw(3, 0, "O resultado das votações é:");
                mvprintw(5, 0, "Ao todo foram %d votos", totalVotos);
                mvprintw(7, 0, "Windows teve %d%% dos votos", contWindows);
                mvprintw(8, 0, "Unix teve %d%% dos votos", contUnix);
                mvprintw(9, 0, "Linux teve %d%% dos votos", contLinux);
                mvprintw(10, 0, "Netware teve %d%% dos votos", contNetware);
                mvprintw(11, 0, "Mac OS teve %d%% dos votos", contMac);
                mvprintw(12, 0, "Outros sistemas tiveram %d%% dos votos", contOutros);

                mvprintw(14, 0, "Para sair pressione qualquer tecla...");
                refresh();
                getch();
                endwin();
                return 0;

            default:
                clear();
                refresh();
                mvprintw(1, 0, "Valor incorreto, por favor insira um valor válido.");
                mvprintw(2, 0, "Pressione qualquer tecla para voltar à tela de votação.");
                getch();
                break;
        }
    } while (reiniciar == 0);
}
