#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "proiect2.h"

int main(){
    int cif;
    std::vector<Student> listaStudenti;
    std::vector<Profesor> listaProfesori;
    std::vector<Curs> listaCursuri;
    std::string nume;
    Facultate facultate;
    std::cout << "0.-- Iesire" << "\n";
    std::cout << "1.-- Creare baza de date" << "\n";
    std::cout << "2.-- Vizualizare baza de date" << "\n";
    std::cout << "3.-- Stergere baza de date";

    int okBD = 0;

    while(1){
        std::cout << "\n\nInserare cifra: ";
        std::cin >> cif;

        if (cif == 0)break;

        else{
            switch(cif) {

                case 0:
                    break;

                case 1:
                    if (okBD == 1){
                        std::cout << "Baza de date a fost creata deja.";
                        break;
                    }
                    okBD = 1;
                    std::cout << "-> Nume Facultate: ";
                    facultate.setNume();
                    std::cout << "-> Oras: ";
                    facultate.setOras();
                    std::cout << "-> Inserati studenti: " << "\n";
                    while(1){
                        Student student;
                        if(student.getNume() == "0")
                            break;
                        listaStudenti.push_back(student);
                    }
                    std::cout << "-> Inserati profesori" << "\n";
                    while(1){
                        Profesor profesor;
                        if(profesor.getNume() == "0")
                            break;
                        else{
                            listaProfesori.push_back(profesor);
                            Curs curs;
                            curs.citire();
                            profesor.setCurs(curs);
                            std::cout << profesor.getNumeCurs() << " " << profesor.getCrediteCurs() << "\n";
                        }
                    }
                    std :: cout << "Baza de date a fost creata cu succes!";
                    break;

                case 2:
                    std::cout << "--> NUME FACULTATE: " << facultate.getNume() << "\n";
                    std::cout << "--> ORAS: " << facultate.getOras() << "\n";
                    std::cout << "--> STUDENTI: " << "\n";
                    for (int i = 0; i < listaStudenti.size(); ++i){
                        std::cout << "- " << listaStudenti[i].getNume() << "\n";
                    }
                    std::cout << "\n\n";
                    std::cout << "--> PROFESORI: " << "\n";
                    for (int i = 0; i < listaProfesori.size(); ++i){
                        std::cout << "- Nume: " << listaProfesori[i].getNume() << "\n";
                        std::cout << "- Curs predat: " << listaProfesori[i].getNumeCurs() << "\n";
                        std::cout << "- Credite" << listaProfesori[i].getCrediteCurs() << "\n";
                    }
                    std::cout << "\n\n";
                    break;

                case 3:

                    char btn;
                    if (okBD == 0){
                        std::cout << "Baza de date nu exista.";
                    }

                    else std::cout << "Sigur doriti sa stergeti baza de date?(y/n)";
                    std::cin >> btn;

                    if (btn == 'y') {
                        listaStudenti.clear();
                        listaProfesori.clear();
                        listaCursuri.clear();

                        facultate = Facultate();
                        okBD = 0;

                        std::cout << "Baza de date a fost stearsa!\n";
                    }
                    break;

                default:
                    std::cout << "\n\n";
                    std::cout << "Optiune nevalida";
            }
        }
    }
    return 0;
}
