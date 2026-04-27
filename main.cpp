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
    std::cout << "3.-- Stergere baza de date" << "\n";
    std::cout << "4.-- Adauga student" << "\n";
    std::cout << "5.-- Sterge student" << "\n";
    std::cout << "6.-- Cauta student" << "\n";
    std::cout << "7.-- Adauga curs profesor" << "\n";
    std::cout << "MENTIUNE: IN CAZUL IN CARE DORITI SA NU CONTINUATI, APASATI TASTA 0 ORICAND!";

    int okBD = 0;


    while(1){
        std::cout << "\n\nInserare cifra: ";
        std::cin >> cif;
        std::cin.ignore();

        if (cif == 0){
            std::cout << "La revedere!";
            break;
        }

        else{

            switch(cif) {

                case 1:
                    if (okBD == 1){
                        std::cout << "Baza de date a fost creata deja.";
                        break;
                    }
                    okBD = 1;
                    std::cout << "-> Nume Facultate: ";
                    facultate.setNume();
                    if (facultate.getNume() == "0")break;
                    std::cout << "-> Oras: ";
                    facultate.setOras();
                    if (facultate.getOras() == "0")break;
                    std::cout << "-> Inserati studenti: " << "\n";
                    while(1){
                        Student student;
                        if(student.getNume() == "execute"){
                            if(listaStudenti.size() == 0){
                                std::cout << "!EROARE!" << "\n";
                            }
                            else{
                                break;
                            }
                        }
                        if (student.getNume() == "exit"){
                            break;
                        }
                        listaStudenti.push_back(student);
                    }
                    std::cout << "-> Inserati profesori" << "\n";
                    while(1){
                        Profesor profesor;
                        if(profesor.getNume() == "execute")
                            break;
                        else{
                            Curs curs;
                            curs.citire();
                            profesor.setCurs(curs);
                            listaProfesori.push_back(profesor);
                            std::cout << profesor.getNumeCurs() << " " << profesor.getCrediteCurs() << "\n";
                        }
                    }
                    std :: cout << "Baza de date a fost creata cu succes!";
                    break;

                case 2:
                    if (okBD == 0){
                        std::cout << "Baza de date nu exista!";
                        break;
                    }
                    std::cout << "--> NUME FACULTATE: " << facultate.getNume() << "\n";
                    std::cout << "--> ORAS: " << facultate.getOras() << "\n";
                    std::cout << "--> STUDENTI: " << "\n";
                    for (int i = 0; i < listaStudenti.size(); ++i){
                        std::cout << "- " << listaStudenti[i].getNume() << "\n";
                    }
                    std::cout << "\n\n";
                    std::cout << "--> PROFESORI: " << "\n";
                    for (int i = 0; i < listaProfesori.size(); i++){
                        std::cout << "- Nume: " << listaProfesori[i].getNume() << "\n";
                        std::cout << "- Curs predat: " << listaProfesori[i].getNumeCurs() << "\n";
                        std::cout << "- Credite: " << listaProfesori[i].getCrediteCurs() << "\n\n";
                    }
                    break;

                case 3:

                    char btn;
                    if (okBD == 0){
                        std::cout << "Baza de date nu exista.";
                        break;
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

                case 4:
                    if (okBD == 0){
                        std::cout << "Baza de date nu exista!";
                        break;
                    }


                    std::cout << "-> Inserati studenti: " << "\n";
                    while(1){
                        Student student;
                        if(student.getNume() == "0")
                            break;
                        listaStudenti.push_back(student);
                    }

                case 5:
                    int btn5;
                    if (listaStudenti.size() == 0){
                        std:: cout << "Nu a fost inregistrat niciun student!";
                    }
                    else std:: cout << "Introduceti numarul studentului pe care doriti sa il stergeti." << "\n" << "->";
                    std:: cin >> btn5;
                    if (btn5 == 0) {
                        std::cout << "Doriti sa anulati?";
                        char btn5_yn;
                        std::cin >> btn5_yn;
                        if (btn5_yn == 'y') break;
                        else continue;
                    }
                    else if (btn5 > listaStudenti.size() || btn5 < listaStudenti.size()) std::cout << "Optiune invalida!";
                        else listaStudenti[btn5];

                case 6:
                    int btn6;
                    std::cout << "Introduceti numarul studentului pe care doriti sa il gasiti." << "\n" << "->";
                    if (btn6 == 0){
                            std::cout << "Doriti sa anulati?(y/n)";
                            char btn6_yn;
                            std::cin >> btn6_yn;
                            if (btn6_yn == 'y') break;
                            else continue;
                    }

                    else if (btn6 > listaStudenti.size() || btn6 < listaStudenti.size()) std::cout << "Optiune invalida!";
                        else{
                            std::cout << "-> Inserati studenti: " << "\n";
                            while(1){
                            Student student;
                            if(student.getNume() == "0")
                                break;
                            listaStudenti.push_back(student);
                            }
                        }


                default:
                    std::cout << "\n\n";
                    std::cout << "Optiune nevalida";
            }


        }
    }
    return 0;

}
