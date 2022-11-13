#include <stdio.h>
#include <time.h>

void newline()
{
    printf("\n");
}

void main()
{
    int pin, vrijednost=1234, provjera=0;
    float stanje=15.823400;
    printf("Bankomat system by demkyy v1.0\n\n");
    printf("Dobrodosli na bankomat xy banke!\nMolimo unsite Vas cetveroznamenkasti PIN kod.\n\nPIN: ");
    do
    {
        scanf("%d",&pin);
        if(pin==vrijednost)
        {
            int PrviUnos;
            printf("\nUspjesno ste unijeli Vas PIN kod.\n");
            do
            {
                int DrugiUnos,TreciUnos;
                /////////////////////////////// CREDITS TO STACK OVERFLOW FOR TIME.H
                time_t rawtime;
                struct tm * timeinfo;
                time(&rawtime);
                timeinfo=localtime(&rawtime);
                ///////////////////////////////
                printf("Molimo Vas odaberite zeljenu transakciju:\n1. Stanje na racunu\n2. Podizanje novca\n3. Promjena PIN-a\n4. Izlaz\n\nOdabir: ");
                scanf("%d",&PrviUnos);
                switch(PrviUnos)
                {
                    case 1:
                        printf("\n*****************************************\nTekuce stanje na racunu: %.2lf $\nDatum i vrijeme: %s\n*****************************************\nVasa xy banka!\n\n",stanje,asctime(timeinfo));
                        break;
                    case 2:
                        printf("NAPOMENA: Mozete podizati iskljucivo novcanice po 1$, 2$, 5$, 10$, 20$, 50$ i 100$!\n");
                        do
                        {
                            printf("Unesite zeljeni iznos novca za podizanje sa bankomata. Unesite '0' ako zelite odustati od podizanja novca.\n\nZeljena suma: ");
                            scanf("%d",&DrugiUnos);
                            if(DrugiUnos>(int)stanje)
                            {
                                printf("\aGRESKA: Ne mozete podici vise od onoga sto imate na racunu!\n\n");
                            }
                            else if((int)stanje<0)
                            {
                                printf("\aGRESKA: Nemate sredstava na Vasem tekucem racunu!\n\n");
                            }
                            else if(DrugiUnos==0)
                            {
                                printf("Hvala Vam na koristenju usluge bankomata! Vasa xy banka.\n\n");
                            }
                            else if((DrugiUnos!=1)&&(DrugiUnos!=2)&&(DrugiUnos!=5)&&(DrugiUnos!=10)&&(DrugiUnos!=20)&&(DrugiUnos!=50)&&(DrugiUnos!=100))
                            {
                                printf("\aGRESKA: Mozete podizati iskljucivo novcanice po 1$, 2$, 5$, 10$, 20$, 50$ i 100$!\n\n");
                            }
                            else
                            {
                                stanje-=DrugiUnos;
                                printf("Uspjesno ste podigli %.2f $ sa Vaseg tekuceg racuna.\nHvala Vam sto koristite usluge xy banke.\n\n",(float)DrugiUnos);
                                do
                                {
                                    printf("Zelite li ponovo izvrsiti transakciju?\n1. Da\n2. Ne\n\nOdabir: ");
                                    scanf("%d",&TreciUnos);
                                    switch(TreciUnos)
                                    {
                                        case 1:
                                            DrugiUnos=1;
                                            TreciUnos=2;
                                            newline();
                                            break;
                                        case 2:
                                            DrugiUnos=0;
                                            printf("Hvala Vam na koristenju usluge bankomata! Vasa xy banka.\n\n");
                                            break;
                                        default:
                                            printf("\aPogresan unos koda! Pokusajte ponovo.\n\n");
                                            break;
                                    }
                                }
                                while(TreciUnos!=2);
                            }
                        }
                        while(DrugiUnos!=0);
                        break;
                    case 3:
                        printf("Odabrali ste promjenu postojeceg PIN koda.\nZbog sigurnosnih razloga molimo unesite Vas postojeci PIN kod.\n\nPIN: ");
                        scanf("%d",&pin);
                        if(pin==vrijednost)
                        {
                            printf("Uspjesno ste unijeli Vas trenutni PIN kod.\nU nastavku molimo unesite Vas NOVI zeljeni PIN kod.\n\nPIN: ");
                            scanf("%d",&pin);
                            if(pin==vrijednost)
                            {
                                int i=0;
                                while(i<2)
                                {
                                    printf("\aUneseni kod se poklapa sa postojecim,\nstoga molimo unesite NOVI PIN kod! (%d/3 pokusaja)\n\nPIN: ",i+1);
                                    i++;
                                    scanf("%d",&pin);
                                    if(pin!=vrijednost)
                                    {
                                        i=0;
                                        break;
                                    }
                                }
                                if(i==2)
                                {
                                    PrviUnos=4;
                                    provjera=3;
                                    printf("\aVasa kartica je blokirana zbog sigurnosnih razloga. (%d/3 pokusaja)\nObratite se na salter banke za dodatne informacije.\n",i+1);
                                    break;
                                }
                            }
                            vrijednost=pin;
                            printf("Uspjesno ste promijenili Vas postojeci PIN kod.\nVas NOVI PINKOD je: **%d\n\n",vrijednost%100);
                            printf("Molimo unesite Vas PIN kod kako biste nastavili.\n\nPIN: ");
                            PrviUnos=4;
                            provjera=0;
                            pin=1234;
                        }
                        else
                        {
                            PrviUnos=4;
                            provjera=3;
                            printf("\aVasa kartica je blokirana zbog sigurnosnih razloga.\nObratite se na salter banke za dodatne informacije.\n");
                        }
                        break;
                    case 4:
                        provjera=3;
                        printf("Hvala Vam na koristenju nasih usluga. Vidimo se ponovo.\n");
                        break;
                    default:
                        printf("Pogresan unos koda! Pokusajte ponovo.\n\n");
                        break;
                }
            }
            while(PrviUnos!=4);
        }
        else
        {
            if(provjera<2)
            {
                printf("\aUnijeli ste pogresan PIN kod! (%d/3 pokusaja)\n\nUnesite ponovo Vas PIN kod.\nPIN: ",provjera+1);
                provjera++;
            }
            else if(provjera==2)
            {
                provjera++;
                printf("\a\nZao nam je, Vasa kartica je blokirana. (%d/3 pokusaja)\nObratite se na salter banke za dodatne informacije.\n",provjera);
            }
        }
    }
    while((pin!=vrijednost)&&(provjera<3));
}
