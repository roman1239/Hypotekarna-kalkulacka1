

#include <iostream>
#include <math.h>

int main()
{
    int pocet_rokov = 30;
    float urokova_miera = 4.49;
    float pozicana_suma = 170000;

    float istina = pozicana_suma;
    float mesacny_urok;
    float celkovy_urok = 0;
    float mesacna_splatka;
    float mesacna_istina;

    mesacna_splatka = istina * (urokova_miera / 100 / 12) * pow(1 + urokova_miera / 100 / 12, 12 * pocet_rokov);
    mesacna_splatka = mesacna_splatka / (pow(1 + urokova_miera / 100 / 12, 12 * pocet_rokov) - 1);

    for (int i = 1; i <= pocet_rokov; i++)
    {
        std::cout << std::endl << i  << ". rok " << std::endl;
        for (int j = 1; j <= 12; j++)
        {
            mesacny_urok = istina * (urokova_miera / 100) / 12;
            celkovy_urok += mesacny_urok;

            (mesacna_splatka > istina) ? mesacna_istina = istina + mesacny_urok : mesacna_istina = mesacna_splatka - mesacny_urok;

            //std::cout << "splatka: " << mesacna_splatka << ",  urok: " << mesacny_urok << ",  istina: " << mesacna_istina << std::endl;
            printf("splatka: %.2f,  urok: %.2f,  istina: %.2f,  ", mesacna_splatka, mesacny_urok, mesacna_istina);
            istina = istina - mesacna_istina;
            printf("zostavajuca istina: %.2f,  celkovo zaplatene na urokoch: %.2f", istina, celkovy_urok);
            std::cout << std::endl;

        }
    }
    std::cout << std::endl << "celkovo preplatene na urokoch: " << celkovy_urok << std::endl;
}
