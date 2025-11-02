#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0; // nie tworzymy ¿adnych statków

    Stocznia     stocznia{};
    unsigned int suma            = 0;
    unsigned int liczbaZaglowcow = 0;

    while (suma < towar) {
        Statek*      s            = stocznia();       // tworzymy nowy statek
        unsigned int przewiezione = s->transportuj(); // transportuje towar
        suma += przewiezione;                         // sumujemy

        // sprawdzamy, czy to ¿aglowiec
        if (dynamic_cast< Zaglowiec* >(s) != nullptr)
            ++liczbaZaglowcow;

        delete s; // niszczymy statek
    }

    return liczbaZaglowcow;
}