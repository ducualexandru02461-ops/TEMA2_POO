#include <fstream>
#include <iostream>
#include <limits>
#include "proiect2.h"

int main() {
    std::ifstream fin("date.txt");

    if (!fin) {
        std::cout << "Eroare la deschiderea fisierului!";
        return 1;
    }

    Facultate f;

    std::string linie;

    std::getline(fin, linie);
    std::string numeFac = linie;

    std::getline(fin, linie);
    std::string oras = linie;

    f.setDate(numeFac, oras);

    std::getline(fin, linie);
    std::getline(fin, linie);

    std::string domeniu;

    while (std::getline(fin, linie) && linie != "") {
        std::getline(fin, domeniu);
        f.studenti.push_back(Student(linie, domeniu));
    }

    std::getline(fin, linie);

    std::string numeProf, numeCurs;
    int credite;

    while (std::getline(fin, numeProf)) {
        if (numeProf == "") break;

        std::getline(fin, numeCurs);
        fin >> credite;
        fin.ignore();

        Curs c(numeCurs, credite);
        f.profesori.push_back(Profesor(numeProf, c));
    }


    std::string nume, prenume, departament;
    int vechime;

    std::getline(fin, linie);

    while (fin >> nume >> prenume >> departament >> vechime) {
        std::string numeComplet = nume + " " + prenume;
        f.secretari.push_back(Secretar(numeComplet, departament, vechime));
    }

    f.afisare();


    while(1){
        std::cout << "\n   INSERATI CIFRA:\n"
                  << "0-Exit\n"
                  << "1-Inregistrare persoane noi\n"
                  << "2-Numarul studentilor noi inregistrati\n";
        int btn;
        std::cout << "\n-> ";
        std::cin >> btn;
        if (btn == 0){
            std::cout << "\n   CLOSED";
            break;
        }
        switch(btn){
            case 1:
                {
                //std::vector<Persoana*> persoane;
                while(1){

                    int tip;
                    std::cout << "0-Exit| 1-Student | 2-Profesor | 3-Secretar: ";
                    std::cin >> tip;
                    std::cin.ignore();

                    Persoana* p = nullptr;

                    if (tip == 0)
                        break;
                    else if (tip == 1)
                        p = new Student();
                        else if (tip == 2)
                            p = new Profesor();
                            else if (tip == 3)
                                p = new Secretar();

                    if (p) {
                        p->citire(std::cin);
                        f.persoane.push_back(p);
                    }
                }

                std::cout << "\n   PERSOANE NOI:";
                f.afiseazaDate();
                break;
                }
            case 2:
                {
                    std::cout << "\n   ->Au fost inregistrati " << f.nrStudentiAdaugati() << " studenti noi.";
                    break;
                }
            default:
                std::cout << "\n   OPTIUNE INVALIDA\n";
                break;
        }
    }

    return 0;
}
