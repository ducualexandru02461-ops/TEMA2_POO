#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "proiect2.h"

int main(){
    int cif, ok;
    std::vector<Student> listaStudenti;
    std::vector<Profesor> listaProfesori;
    std::vector<Curs> listaCursuri;
    std::vector<Credite> listaCredite;
    std::string nume;
    Facultate facultate;
    std::cout << "0.-- Iesire" << "\n";
    std::cout << "1.-- Creare baza de date" << "\n";
    std::cout << "2.-- Vizualizare baza de date" << "\n";
    std::cout << "3.-- Stergere baza de date" << "\n";
    std::cout << "4.-- Adauga student" << "\n";
    std::cout << "5.-- Sterge student" << "\n";
    std::cout << "6.-- Cauta student" << "\n";
    std::cout << "7.-- Adauga curs profesor" << "\n\n";
    std::cout << "  MENTIUNE:" << "\n" << "->IN CAZUL IN CARE DORITI SA NU CONTINUATI, APASATI TASTA 0 ORICAND!" << "\n";

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
                        ok = 1;
                        Student student;
                        if (student.getNume() == "0"){
                            std::cout << "Sigur doriti sa iesiti?(y/n)";
                            char btn1;
                            std::cin >> btn1;
                            std::cin.ignore();
                            if (btn1 == 'y'){
                                ok = 0;
                                break;
                            }
                        }
                        else if (student.getNume() == ""){
                            if (listaStudenti.size() == 0){
                                std::cout << "\n" << "Eroare" << "\n";
                            }
                            else break;
                        }
                            else{
                                listaStudenti.push_back(student);
                            }
                    }
                    if (ok == 0) {
                        okBD = 0;
                        listaStudenti.clear();
                        facultate = Facultate();
                        break;
                    }

                    std::cout << "-> Inserati profesori" << "\n";
                    while(1){
                        ok = 1;
                        Profesor profesor;
                        if (profesor.getNume() == "0"){
                            std::cout << "Sigur doriti sa iesiti?(y/n)";
                            char btn1;
                            std::cin >> btn1;
                            std::cin.ignore();
                            if (btn1 == 'y'){
                                ok = 0;
                                break;
                            }
                        }
                        if (ok == 0){
                            okBD = 0;
                            listaStudenti.clear();
                            listaProfesori.clear();
                            facultate = Facultate();
                            std::cout << "Crearea bazei de date a fost anulata!\n";
                            break;
                        }
                        else if (profesor.getNume() == ""){
                            if (listaProfesori.size() == 0){
                                std::cout << "\n" << "Eroare" << "\n";
                            }
                        }
                            else{
                                listaProfesori.push_back(profesor);
                                Curs curs;
                                curs.citire();
                                if (curs.getNume() == "0"){
                                    std::cout << "Sigur doriti sa iesiti?(y/n)";
                                    char btn2;
                                    std::cin >> btn2;
                                    std::cin.ignore();
                                    if (btn2 == 'y'){
                                        ok = 0;
                                        break;
                                    }
                                }
                                if (ok == 0){
                                    okBD = 0;
                                    listaStudenti.clear();
                                    listaProfesori.clear();
                                    listaCursuri.clear();
                                    facultate = Facultate();
                                    break;
                                }
                                else if (curs.getNume() == ""){
                                    if (listaCursuri.size() == 0){
                                        std::cout << "\n" << "Eroare" << "\n";
                                    }
                                }
                                    else{
                                        listaCursuri.push_back(curs);
                                        Credite credite;
                                        credite.citire();
                                        if (credite.getCredite() == "0"){
                                            std::cout << "Sigur doriti sa iesiti?(y/n)";
                                            char btn3;
                                            std::cin >> btn3;
                                            std::cin.ignore();
                                            if (btn3 == 'y'){
                                                ok = 0;
                                                break;
                                            }
                                        }
                                        if (ok == 0){
                                            okBD = 0;
                                            listaStudenti.clear();
                                            listaProfesori.clear();
                                            listaCursuri.clear();
                                            listaCredite.clear();
                                            facultate = Facultate();
                                            break;
                                        }
                                        else if (credite.getCredite() == ""){
                                            if (listaCredite.size() == 0){
                                                std::cout << "\n" << "Eroare" << "\n";
                                            }
                                            else break;
                                        }
                                    }
                                }
                    }
                    if (ok == 0){
                        okBD = 0;
                        std::cout << "Crearea bazei de date a fost anulata!\n";
                        break;
                    }
                    /*if (ok == 0) {
                        okBD = 0;
                        listaProfesori.clear();
                        facultate = Facultate();
                        break;
                    }*/

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
                        std::cout << "- Curs predat: " << listaCursuri[i].getNume() << "\n";
                        std::cout << "- Credite: " << listaCredite[i].getCredite() << "\n\n";
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
                    else if (btn5 < 0 || btn5 >= listaStudenti.size()) std::cout << "Optiune invalida!";
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
